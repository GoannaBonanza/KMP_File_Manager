#ifndef AREA_ENTRY_H_INCLUDED
#define AREA_ENTRY_H_INCLUDED
#include <fstream>
class AREA_entry{
	private:
	public:
	//for storing area info
	union{
		unsigned char data[0x30];
		struct{
			unsigned char shape;
			//vals 0x0 to 0xa for type
			unsigned char type;
			unsigned char came_index;
			unsigned char priority;
			float pos[3];
			float rot[3];
			float scale[3];
			unsigned short setting1;
			unsigned short setting2;
			unsigned char route_id;
			unsigned char enemy_id;
			unsigned short padding;
		}vals;
	}entry;
	//default, unknown object
	AREA_entry()=default;
	//copy over without sharing memory
	AREA_entry(const AREA_entry &);
	AREA_entry(const char *);
	AREA_entry& operator=(const AREA_entry &);
	AREA_entry& operator=(const char *);
	~AREA_entry()=default;
	//flip endian
	void flipVals();
	void display() const;
	//for placing kmp object into kmp file
	friend std::ofstream& operator<<(std::ofstream &, const AREA_entry &);
	friend std::ifstream& operator>>(std::ifstream &, AREA_entry &);
};
#endif
