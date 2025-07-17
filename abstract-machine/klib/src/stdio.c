#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

void num_str(int num , char *str){
	char temp[12];
	int negative = 0;
	int n =0;
	if(num == 0){
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	if(num < 0){
		str[0] = '-';
		negative = 1;
		num = -num;
	}

	while(num>0){
		temp[n++] = num%10 + '0';
		num/=10;
	}
	int t = negative ? 1 : 0;
	for(int j = n-1; j>=0; j--){
		str[t++] = temp[j];
	}
	//保证是字符串
	str[t] = '\0';
}

int printf(const char *fmt, ...) {
  va_list ap;
  va_start(ap,fmt);
  int i = 0;
  while(fmt[i] != '\0'){
	if(fmt[i] == '%'){
		i++;
		switch(fmt[i]){
			case 's':{
				char* str = va_arg(ap,char*);
				putstr(str);
				i++;
				break;
			}
			case 'd':{
				int num = va_arg(ap,int);
				char str[12] ;
				num_str(num,str);
				i++;
				putstr(str);
				break;
			}
		}
	}else{
		putch(fmt[i]);
		i++;
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
  int count = 0;
  int i = 0;
  while(fmt[i] != '\0'){
	if(fmt[i] == '%'){
		i++;
		switch(fmt[i]){
			case 'd':{
				//取出
				int num = va_arg(ap,int);
				char str[12];
				num_str(num,str);
				//写入
				int t = 0;
				while(str[t]!='\0'){
					out[count++] = str[t++];
				}
				i++;
				break;
			}
			case 's':{
				//取出
				char* str = va_arg(ap,char*);
				//写入
				int t = 0;
				while(str[t]!='\0'){
					out[count++] = str[t++];
				}
				i++;
				break;
			}
		}
	}else{
		out[count++] = fmt[i++];
	}
  }
  //确保字符串
  out[count] = '\0';
  va_end(ap);
  return count;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
