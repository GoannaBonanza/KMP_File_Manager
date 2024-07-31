#include "XXPH_entry.h"
#include "endian.h"
#include <fstream>
XXPH_entry::XXPH_entry(const XXPH_entry &o){
	for(unsigned short i=0; i<0x10; ++i) entry.data[i]=o.entry.data[i];
}
XXPH_entry::XXPH_entry(const char *obj){
	for(unsigned short i=0; i<0x10; ++i) entry.data[i]=obj[i];
}
//these assignment operators are defined to avoid infinite recursion
XXPH_entry& XXPH_entry::operator=(const char *obj){
	for(unsigned short i=0; i<0x10; ++i) entry.data[i]=obj[i];
	return *this;
}
XXPH_entry& XXPH_entry::operator=(const XXPH_entry &o){
	for(unsigned short i=0; i<0x10; ++i) entry.data[i]=o.entry.data[i];
	return *this;
}
//flip endian
void XXPH_entry::flipVals(){
	flip(entry.vals.padding);
	//individual bytes don't need to be flipped
}
//for ease of file editing
std::ofstream& operator<<(std::ofstream &file, const XXPH_entry &o){
	file.write((char *)o.entry.data, 0x10);
	return file;
}
std::ifstream& operator>>(std::ifstream &file, XXPH_entry &o){
	static char temp[0x10];
	file.read(temp, 0x10);
	o=temp;
	return file;
}
