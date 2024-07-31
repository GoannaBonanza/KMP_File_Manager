#include "XXPT_entry.h"
#include "endian.h"
#include <fstream>
XXPT_entry::XXPT_entry(const XXPT_entry &o){
	for(unsigned short i=0; i<0x1c; ++i) entry.data[i]=o.entry.data[i];
}
XXPT_entry::XXPT_entry(const char *obj){
	for(unsigned short i=0; i<0x1c; ++i) entry.data[i]=obj[i];
}
//these assignment operators are defined to avoid infinite recursion
XXPT_entry& XXPT_entry::operator=(const char *obj){
	for(unsigned short i=0; i<0x1c; ++i) entry.data[i]=obj[i];
	return *this;
}
XXPT_entry& XXPT_entry::operator=(const XXPT_entry &o){
	for(unsigned short i=0; i<0x1c; ++i) entry.data[i]=o.entry.data[i];
	return *this;
}
//flip endian
void XXPT_entry::flipVals(){
	flip(entry.vals.id);
	flip(entry.vals.setting);
	for(unsigned short i=0; i<3; i++){
		flip(entry.vals.pos[i]);
		flip(entry.vals.rot[i]);
	}
}
//for ease of file editing
std::ofstream& operator<<(std::ofstream &file, const XXPT_entry &o){
	file.write((char *)o.entry.data, 0x1c);
	return file;
}
std::ifstream& operator>>(std::ifstream &file, XXPT_entry &o){
	static char temp[0x1c];
	file.read(temp, 0x1c);
	o=temp;
	return file;
}
