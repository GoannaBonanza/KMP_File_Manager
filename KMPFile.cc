#include "KMPFile.h"
#include "Section.h"
#include "KTPT_entry.h"
#include "XXPH_entry.h"
#include "ENPT_entry.h"
#include "ITPT_entry.h"
#include "CKPT_entry.h"
#include "GOBJ_entry.h"
#include "POTI_entry.h"
#include "AREA_entry.h"
#include "CAME_entry.h"
#include "XXPT_entry.h"
#include "STGI_entry.h"
#include "endian.h"
#include <fstream>
#include <string>
#include <stdexcept>

#include <iostream>

using namespace std;
KMPFile::KMPFile(const char *filepath){
	ifstream ifs(filepath);
	filename=filepath;
	if(!ifs) throw runtime_error("Bad filename given: " + filename);
	ifs.seekg(0);
	ifs.read(header.data, 0x4c);
	if(!ifs) throw runtime_error("Ran out of data in: " + filename);
	//make everything little endian
	flipHead();
	//read data into section headers
	for(unsigned short i=0; i<15; ++i){
		ifs.seekg(0x4c+header.vals.offsets[i]);
		ifs.read(sec_heads[i].data, 0x8);
		//convert to little endian
		flipSecHead(sec_heads[i]);
	}
	//read entry data into Sections
	
	for(unsigned short i=0; i<15; i++){
		if(!ifs) throw runtime_error("Failure in section reading: " + filename);
		ifs.seekg(0x4c+header.vals.offsets[i]+0x8);
		switch (i){
		case 0: ktpt.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 1: enpt.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 2: enph.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 3: itpt.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 4: itph.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 5: ckpt.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 6: ckph.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 7: gobj.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 8: poti.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 9: area.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 10: came.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 11: jgpt.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 12: cnpt.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 13: mspt.readfile(ifs, sec_heads[i].vals.total_obj); break;
		case 14: stgi.readfile(ifs, sec_heads[i].vals.total_obj); break;
		}
	}
}
KMPFile::KMPFile(){
	filename="course.kmp";
	header.vals.magic[0]='R';
	header.vals.magic[1]='K';
	header.vals.magic[2]='M';
	header.vals.magic[3]='D';
	header.vals.filelen=0x4c+(0x8*15);
	header.vals.numsec=15;
	header.vals.headlen=0x4c;
	header.vals.version=0x9d8;
	for(unsigned short i=0; i<15; i++){
		unsigned int off=0;
		header.vals.offsets[i]=off;
		off+=0x8;
	}
}
void KMPFile::save(const char* name){
	//cout << "1\n";
	ofstream ofs(name);
	//save file header
	//note that the offsets of the section headers never changes
	flipHead();
	ofs.write(header.data, 0x4c);
	//cout << "2\n";
	//update header info
	sec_heads[0].vals.total_obj=ktpt.size();
	sec_heads[1].vals.total_obj=enpt.size();
	sec_heads[2].vals.total_obj=enph.size();
	sec_heads[3].vals.total_obj=itpt.size();
	sec_heads[4].vals.total_obj=itph.size();
	sec_heads[5].vals.total_obj=ckpt.size();
	sec_heads[6].vals.total_obj=ckph.size();
	sec_heads[7].vals.total_obj=gobj.size();
	sec_heads[8].vals.total_obj=poti.size();
	sec_heads[9].vals.total_obj=area.size();
	sec_heads[10].vals.total_obj=came.size();
	sec_heads[11].vals.total_obj=jgpt.size();
	sec_heads[12].vals.total_obj=cnpt.size();
	sec_heads[13].vals.total_obj=mspt.size();
	sec_heads[14].vals.total_obj=stgi.size();
	//save each header
	//cout << "3\n";
	for(unsigned short i=0; i<15; i++){
		flipSecHead(sec_heads[i]);
		ofs.write(sec_heads[i].data, 0x8);
	}
	//cout << "4\n";
	//save sections
	ofs << ktpt;
	//cout << "5\n";
	ofs << enpt;
	ofs << enph;
	ofs << itpt;
	ofs << itph;
	ofs << ckpt;
	ofs << ckph;
	ofs << gobj;
	//cout << "6\n";
	ofs << poti;
	//cout << "7\n";
	ofs << area;
	ofs << came;
	ofs << jgpt;
	ofs << cnpt;
	ofs << mspt;
	ofs << stgi;
	//cout << "13\n";
}
void KMPFile::flipHead(){
	flip(header.vals.filelen);
	flip(header.vals.numsec);
	flip(header.vals.headlen);
	flip(header.vals.version);
	for(unsigned short i=0; i<15; i++) flip(header.vals.offsets[i]);
}
string KMPFile::name(){return filename;}
Section<KTPT_entry>& KMPFile::KTPT(){return ktpt;}
Section<ENPT_entry>& KMPFile::ENPT(){return enpt;}
Section<XXPH_entry>& KMPFile::ENPH(){return enph;}
Section<ITPT_entry>& KMPFile::ITPT(){return itpt;}
Section<XXPH_entry>& KMPFile::ITPH(){return itph;}
Section<CKPT_entry>& KMPFile::CKPT(){return ckpt;}
Section<XXPH_entry>& KMPFile::CKPH(){return ckph;}
Section<GOBJ_entry>& KMPFile::GOBJ(){return gobj;}
Section<POTI_entry>& KMPFile::POTI(){return poti;}
Section<AREA_entry>& KMPFile::AREA(){return area;}
Section<CAME_entry>& KMPFile::CAME(){return came;}
Section<XXPT_entry>& KMPFile::JGPT(){return jgpt;}
Section<XXPT_entry>& KMPFile::CNPT(){return cnpt;}
Section<XXPT_entry>& KMPFile::MSPT(){return mspt;}
Section<STGI_entry>& KMPFile::STGI(){return stgi;}
