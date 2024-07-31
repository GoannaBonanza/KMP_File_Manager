#ifndef ENDIAN_H_INCLUDED
#define ENDIAN_H_INCLUDED
union Endian{
	unsigned int i;
	float f;
	unsigned short us[2];
	short s[2];
	struct{
		unsigned char d,c,b,a;
	} bytes;
};
extern Endian endian;
extern void swap();
extern float flip(float &);
extern unsigned int flip(unsigned int &);
extern unsigned short flip(unsigned short &);
extern short flip(short &);
#endif
