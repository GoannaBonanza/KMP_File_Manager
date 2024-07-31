#include "CAME_entry.h"
#include "endian.h"
#include <fstream>
CAME_entry::CAME_entry(const CAME_entry &o){
	for(unsigned short i=0; i<0x48; ++i) entry.data[i]=o.entry.data[i];
}
CAME_entry::CAME_entry(const char *obj){
	for(unsigned short i=0; i<0x48; ++i) entry.data[i]=obj[i];
}
//these assignment operators are defined to avoid infinite recursion
CAME_entry& CAME_entry::operator=(const char *obj){
	for(unsigned short i=0; i<0x48; ++i) entry.data[i]=obj[i];
	return *this;
}
CAME_entry& CAME_entry::operator=(const CAME_entry &o){
	for(unsigned short i=0; i<0x48; ++i) entry.data[i]=o.entry.data[i];
	return *this;
}
//flip endian
void CAME_entry::flipVals(){
	flip(entry.vals.velo_point);
	flip(entry.vals.velo_zoom);
	flip(entry.vals.velo_view);
	//individual bytes don't need to be flipped
	for(unsigned short i=0; i<3; i++){
		flip(entry.vals.pos[i]);
		flip(entry.vals.rot[i]);
		flip(entry.vals.start_vector[i]);
		flip(entry.vals.end_vector[i]);
	}
	flip(entry.vals.zoomstart);
	flip(entry.vals.zoomend);
	flip(entry.vals.time);
}
//for ease of file editing
std::ofstream& operator<<(std::ofstream &file, const CAME_entry &o){
	file.write((char *)o.entry.data, 0x48);
	return file;
}
std::ifstream& operator>>(std::ifstream &file, CAME_entry &o){
	static char temp[0x48];
	file.read(temp, 0x48);
	o=temp;
	return file;
}
