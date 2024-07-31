#ifndef STGI_ENTRY_H_INCLUDED
#define STGI_ENTRY_H_INCLUDED
#include <fstream>
class STGI_entry{
	private:
	public:
	//for storing itempoint info
	union{
		unsigned char data[0xc];
		struct{
			unsigned char lap_count;
			unsigned char pole_pos;
			unsigned char driver_dis;
			struct{
				unsigned char enabled;
				unsigned int color;
				unsigned char alpha;	
			}flare;
			unsigned short unknown;
			unsigned char padding;
		}vals;
	}entry;
	//default, unknown object
	STGI_entry()=default;
	//copy over without sharing memory
	STGI_entry(const STGI_entry &);
	STGI_entry(const char *);
	STGI_entry& operator=(const STGI_entry &);
	STGI_entry& operator=(const char *);
	~STGI_entry()=default;
	//flip endian
	void flipVals();
	void display() const;
	//for placing kmp object into kmp file
	friend std::ofstream& operator<<(std::ofstream &, const STGI_entry &);
	friend std::ifstream& operator>>(std::ifstream &, STGI_entry &);
};
#endif
