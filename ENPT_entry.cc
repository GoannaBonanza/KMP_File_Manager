#include "ENPT_entry.h"
#include "endian.h"
#include <fstream>
ENPT_entry::ENPT_entry(const ENPT_entry &o){
	for(unsigned short i=0; i<0x14; ++i) entry.data[i]=o.entry.data[i];
}
ENPT_entry::ENPT_entry(const char *obj){
	for(unsigned short i=0; i<0x14; ++i) entry.data[i]=obj[i];
}
//these assignment operators are defined to avoid infinite recursion
ENPT_entry& ENPT_entry::operator=(const char *obj){
	for(unsigned short i=0; i<0x14; ++i) entry.data[i]=obj[i];
	return *this;
}
ENPT_entry& ENPT_entry::operator=(const ENPT_entry &o){
	for(unsigned short i=0; i<0x14; ++i) entry.data[i]=o.entry.data[i];
	return *this;
}
//flip endian
void ENPT_entry::flipVals(){
	flip(entry.vals.bound);
	flip(entry.vals.set1);
	//individual bytes don't need to be flipped
	for(unsigned short i=0; i<3; i++){
		flip(entry.vals.pos[i]);
	}
}
//for ease of file editing
std::ofstream& operator<<(std::ofstream &file, const ENPT_entry &o){
	file.write((char *)o.entry.data, 0x14);
	return file;
}
std::ifstream& operator>>(std::ifstream &file, ENPT_entry &o){
	static char temp[0x14];
	file.read(temp, 0x14);
	o=temp;
	return file;
}
