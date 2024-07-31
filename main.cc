#include "Section.h"
#include "GOBJ_entry.h"
#include "KTPT_entry.h"
#include "ENPT_entry.h"
#include "ITPT_entry.h"
#include "CKPT_entry.h"
#include "XXPH_entry.h"
#include "POTI_entry.h"
#include "AREA_entry.h"
#include "CAME_entry.h"
#include "XXPT_entry.h"
#include "STGI_entry.h"
#include "display.h"
#include "endian.h"
#include "KMPFile.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;
void make_obj_table(const char* filename, map<int, string> &table){
	ifstream file(filename);
	if(!file) return;
	string temp;
	int tempid;
	for(unsigned short i=0; i<316; i++){
		//get id num
		getline(file, temp);
		tempid=stoi(temp, nullptr, 16);
		//get object name
		getline(file, temp);
		table.insert(pair<int, string>(tempid, temp));
	}
}
int main(int argc, char **argv){
	int section;
	//make object table
	map<int, string> obj_table;
	make_obj_table("obj.txt", obj_table);
	//open file
	ifstream raw(argc>1?argv[1]:"course.kmp");
	if(!raw){
		cerr << "Bad filename \"" << (argc>1?argv[1]:"course.kmp") << "\" given while running: " << argv[0] << '\n';
		return 1;
	}
	raw.close();
	//open file
	KMPFile kmp(argc>1?argv[1]:"course.kmp");
	//user input begin
	bool cont=true;
	cout << "File " << kmp.name() << " opened successfully:\n";
	while(cont){
		cout << "What section would you like to view?\n";
		cout << "KTPT(0)\t\tENPT(1)\nITPT(2)\t\tCKPT(3)\nENPH(4)\t\tITPH(5)\nCKPH(6)\t\tGOBJ(7)\
		\nPOTI(8)\t\tAREA(9)\nCAME(10)\tJGPT(11)\
		\nCNPT(12)\tMSPT(13)\nSTGI(14)\tOr quit(15)\nSelect: ";
		cin >> section;
		if(!cin){
			cerr << "Invalid input provided. Please only enter numbers. Ending execution.\n";
			return 1;
		}
		switch(section){
		case 0:
			cout << "Retrieving KTPT data...\n";
			break;
		case 1:
			cout << "Retrieving ENPT data...\n";
			break;
		case 2:
			cout << "Retrieving ITPT data...\n";
			break;
		case 3:
			cout << "Retrieving CKPT data...\n";
			break;
		case 4:
			cout << "Retrieving ENPH data...\n";
			break;
		case 5:
			cout << "Retrieving ITPH data...\n";
			break;
		case 6:
			cout << "Retrieving CKPH data...\n";
			break;
		case 7:
			cout << "Retrieving GOBJ data...\n";
			kmp.GOBJ().display();
			break;
		case 8:
			cout << "Retrieving POTI data...\n";
			break;
		case 9:
			cout << "Retrieving AREA data...\n";
			break;
		case 10:
			cout << "Retrieving CAME data...\n";
			break;
		case 11:
			cout << "Retrieving JGPT data...\n";
			break;
		case 12:
			cout << "Retrieving CNPT data...\n";
			break;
		case 13:
			cout << "Retrieving MSPT data...\n";
			break;
		case 14:
			cout << "Retrieving STGI data...\n";
			break;
		//NOT FUNCTIONAL
		//TESTING ONLY
		case 99:
			cout << "Writing file...\n";
			kmp.save("out.kmp");
			cout << "Done!\n";
			return 0;
		default:
			cout << "Exiting...\n";
			cont=false;
			break;
		}
		//reset section to always end if input somehow avoided
		section=15;
	}
	return 0;
}
