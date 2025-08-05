#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

void num_str(int num , char *str);


int printf(const char *fmt, ...) {
	//声明一个可变参数访问指针/对象（通常是内部游标）。
  va_list ap;
	//初始化 ap，让它指向可变参数序列的第一个参数。
  va_start(ap,fmt);
  while(*fmt != '\0'){
		if(*fmt == '%'){
			putstr("0");
			switch(*++fmt){
				case 's':{
					char* str = va_arg(ap,char*);
					putstr(str);
					break;
				}
				case 'd':{
					int num = va_arg(ap,int);
					char str[13];
					num_str(num,str);
					putstr(str);
					break;
				}
				default : putch(*fmt);
			}
			fmt++;
		}else{
			putch(*fmt++);
		}	
  }
  va_end(ap);
  return 0;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap,fmt);
  int count = 0; //已经写入的字符串

  while(*fmt != '\0'){
		if(*fmt == '%'){
			switch(*++fmt){
				case 'd':{
					//取出
					int num = va_arg(ap,int);
					char str[13];
					int i = 0;
					num_str(num,str);
					//写入
					while(str[i]!='\0') out[count++] = str[i++];
					break;
				}
				case 's':{
					//取出
					char* str = va_arg(ap,char*);
					//写入
					while(*str!='\0'){
						out[count++] = *str++;
					}
					break;
				}
			}
			fmt++;
		}else{
			out[count++] = *fmt++;
		}
  }
  //确保字符串
  out[count] = '\0';
  va_end(ap);
  return count;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap,fmt);
  int count = 0; //已经写入的字符串
  int total_len = 0;
  while(*fmt != '\0'){
		if(*fmt == '%'){
			switch(*++fmt){
				case 'd':{
					//取出
					int num = va_arg(ap,int);
					char str[13];
					int i = 0;
					num_str(num,str);
					//写入
					while(str[i]!='\0'){
						if(out != NULL && count < n-1 && n!=0){
							out[count++] = str[i++];
							total_len++;
						}else{
							total_len++;
							i++;
						}
					} 
					break;
				}
				case 's':{
					//取出
					char* str = va_arg(ap,char*);
					//写入
					while(*str!='\0'){
						if(out != NULL && count < n-1 && n!=0){
							out[count++] = *str++;
							total_len++;
						}else{
							total_len++;
							str++;
						}
					}
					break;
				}
			}
			fmt++;
		}else{
			if(count < n-1 && out!=NULL && n!=0){
				out[count++] = *fmt++;
				total_len++;
			}else{
				total_len++;
				fmt++;
			}
		}
  }
  //确保字符串
	if(n!=0 && out!=NULL)
  	out[count] = '\0';
  va_end(ap);
  return total_len;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}


void num_str(int num , char *str){
	unsigned int u;
	char *p = str;
	char *start = NULL;
	//处理 0；
	if(num == 0){
		*p++ = '0';
		*p = '\0';
		return;
	}
	//处理负数
	if(num < 0){
		*p++ = '-';
		//用 (unsigned int)(-(long)num) 处理负数绝对值，避免 INT_MIN 溢出问题
		u = (unsigned int)(-(long)num);
	}else{
		u = (unsigned int)num;
	}
	//因为负数的存在考虑起始端
	start = p;

	while(u > 0){
		*p++ = (u % 10) + '0';
		u/=10;
	}
	//保证是字符串
	*p = '\0';
	//反转字符串
	char *end = p-1;
	//只要 start 指针还在 end 指针的左边，就继续交换两端的字符。
	while(start < end){
		char tem = *start;
		*start++ = *end;
		*end-- = tem;
	}
}

#endif
