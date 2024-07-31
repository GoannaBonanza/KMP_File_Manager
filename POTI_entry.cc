#include "POTI_entry.h"
#include "endian.h"
#include <vector>
#include <fstream>

//route point functions
//copy object to array
route_pt::route_pt(const route_pt &o){
	for(unsigned short i=0; i<0x10; ++i) entry.data[i]=o.entry.data[i];
}
route_pt::route_pt(const char *obj){
	for(unsigned short i=0; i<0x10; ++i) entry.data[i]=obj[i];
}
//these assignment operators are defined to avoid infinite recursion
route_pt& route_pt::operator=(const char *obj){
	for(unsigned short i=0; i<0x10; ++i) entry.data[i]=obj[i];
	return *this;
}
route_pt& route_pt::operator=(const route_pt &o){
	for(unsigned short i=0; i<0x10; ++i) entry.data[i]=o.entry.data[i];
	return *this;
}
//flip endian
void route_pt::flipVals(){
	flip(entry.vals.speed);
	flip(entry.vals.setting);
	for(unsigned short i=0; i<3; i++) flip(entry.vals.pos[i]);
}
//for ease of file editing
std::ofstream& operator<<(std::ofstream &file, const route_pt &o){
	file.write((char *)o.entry.data, 0x10);
	return file;
}
std::ifstream& operator>>(std::ifstream &file, route_pt &o){
	static char temp[0x10];
	file.read(temp, 0x10);
	o=temp;
	return file;
}

//POTI entry functions
//copy object to array
POTI_entry::POTI_entry(const POTI_entry &o){
	for(unsigned short i=0; i<0x4; ++i) entry.data[i]=o.entry.data[i];
	route=o.route;
}
POTI_entry::POTI_entry(const char *obj){
	for(unsigned short i=0; i<0x4; ++i) entry.data[i]=obj[i];
	//clear route, filling it up is done separately
	route.clear();
}
//these assignment operators are defined to avoid infinite recursion
POTI_entry& POTI_entry::operator=(const char *obj){
	for(unsigned short i=0; i<0x4; ++i) entry.data[i]=obj[i];
	route.clear();
	return *this;
}
POTI_entry& POTI_entry::operator=(const POTI_entry &o){
	for(unsigned short i=0; i<0x4; ++i) entry.data[i]=o.entry.data[i];
	route=o.route;
	return *this;
}
//flip endian
void POTI_entry::flipVals(){
	flip(entry.vals.count);
	//also flip every point
	for(auto &p:route) p.flipVals();
}
//for ease of file editing
std::ofstream& operator<<(std::ofstream &file, const POTI_entry &o){
	file.write((char *)o.entry.data, 0x4);
	//flip count to avoid segmentation fault
	unsigned short act_count=o.entry.vals.count;
	flip(act_count);
	//now write everything
	//entire route has already been flipped by section code
	for(unsigned short i=0; i<act_count; i++) file << o.route[i];
	return file;
}
std::ifstream& operator>>(std::ifstream &file, POTI_entry &o){
	static char temp[0x4];
	file.read(temp, 0x4);
	o=temp;
	//flip count to get proper size
	unsigned short act_count=o.entry.vals.count;
	flip(act_count);
	//clear existing route and reserve and resize
	o.route.clear();
	o.route.reserve(act_count);
	//now use act_count
	for(unsigned short i=0; i<act_count; i++){
		route_pt p;
		file >> p;
		o.route.push_back(p);
	}
	return file;
}
