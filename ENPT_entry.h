#ifndef ENPT_ENTRY_H_INCLUDED
#define ENPT_ENTRY_H_INCLUDED
#include <fstream>
class ENPT_entry{
	private:
	public:
	//for storing enemypoint info
	union{
		unsigned char data[0x14];
		struct{
			float pos[3];
			float bound;
			unsigned short set1;
			unsigned char set2;
			unsigned char set3;
		}vals;
	}entry;
	//default, unknown object
	ENPT_entry()=default;
	//copy over without sharing memory
	ENPT_entry(const ENPT_entry &);
	ENPT_entry(const char *);
	ENPT_entry& operator=(const ENPT_entry &);
	ENPT_entry& operator=(const char *);
	~ENPT_entry()=default;
	//flip endian
	void flipVals();
	void display() const;
	//for placing kmp object into kmp file
	friend std::ofstream& operator<<(std::ofstream &, const ENPT_entry &);
	friend std::ifstream& operator>>(std::ifstream &, ENPT_entry &);
};
#endif
