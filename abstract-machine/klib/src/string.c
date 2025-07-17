#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
	size_t count = 0;
	while(s[count++]!='\0');
	return count-1;
}

char *strcpy(char *dst, const char *src) {
  size_t i = 0;
  while(src[i]!='\0'){
	dst[i] = src[i];
	i++;
  }
  dst[i] = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
	size_t i = 0;
	while(i < n && src[i] != '\0'){
		dst[i] = src[i];  
		i++;
	}
	//如果没有源码不够
	if(i < n){
		while(i < n){
			dst[i] = '\0';
			i++;
		}
	}
  return dst;
}

//追加
char *strcat(char *dst, const char *src) {
  size_t start = strlen(dst);
	size_t i = 0;
	while(src[i] != '\0'){
		dst[start + i] = src[i];
		i++;
	}
	dst[start+i] = '\0';
	return dst;
}

int strcmp(const char *s1, const char *s2) {
	size_t i = 0;
		while(s1[i]!='\0' && s2[i]!='\0'){
			if(s1[i] != s2[i]) return (unsigned char)s1[i] - (unsigned char)s2[i];
			i++;
		}
		//如果长度不同，且前面相同
	return (unsigned char)s1[i]-(unsigned char)s2[i];
}

int strncmp(const char *s1, const char *s2, size_t n) {
  size_t i = 0;
	while(s1[i]!=0 && s2[i] !=0 && i<n){
		if(s1[i] == s2[i]){
			i++;
			continue;
		}else{
			return s1[i] - s2[i];
		}
	}
	if(n==i){
		return 0;
	}else{
		return s1[i]-s2[i];
	}
}

void *memset(void *s, int c, size_t n) {
	unsigned char a = (unsigned char)c;
	unsigned char *p = s;
	for(size_t i =0 ;i<n;i++){
		p[i] = a;
	}
	return s;
}


void *memmove(void *dst, const void *src, size_t n) {
	const unsigned char *a = src;
	unsigned char *p = dst;
	if(a+n <= p || p+n <= a){
		for(size_t i =0; i<n; i++) p[i] = a[i];
	}else{
		for(size_t i =n; i>0; i++) p[i-1] = a[i-1];
	}
	return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  	const unsigned char *a = in;
	unsigned char *p = out;
	for(size_t i =0;i<n;i++){
		p[i] = a[i];
	}
	return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *t1 = s1;
  const unsigned char *t2 = s2;
  size_t i = 0;
  while(i < n ){
	if(t1[i]!=t2[i]) return t1[i] - t2[i];
	i++;
  }
  return 0;
}

#endif
