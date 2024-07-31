#ifndef KTPT_ENTRY_H_INCLUDED
#define KTPT_ENTRY_H_INCLUDED
#include <fstream>
class KTPT_entry{
	private:
	public:
	//for storing spawnpoint info
	union{
		unsigned char data[0x1c];
		struct{
			float pos[3];
			float rot[3];
			short index;
			unsigned short padding;
		}vals;
	}entry;
	//default, unknown object
	KTPT_entry()=default;
	//copy over without sharing memory
	KTPT_entry(const KTPT_entry &);
	KTPT_entry(const char *);
	KTPT_entry& operator=(const KTPT_entry &);
	KTPT_entry& operator=(const char *);
	~KTPT_entry()=default;
	//flip endian
	void flipVals();
	void display() const;
	//for placing kmp object into kmp file
	friend std::ofstream& operator<<(std::ofstream &, const KTPT_entry &);
	friend std::ifstream& operator>>(std::ifstream &, KTPT_entry &);
};
#endif
