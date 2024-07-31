#ifndef XXPT_ENTRY_H_INCLUDED
#define XXPT_ENTRY_H_INCLUDED
#include <fstream>
class XXPT_entry{
	private:
	public:
	//for storing JGPT, CNPT, MSPT
	union{
		unsigned char data[0x1c];
		struct{
			float pos[3];
			float rot[3];
			unsigned short id;
			unsigned short setting;
		}vals;
	}entry;
	//default, unknown object
	XXPT_entry()=default;
	//copy over without sharing memory
	XXPT_entry(const XXPT_entry &);
	XXPT_entry(const char *);
	XXPT_entry& operator=(const XXPT_entry &);
	XXPT_entry& operator=(const char *);
	~XXPT_entry()=default;
	//flip endian
	void flipVals();
	void display() const;
	//for placing kmp object into kmp file
	friend std::ofstream& operator<<(std::ofstream &, const XXPT_entry &);
	friend std::ifstream& operator>>(std::ifstream &, XXPT_entry &);
};
#endif
