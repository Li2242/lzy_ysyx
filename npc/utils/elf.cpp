#include "common.h"
#include <elf.h>

FILE *elf_fp = NULL;
Elf32_Sym *symtab = NULL;
char *strtab = NULL;
int sym_num = 0;

//用于空格
int count = 0;
//ftrace初始化
void init_elf(){
    //打开文件
    FILE *fp = fopen(elf_file, "r");
		if(fp==NULL){
			red_printf("Can not open '%s'\n", elf_file);
			assert(0);
		}

    green_printf("The %s Elf is be open \n", elf_file);
    //先整header
    Elf32_Ehdr ehdr;
    if(fread(&ehdr,sizeof(ehdr),1,fp) != 1){
      red_printf("Can not open '%s'\n", elf_file);
			assert(0);
    }

    //从header中找到偏移量找节区
    Elf32_Shdr shdr[ehdr.e_shnum];
    fseek(fp,ehdr.e_shoff,SEEK_SET);
    if(fread(&shdr,sizeof(shdr),1,fp)!=1){
      red_printf("Can not open '%s'\n", elf_file);
			assert(0);
    }
    //找到节区后从节区中找到符号表和字符串表
    Elf32_Shdr u_symtab,u_strtab;
    for(int i=0; i<ehdr.e_shnum; i++){
        if(shdr[i].sh_type == SHT_SYMTAB) u_symtab = shdr[i];
        if(shdr[i].sh_type && i != ehdr.e_shstrndx) u_strtab = shdr[i];
    }
    //字符串表，符号表，符号表的值现在都是<commond.h>里面的全局变量了
    //符号表
    sym_num = u_symtab.sh_size/u_symtab.sh_entsize;
    symtab = (Elf32_Sym*)malloc(u_symtab.sh_size);
    fseek(fp,u_symtab.sh_offset,SEEK_SET);
    if(fread(symtab,u_symtab.sh_size,1,fp)!= 1){
      red_printf("Can not open '%s'\n", elf_file);
			assert(0);
    }
    //字符串表
    strtab = (char*)malloc(u_strtab.sh_size);
    fseek(fp,u_strtab.sh_offset,SEEK_SET);
    if(fread(strtab,u_strtab.sh_size,1,fp) != 1){
      red_printf("Can not open '%s'\n", elf_file);
			assert(0);
    }
}

#define BITMASK(bits) ((1ull << (bits)) - 1)
//位抽取
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1)) // similar to x[hi:lo] in verilog
//符号扩展
#define SEXT(x, len) ({ struct { int64_t n : len; } __x = { .n = x }; (uint64_t)__x.n; })


//ftrace逻辑
void ftrace(char* inst){
	     //jalr
				uint32_t inst_t = pmem_read(cpu_pc,4);
				uint32_t opcode = inst_t & 0x7f;
				uint32_t funct3 = (inst_t >> 12) & 0x7;
	 			uint32_t rd  = (inst_t >> 7) & 0x1f;    // 提取 rd 寄存器
				uint32_t rs1 = (inst_t >> 15) & 0x1f;
				uint32_t rs2 = (inst_t >> 20) & 0x1f;
				uint32_t imm_I = SEXT(BITS(inst_t, 31, 20), 12);  // sign-extend
				uint32_t imm_J = SEXT( (BITS(inst_t,31,31)<<20) | (BITS(inst_t,19,12)<<12) \
				| (BITS(inst_t,20,20)<<11) |  (BITS(inst_t,30,21)<<1),21);


        bool in = 0;
				//ret
        if(inst_t == 0x00008067){
            in = 1;

        }
        //jal
        if(opcode == 111 ){
            in = 1;
            int jal_target = imm_J + cpu_pc;
            for(int i =0;i<sym_num;i++){
                if((symtab[i].st_value <= jal_target && jal_target < symtab[i].st_value + symtab[i].st_size) &&\
								  ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC)
									{
                    printf("0x%x: %*scall [%s@0x%x]\n",cpu_pc,count++,"",strtab+symtab[i].st_name,jal_target);
                    return;
                }
            }
        }

        //jalr(未使用Itrace)
        if(opcode == 103 && funct3==0){
            in = 1;
						//ret
						if(rd == 0 && rs1 == 1 && imm_I == 0){
							uint32_t ret_target = imm_I + reg_str2val_num(rs1);
							for(int i =0;i<sym_num;i++){
									in = 1;
									if(symtab[i].st_value <= ret_target && ret_target < symtab[i].st_value + symtab[i].st_size ){
											printf("0x%x: %*sret[%s]\n",cpu_pc,--count,"",strtab+symtab[i].st_name);
											return;
									}
							}
						}
						//jalr
						uint32_t jalr_target = imm_I + reg_str2val_num(rs1);
            for(int i =0;i<sym_num;i++){
                if(symtab[i].st_value <= jalr_target && jalr_target < symtab[i].st_value + symtab[i].st_size &&\
									 ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC){
                    printf("0x%x: %*scall [%s@0x%x]\n",cpu_pc,count++,"",strtab+symtab[i].st_name,jalr_target);
                    return;
                }
            }
        }

        if(in==1){
            printf("???\n");
        }
				return;
}
