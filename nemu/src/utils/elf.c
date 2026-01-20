#include "debug.h"
#include <common.h>
#include <elf.h>
#include <stdio.h>

//common.h中声明了,这里定义
Elf32_Sym *symtab = NULL;
char *strtab = NULL;
int sym_num = 0;


//ftrace
void init_elf(const char *elf_file) {

    //打开elf文件
    FILE *fp = fopen(elf_file, "r");
    Assert(fp, "Can not open '%s'", elf_file);
    Log("The %s Elf is be open to ", elf_file);

    //读取ELF的头
    Elf32_Ehdr ehdr;
    if(fread(&ehdr,sizeof(Elf32_Ehdr),1,fp) != 1){
        Assert(0,"ehdr读取失败");
    }

    //读取节区头表
    Elf32_Shdr shdr[ehdr.e_shnum];
    fseek(fp,ehdr.e_shoff,SEEK_SET);
    if(fread(&shdr,sizeof(Elf32_Shdr),ehdr.e_shnum,fp) != ehdr.e_shnum){
        Assert(0,"shdr读取失败");
    }

	//读取.shstrtab内容
	Elf32_Shdr shstrtab_shdr = shdr[ehdr.e_shstrndx];
	char *shstrtab = malloc(shstrtab_shdr.sh_size);
	fseek(fp, shstrtab_shdr.sh_offset, SEEK_SET);
	if(fread(shstrtab, 1, shstrtab_shdr.sh_size, fp) != shstrtab_shdr.sh_size ){
		Assert(0, "shstrtab读取失败");
	}
	
	
	//根据名字找到找到符号表和字符串表
    Elf32_Shdr my_symtab = {0}, my_strtab = {0};
    for(int i=0; i<ehdr.e_shnum; i++){
		//直接不看类型只看名字
        if(strcmp(shstrtab + shdr[i].sh_name,".symtab") == 0 ) my_symtab = shdr[i];
        if(strcmp(shstrtab + shdr[i].sh_name,".strtab") == 0 ) my_strtab = shdr[i];
    }

    //符号表中的符号数量
    sym_num = my_symtab.sh_size / my_symtab.sh_entsize;

    symtab = malloc(my_symtab.sh_size);
    fseek(fp,my_symtab.sh_offset,SEEK_SET);
    if(fread(symtab,my_symtab.sh_size,1,fp)!= 1){
        Assert(0 , "symtab读取失败");
    }
	
    //字符串表
    strtab = malloc(my_strtab.sh_size);
    fseek(fp,my_strtab.sh_offset,SEEK_SET);
    if(fread(strtab,my_strtab.sh_size,1,fp) != 1){
        Assert(0 , "strtab读取失败");
    }
}
