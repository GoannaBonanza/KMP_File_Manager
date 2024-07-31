#include "endian.h"
Endian endian;
void swap(){
	//swap a and d
	unsigned char t=endian.bytes.a;
	endian.bytes.a=endian.bytes.d;
	endian.bytes.d=t;
	//swap b and c
	t=endian.bytes.b;
	endian.bytes.b=endian.bytes.c;
	endian.bytes.c=t;
}
float flip(float &f){
	endian.f=f;
	swap();
	f=endian.f;
	return endian.f;
}
unsigned int flip(unsigned int &i){
	endian.i=i;
	swap();
	i=endian.i;
	return endian.i;
}
unsigned short flip(unsigned short &s){
	endian.us[0]=s;
	swap();
	s=endian.us[1];
	return endian.us[1];
}
short flip(short &s){
	endian.s[0]=s;
	swap();
	s=endian.s[1];
	return endian.s[1];
}
