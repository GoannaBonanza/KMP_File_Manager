#include "CKPT_entry.h"
#include "endian.h"
#include <fstream>
CKPT_entry::CKPT_entry(const CKPT_entry &o){
	for(unsigned short i=0; i<0x14; ++i) entry.data[i]=o.entry.data[i];
}
CKPT_entry::CKPT_entry(const char *obj){
	for(unsigned short i=0; i<0x14; ++i) entry.data[i]=obj[i];
}
//these assignment operators are defined to avoid infinite recursion
CKPT_entry& CKPT_entry::operator=(const char *obj){
	for(unsigned short i=0; i<0x14; ++i) entry.data[i]=obj[i];
	return *this;
}
CKPT_entry& CKPT_entry::operator=(const CKPT_entry &o){
	for(unsigned short i=0; i<0x14; ++i) entry.data[i]=o.entry.data[i];
	return *this;
}
//flip endian
void CKPT_entry::flipVals(){
	//individual bytes don't need to be flipped
	for(unsigned short i=0; i<2; i++){
		flip(entry.vals.lpoint[i]);
		flip(entry.vals.rpoint[i]);
	}
}
//for ease of file editing
std::ofstream& operator<<(std::ofstream &file, const CKPT_entry &o){
	file.write((char *)o.entry.data, 0x14);
	return file;
}
std::ifstream& operator>>(std::ifstream &file, CKPT_entry &o){
	static char temp[0x14];
	file.read(temp, 0x14);
	o=temp;
	return file;
}
