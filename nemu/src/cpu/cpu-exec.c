/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include "/home/lzy14/ysyx/ysyx-workbench/nemu/src/monitor/sdb/sdb.h"

//是否显示指令
/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;
int ring_buf_count = 0;
char ring_buf[8][100];

void device_update();
//ring buf
void ring_buf_fun();

//ftrace
void ftrace();
//用于空格
int count = 0;

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
    //如果走的步数少于MAX_INST_TO_PRINT就打印步骤
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));

  //在Kconfig中可以控制这个宏是否生成
  //扫描监视点
  #ifdef CONFIG_WATCHPOINT
    bool success = false;
    scan_watchpoints(&success);
  #endif
}

//该函数用于执行一条指令
// Decode类型的结构体指针s, 这个结构体用于存放在执行一条指令过程中所需的信息, 包括指令的PC, 下一条指令的PC等
static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;       //s->pc就是当前指令的PC
  s->snpc = pc;     //s->snpc则是下一条指令的PC，此时还没变
  //主要是pc的值
  isa_exec_once(s); //它会随着取指的过程修改s->snpc的值, 使得从isa_exec_once()返回后s->snpc正好为下一条指令的PC.
  cpu.pc = s->dnpc; //通过s->dnpc来更新PC


  //日志跟踪
#ifdef CONFIG_ITRACE
    //先存储执行过程中的二进制
  char *p = s->logbuf;
  //snprintf的返回值是"本应该"写入的总字符数
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst;

#ifdef CONFIG_ISA_x86
  for (i = 0; i < ilen; i ++) {
#else
  for (i = ilen - 1; i >= 0; i --) {
#endif
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  //架构决定的
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);

  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;

  memset(p, ' ', space_len);
  p += space_len;
  //写入了反汇编的内容
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst, ilen);
#endif
}

//该函数用于执行指定数量的指令。
static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
#ifdef CONFIG_ITRACE
    //ring_buf
    ring_buf_fun(s.logbuf);
    //在没有-e选项时不启动
    if(ftrace_switch){
        #ifdef CONFIG_FTRACE
            //ftrace
            ftrace(s.logbuf);
        #endif
    }
#endif

    g_nr_guest_inst ++;  //对一个用于记录客户指令的计数器加1
    trace_and_difftest(&s, cpu.pc);

    //在这里添加出错指令再好不过了,不对不对，这里正常结束也会显示，我想定义一个全局变量，然后在最后状态里面输出
    //算了状态提前判断一下吧，就在这个文件里写一个ring_buf吧
    if (nemu_state.state != NEMU_RUNNING){
        //判断是否正常退出
        int good = (nemu_state.state == NEMU_END && nemu_state.halt_ret == 0) ||
                (nemu_state.state == NEMU_QUIT);
        if(good == 0){
            //log_write 写入文件的函数
            log_write("下面是临近出错时的8条指令\n");
            for(int j=0; j<8; j++){
                if(ring_buf_count<8){
                    log_write("%s\n", ring_buf[ring_buf_count++]);
                }else{
                    ring_buf_count = 0;
                    log_write("%s\n", ring_buf[ring_buf_count++]);
                }
            }
        }
        break;
    }
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

//该函数用于输出统计信息，包括主机时间花费、执行的客户指令总数和模拟频率。
static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}
//该函数用于在断言失败时输出寄存器信息和统计信息。
void assert_fail_msg() {
  isa_reg_display();
  statistic();
}

/* Simulate how the CPU works. */
//该函数是 CPU 执行的主函数，用于控制 CPU 的执行流程。
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT: case NEMU_QUIT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // fall through
    case NEMU_QUIT: statistic();
  }
}

//ringbuf
void ring_buf_fun(char* inst){
    //加的环形缓冲区
    if(ring_buf_count<8){
        strncpy(ring_buf[ring_buf_count], inst, 100 );
        ring_buf[ring_buf_count++][99] = '\0';
    }else{
        ring_buf_count = 0;
        strncpy(ring_buf[ring_buf_count], inst, 100 );
        ring_buf[ring_buf_count++][99] = '\0';
    }
}


//ftrace
void ftrace(char* inst){
    //找出jal和jalr
        // char* fun = s.logbuf;
        // fun+=24;
        char fun1[10];
        unsigned int pc, target;
        // char target[10];
        sscanf(inst,"%x: %*s %*s %*s %*s %s\t%x",&pc ,fun1, &target);
        // char* temp = strtok(fun,"\t");
        //终于找出来了，接下来要进行处理了
        bool find = 0;
        bool in = 0;
        //jal
        if(strncmp(fun1,"jal",4) ==0){
            in = 1;
            int jal_target = pc + target;
            for(int i =0;i<sym_num;i++){
                if((symtab[i].st_value <= jal_target && jal_target < symtab[i].st_value + symtab[i].st_size) &&   ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC){
                    printf("0x%x: %*scall [%s@0x%x]\n",pc,++count,"",strtab+symtab[i].st_name,jal_target);
                    find = 1;
                    break;
                }
            }
        }
        //jalr
        if(strncmp(fun1,"jalr",5)==0){
            in = 1;
            char str_t[10];
            sprintf(str_t,"%x",target);
            bool success_flag = false;
            uint32_t jalr_target = isa_reg_str2val(str_t, &success_flag);
            if(!success_flag){
                printf("寄存器取值失败!\n");
            }
            for(int i =0;i<sym_num;i++){
                in = 1;
                if(symtab[i].st_value <= jalr_target && jalr_target < symtab[i].st_value + symtab[i].st_size && ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC){
                    printf("0x%x: %*scall [%s@0x%x]\n",pc,++count,"",strtab+symtab[i].st_name,jalr_target);
                    find = 1;
                    break;
                }
            }
        }
        //ret
        if(strncmp(fun1,"ret",3)==0){
            in = 1;
            for(int i =0;i<sym_num;i++){
                in = 1;
                if(symtab[i].st_value <= pc && pc < symtab[i].st_value + symtab[i].st_size ){
                    printf("0x%x: %*sret[%s]\n",pc,--count,"",strtab+symtab[i].st_name);
                    find = 1;
                    break;
                }
            }
        }
        if(find==0 && in==1){
            printf("???\n");
        }

}
