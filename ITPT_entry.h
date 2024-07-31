#ifndef ITPT_ENTRY_H_INCLUDED
#define ITPT_ENTRY_H_INCLUDED
#include <fstream>
class ITPT_entry{
	private:
	public:
	//for storing itempoint info
	union{
		unsigned char data[0x14];
		struct{
			float pos[3];
			float bound;
			unsigned short set1;
			unsigned short set2;
		}vals;
	}entry;
	//default, unknown object
	ITPT_entry()=default;
	//copy over without sharing memory
	ITPT_entry(const ITPT_entry &);
	ITPT_entry(const char *);
	ITPT_entry& operator=(const ITPT_entry &);
	ITPT_entry& operator=(const char *);
	~ITPT_entry()=default;
	//flip endian
	void flipVals();
	void display() const;
	//for placing kmp object into kmp file
	friend std::ofstream& operator<<(std::ofstream &, const ITPT_entry &);
	friend std::ifstream& operator>>(std::ifstream &, ITPT_entry &);
};
#endif
