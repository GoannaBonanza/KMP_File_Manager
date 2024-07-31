#include "STGI_entry.h"
#include "endian.h"
#include <fstream>
STGI_entry::STGI_entry(const STGI_entry &o){
	for(unsigned short i=0; i<0xc; ++i) entry.data[i]=o.entry.data[i];
}
STGI_entry::STGI_entry(const char *obj){
	for(unsigned short i=0; i<0xc; ++i) entry.data[i]=obj[i];
}
//these assignment operators are defined to avoid infinite recursion
STGI_entry& STGI_entry::operator=(const char *obj){
	for(unsigned short i=0; i<0xc; ++i) entry.data[i]=obj[i];
	return *this;
}
STGI_entry& STGI_entry::operator=(const STGI_entry &o){
	for(unsigned short i=0; i<0xc; ++i) entry.data[i]=o.entry.data[i];
	return *this;
}
//flip endian
void STGI_entry::flipVals(){
	flip(entry.vals.flare.color);
	flip(entry.vals.unknown);
}
//for ease of file editing
std::ofstream& operator<<(std::ofstream &file, const STGI_entry &o){
	file.write((char *)o.entry.data, 0xc);
	return file;
}
std::ifstream& operator>>(std::ifstream &file, STGI_entry &o){
	static char temp[0xc];
	file.read(temp, 0xc);
	o=temp;
	return file;
}
