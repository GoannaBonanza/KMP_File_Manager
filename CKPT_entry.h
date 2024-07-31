#ifndef CKPT_ENTRY_H_INCLUDED
#define CKPT_ENTRY_H_INCLUDED
#include <fstream>
class CKPT_entry{
	private:
	public:
	//for storing checkpoint info
	union{
		unsigned char data[0x14];
		struct{
			float lpoint[2];
			float rpoint[2];
			unsigned char respawn_pos;
			unsigned char type;
			unsigned char prev;
			unsigned char next;
		}vals;
	}entry;
	//default, unknown object
	CKPT_entry()=default;
	//copy over without sharing memory
	CKPT_entry(const CKPT_entry &);
	CKPT_entry(const char *obj);
	CKPT_entry& operator=(const CKPT_entry &);
	CKPT_entry& operator=(const char *);
	~CKPT_entry()=default;
	//flip endian
	void flipVals();
	void display() const;
	//for placing kmp object into kmp file
	friend std::ofstream& operator<<(std::ofstream &, const CKPT_entry &);
	friend std::ifstream& operator>>(std::ifstream &, CKPT_entry &);
};
#endif
