#ifndef SECTION_H_INCLUDED
#define SECTION_H_INCLUDED
#include "endian.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>
//union for section header
union Header{
	char data[0x8];
	struct{
		char name[0x4];
		unsigned short total_obj;
		unsigned short addit_info;
	} vals;
};
extern void flipSecHead(Header& h);
//templated for all entry types
template<typename T>
class Section{
	private:
	std::vector<T> entries;
	char*name;
	public:
	Section()=default;
	//make new entry
	void push(const T &);
	//remove entry
	void pop();
	//clear
	void clear();
	//read section from file
	void readfile(std::ifstream& file, unsigned short);
	size_t size();
	void display();
	T& operator[](size_t);
	friend std::ofstream& operator<<(std::ofstream &of, const Section<T> &e){
		for(T entry:e.entries){
			//flip to big endian
			entry.flipVals();
			of<<entry;
			//flip back for future editing
			entry.flipVals();
		}
		return of;
	}
};



template<typename T>
void Section<T>::push(const T &entry){
	entries.push_back(entry);
}
template<typename T>
void Section<T>::pop(){
	entries.pop_back();
}
template<typename T>
void Section<T>::clear(){
	entries.clear();
}
template<typename T>
void Section<T>::readfile(std::ifstream& file, unsigned short count){
	T entry;
	for(unsigned int i=0; i<count; i++){
		file >> entry;
		entry.flipVals();
		push(entry);
	}
}
template<typename T>
T& Section<T>::operator[](size_t ind){
	if(ind>=entries.size()) throw std::range_error("Index out of bounds for given section");
	return entries[ind]; 
}
template<typename T>
size_t Section<T>::size(){
	return entries.size();
}
template<typename T>
void Section<T>::display(){
	std::cout << '\n';
	for(const T& entry:entries){
		entry.display();
		std::cout << "\n\n";
	}
}
#endif
