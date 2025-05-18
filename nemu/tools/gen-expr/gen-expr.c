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

/*
  1.未实现除法的功能因为除数一直搞成了0；
  2.depth不能开很高，现在用的10；
  3。无符号数好像不能解决负数的问题，负数会转位超大的数
  4.空格和单括号有矛盾。
*/




#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

// this should be enough
static char buf[65536] = {};
//现在buf的空位置在哪里
static int pos = 0;

static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";


//写入字符
void gen(char c){
  buf[pos++] = c;
  buf[pos] = '\0';
}

//写入字符串
void gen_str(const char* str){
  uint32_t len = strlen(str);
  //内存复制操作
  //1，目标内存区域的起始地址
  //2，被复制的内容的起始位置
  //3，复制的字节数量
  memcpy(buf+pos,str,len);
  pos+=len;
  if(buf[pos]!='\0'){
    buf[pos] = '\0'; 
  }
  
}

//随机选择你的武器
uint32_t choose(uint32_t n){
  return rand() % n;
}

//生成的数字
void gen_num(){

  uint32_t n = 1 + rand()%10;
  char num_str[10]; 
  //sprintf 是一个通用的格式化字符串函数
  sprintf(num_str, "%u", n);  // 关键：将整数转为字符串，最后会加一个'\0’;
  gen_str(num_str);
}

//生成随机符号
void gen_rand_op(){
  const char ops[4] = {'+','-','*','/'};
  char op = ops[rand() % 4];
  gen(op);
}


//生成随机值
static void gen_rand_expr(int depth) {
  if(depth >= 10){
    gen_num();
    return;
  }
  switch (choose(3)) {
    case 0: 
            gen_num(); 
            break;
    case 1:
          if(buf[pos-1]!=' '){
            gen(' ');
            gen_rand_expr(depth + 1);
            break;
          }
    case 2: 
      //整个判断防止生成好多括号
       if(pos==0||buf[pos-1] != '('){
            gen('('); 
            gen_rand_expr(depth + 1); 
            gen(')');
            break; 
          }   
    default: 
            gen_rand_expr(depth + 1); 
            gen_rand_op(); 
            gen_rand_expr(depth + 1); 
            break;
  }
}

//主体开始了
int main(int argc, char *argv[]) {
  //当前时间作为种子
  int seed = time(0);
  //设置随机数种子
  srand(seed) ;

  int loop = 1;
  //读取循环次数
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }

  //循环生成随机表达式
  int i;
  for (i = 0; i < loop; i ++) {

    pos = 0;                 // 重置缓冲区位置
    memset(buf, 0, sizeof(buf));  // 清空缓冲区（可选，但更安全）

    gen_rand_expr(0);
    //把之前生成的随机表达式嵌入到一个完整的 C 语言程序中
    //buf也就是生成的表达式放入code_format中的占位符然后一起放入code_buf中
    sprintf(code_buf, code_format, buf);
    
    //以写模式打开这个文件
    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);

    //将code_buf的内容写入上面打开的文件中
    fputs(code_buf, fp);
    fclose(fp);

    //system的作用是允许 C 程序与操作系统 shell 交互，执行外部命令。
    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue;

    //执行 command 指定的 shell 命令，并返回一个关联的文件流（FILE*），用于读取命令的输出或向命令输入数据。
    //r是读取，w是输入
    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}

