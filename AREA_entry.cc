#include "AREA_entry.h"
#include "endian.h"
#include <fstream>

//copy object to array
AREA_entry::AREA_entry(const AREA_entry &o){
	for(unsigned short i=0; i<0x30; ++i) entry.data[i]=o.entry.data[i];
}
AREA_entry::AREA_entry(const char *obj){
	for(unsigned short i=0; i<0x30; ++i) entry.data[i]=obj[i];
}
//these assignment operators are defined to avoid infinite recursion
AREA_entry& AREA_entry::operator=(const char *obj){
	for(unsigned short i=0; i<0x30; ++i) entry.data[i]=obj[i];
	return *this;
}
AREA_entry& AREA_entry::operator=(const AREA_entry &o){
	for(unsigned short i=0; i<0x30; ++i) entry.data[i]=o.entry.data[i];
	return *this;
}
//flip endian
void AREA_entry::flipVals(){
	for(unsigned short i=0; i<3; i++){
		flip(entry.vals.pos[i]);
		flip(entry.vals.rot[i]);
		flip(entry.vals.scale[i]);
	}
	flip(entry.vals.setting1);
	flip(entry.vals.setting2);
	flip(entry.vals.padding);
}
//for ease of file editing
std::ofstream& operator<<(std::ofstream &file, const AREA_entry &o){
	file.write((char *)o.entry.data, 0x30);
	return file;
}
std::ifstream& operator>>(std::ifstream &file, AREA_entry &o){
	static char temp[0x30];
	file.read(temp, 0x30);
	o=temp;
	return file;
}
