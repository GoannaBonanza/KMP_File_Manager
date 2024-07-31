#ifndef CAME_ENTRY_H_INCLUDED
#define CAME_ENTRY_H_INCLUDED
#include <fstream>
class CAME_entry{
	private:
	public:
	//for storing camera info
	union{
		unsigned char data[0x48];
		struct{
			unsigned char type;
			unsigned char next;
			unsigned char camshake;
			unsigned char route;
			unsigned short velo_point;
			unsigned short velo_zoom;
			unsigned short velo_view;
			unsigned char startflag;
			unsigned char movieflag;
			float pos[3];
			float rot[3];
			float zoomstart;
			float zoomend;
			float start_vector[3];
			float end_vector[3];
			float time;
		}vals;
	}entry;
	//default, unknown object
	CAME_entry()=default;
	//copy over without sharing memory
	CAME_entry(const CAME_entry &);
	CAME_entry(const char *);
	CAME_entry& operator=(const CAME_entry &);
	CAME_entry& operator=(const char *);
	~CAME_entry()=default;
	//flip endian
	void flipVals();
	void display() const;
	//for placing kmp object into kmp file
	friend std::ofstream& operator<<(std::ofstream &, const CAME_entry &);
	friend std::ifstream& operator>>(std::ifstream &, CAME_entry &);
};
#endif
