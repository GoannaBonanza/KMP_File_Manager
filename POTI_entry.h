#ifndef POTI_ENTRY_H_INCLUDED
#define POTI_ENTRY_H_INCLUDED
#include <vector>
#include <fstream>
class route_pt{
	private:
	public:
	//each individual route point
	union{
		unsigned char data[0x10];
		struct{
			float pos[3];
			unsigned short speed;
			unsigned short setting;
		}vals;
	}entry;
	route_pt()=default;
	//copy without sharing memory
	route_pt(const route_pt &);
	route_pt(const char *);
	route_pt& operator=(const route_pt &);
	route_pt& operator=(const char *);
	~route_pt()=default;
	//flip endian
	void flipVals();
	void display() const;
	//for placing kmp object into kmp file
	friend std::ofstream& operator<<(std::ofstream &, const route_pt &);
	friend std::ifstream& operator>>(std::ifstream &, route_pt &);
};
class POTI_entry{
	private:
	public:
	//for storing route info
	union{
		unsigned char data[0x4];
		struct{
			unsigned short count;
			unsigned char smooth;
			unsigned char cyclic;
		}vals;
	}entry;
	std::vector<route_pt> route;
	//default, unknown object
	POTI_entry()=default;
	//copy over without sharing memory
	POTI_entry(const POTI_entry &);
	POTI_entry(const char *);
	POTI_entry& operator=(const POTI_entry &);
	POTI_entry& operator=(const char *);
	~POTI_entry()=default;
	//set route
	void path(const std::vector<route_pt> &r){route=r;}
	//flip endian
	void flipVals();
	//add point to route
	void add_pt(route_pt p);
	//for placing kmp object into kmp file
	friend std::ofstream& operator<<(std::ofstream &, const POTI_entry &);
	friend std::ifstream& operator>>(std::ifstream &, POTI_entry &);
};
#endif
