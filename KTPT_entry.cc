#include "KTPT_entry.h"
#include "endian.h"
#include <fstream>
KTPT_entry::KTPT_entry(const KTPT_entry &o){
	for(unsigned short i=0; i<0x1c; ++i) entry.data[i]=o.entry.data[i];
}
KTPT_entry::KTPT_entry(const char *obj){
	for(unsigned short i=0; i<0x1c; ++i) entry.data[i]=obj[i];
}
//these assignment operators are defined to avoid infinite recursion
KTPT_entry& KTPT_entry::operator=(const char *obj){
	for(unsigned short i=0; i<0x1c; ++i) entry.data[i]=obj[i];
	return *this;
}
KTPT_entry& KTPT_entry::operator=(const KTPT_entry &o){
	for(unsigned short i=0; i<0x1c; ++i) entry.data[i]=o.entry.data[i];
	return *this;
}
//flip endian
void KTPT_entry::flipVals(){
	flip(entry.vals.index);
	flip(entry.vals.padding);
	for(unsigned short i=0; i<3; i++){
		flip(entry.vals.pos[i]);
		flip(entry.vals.rot[i]);
	}
}
//for ease of file editing
std::ofstream& operator<<(std::ofstream &file, const KTPT_entry &o){
	file.write((char *)o.entry.data, 0x1c);
	return file;
}
std::ifstream& operator>>(std::ifstream &file, KTPT_entry &o){
	static char temp[0x1c];
	file.read(temp, 0x1c);
	o=temp;
	return file;
}
