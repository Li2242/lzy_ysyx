#include <common.h>

FILE *elf_fp = NULL;
Elf32_Sym *symtab = NULL;
char *strtab = NULL;
int sym_num = 0;

//ftrace
void init_elf(const char *elf_file) {
    //打开文件
    FILE *fp = fopen(elf_file, "r");
    Assert(fp, "Can not open '%s'", elf_file);
    Log("The %s Elf is be open to ", elf_file);
    //先整header
    Elf32_Ehdr ehdr;
    if(fread(&ehdr,sizeof(ehdr),1,fp) != 1){
        Assert(0,"ehdr读取失败");
    }
    //从header中找到偏移量找节区
    Elf32_Shdr shdr[ehdr.e_shnum];
    fseek(fp,ehdr.e_shoff,SEEK_SET);
    if(fread(&shdr,sizeof(shdr),1,fp)!=1){
        Assert(0,"shdr读取失败");
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
    symtab = malloc(u_symtab.sh_size);
    fseek(fp,u_symtab.sh_offset,SEEK_SET);
    if(fread(symtab,u_symtab.sh_size,1,fp)!= 1){
        Assert(0,"symtab读取失败");
    }
    //字符串表
    strtab = malloc(u_strtab.sh_size);
    fseek(fp,u_strtab.sh_offset,SEEK_SET);
    if(fread(strtab,u_strtab.sh_size,1,fp) != 1){
        Assert(0,"strtab读取失败");
    }

    // //初始化过了，因该如何使用呢？ 这里是吧所有的函数跳出来打印一边
    // for(int i=0; i<sym_num; i++){
    //     if(ELF32_ST_TYPE(symtab[i].st_info) == STT_FUNC){
    //         char *name = strtab + symtab[i].st_name;
    //         printf("%d : %s\n",i,name);
    //     }
    // }
}
