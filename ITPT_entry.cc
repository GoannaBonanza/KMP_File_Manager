#include "ITPT_entry.h"
#include "endian.h"
#include <fstream>
ITPT_entry::ITPT_entry(const ITPT_entry &o){
	for(unsigned short i=0; i<0x14; ++i) entry.data[i]=o.entry.data[i];
}
ITPT_entry::ITPT_entry(const char *obj){
	for(unsigned short i=0; i<0x14; ++i) entry.data[i]=obj[i];
}
//these assignment operators are defined to avoid infinite recursion
ITPT_entry& ITPT_entry::operator=(const char *obj){
	for(unsigned short i=0; i<0x14; ++i) entry.data[i]=obj[i];
	return *this;
}
ITPT_entry& ITPT_entry::operator=(const ITPT_entry &o){
	for(unsigned short i=0; i<0x14; ++i) entry.data[i]=o.entry.data[i];
	return *this;
}
//flip endian
void ITPT_entry::flipVals(){
	flip(entry.vals.bound);
	flip(entry.vals.set1);
	flip(entry.vals.set2);
	for(unsigned short i=0; i<3; i++){
		flip(entry.vals.pos[i]);
	}
}
//for ease of file editing
std::ofstream& operator<<(std::ofstream &file, const ITPT_entry &o){
	file.write((char *)o.entry.data, 0x14);
	return file;
}
std::ifstream& operator>>(std::ifstream &file, ITPT_entry &o){
	static char temp[0x14];
	file.read(temp, 0x14);
	o=temp;
	return file;
}
