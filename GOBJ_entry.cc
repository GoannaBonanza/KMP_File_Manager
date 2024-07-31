#include "GOBJ_entry.h"
#include "endian.h"
#include "display.h"
#include <fstream>
#include <iostream>
#include <map>
//helper to make object table
std::map<int, std::string> make_obj_table(const char* filename){
	std::ifstream file(filename);
	std::map<int, std::string> table;
	if(!file) return table;
	std::string temp;
	int tempid;
	for(unsigned short i=0; i<316; i++){
		//get id num
		std::getline(file, temp);
		tempid=std::stoi(temp, nullptr, 16);
		//get object name
		std::getline(file, temp);
		table.insert(std::pair<int, std::string>(tempid, temp));
	}
	return table;
}
//copy object to array
GOBJ_entry::GOBJ_entry(const GOBJ_entry &o){
	for(unsigned short i=0; i<0x3c; ++i) entry.data[i]=o.entry.data[i];
}
GOBJ_entry::GOBJ_entry(const char *obj){
	for(unsigned short i=0; i<0x3c; ++i) entry.data[i]=obj[i];
}
//these assignment operators are defined to avoid infinite recursion
GOBJ_entry& GOBJ_entry::operator=(const char *obj){
	for(unsigned short i=0; i<0x3c; ++i) entry.data[i]=obj[i];
	return *this;
}
GOBJ_entry& GOBJ_entry::operator=(const GOBJ_entry &o){
	for(unsigned short i=0; i<0x3c; ++i) entry.data[i]=o.entry.data[i];
	return *this;
}
//flip endian
void GOBJ_entry::flipVals(){
	flip(entry.vals.id);
	flip(entry.vals.padding);
	for(unsigned short i=0; i<3; i++){
		flip(entry.vals.pos[i]);
		flip(entry.vals.rot[i]);
		flip(entry.vals.scale[i]);
	}
	flip(entry.vals.route);
	for(unsigned short i=0; i<8; i++) flip(entry.vals.settings[i]);
	flip(entry.vals.presence);
}
void GOBJ_entry::display() const{
	static auto table=make_obj_table("obj.txt");
	std::cout << table[entry.vals.id] << "\nPosition: ";
	disp_vec(std::cout, entry.vals.pos, 3);
	std::cout << "\nRotation: ";
	disp_vec(std::cout, entry.vals.rot, 3);
	std::cout << "\nScale: ";
	disp_vec(std::cout, entry.vals.scale, 3);
	std::cout << "\nRoute: " << std::hex << entry.vals.route;
	std::cout << "\nSettings: " << std::hex;
	disp_vals(std::cout, entry.vals.settings, 8);
	std::cout << "\nPresence: " << entry.vals.presence << std::dec;
}
//for ease of file editing
std::ofstream& operator<<(std::ofstream &file, const GOBJ_entry &o){
	file.write((char *)o.entry.data, 0x3c);
	return file;
}
std::ifstream& operator>>(std::ifstream &file, GOBJ_entry &o){
	static char temp[0x3c];
	file.read(temp, 0x3c);
	o=temp;
	return file;
}
