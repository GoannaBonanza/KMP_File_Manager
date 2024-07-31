#ifndef GOBJ_ENTRY_H_INCLUDED
#define GOBJ_ENTRY_H_INCLUDED
#include <map>
#include <string>
#include <fstream>
std::map<int, std::string> make_obj_table(const char*);
class GOBJ_entry{
	private:
	public:
	//for storing object info
	union{
		unsigned char data[0x3c];
		struct{
			unsigned short id;
			unsigned short padding;
			float pos[3];
			float rot[3];
			float scale[3];
			unsigned short route;
			unsigned short settings[8];
			unsigned short presence;
		}vals;
	}entry;
	//default, unknown object
	GOBJ_entry()=default;
	//copy over without sharing memory
	GOBJ_entry(const GOBJ_entry &);
	GOBJ_entry(const char *);
	GOBJ_entry& operator=(const GOBJ_entry &);
	GOBJ_entry& operator=(const char *);
	~GOBJ_entry()=default;
	//flip endian
	void flipVals();
	void display() const;
	//for placing kmp object into kmp file
	friend std::ofstream& operator<<(std::ofstream &, const GOBJ_entry &);
	friend std::ifstream& operator>>(std::ifstream &, GOBJ_entry &);
};
#endif
