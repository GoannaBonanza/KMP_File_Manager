#ifndef XXPH_ENTRY_H_INCLUDED
#define XXPH_ENTRY_H_INCLUDED
#include <fstream>
class XXPH_entry{
	private:
	public:
	//ENPH, ITPH, CKPH all have identical format
	union{
		unsigned char data[0x10];
		struct{
			char start;
			char count;
			char from[6];
			char to[6];
			unsigned short padding;
		}vals;
	}entry;
	//default, unknown object
	XXPH_entry()=default;
	//copy over without sharing memory
	XXPH_entry(const XXPH_entry &);
	XXPH_entry(const char *);
	XXPH_entry& operator=(const XXPH_entry &);
	XXPH_entry& operator=(const char *);
	~XXPH_entry()=default;
	//flip endian
	void flipVals();
	void display() const;
	//for placing kmp object into kmp file
	friend std::ofstream& operator<<(std::ofstream &, const XXPH_entry &);
	friend std::ifstream& operator>>(std::ifstream &, XXPH_entry &);
};
#endif
