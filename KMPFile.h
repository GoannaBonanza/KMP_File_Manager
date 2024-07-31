#ifndef KMPFILE_H_INCLUDED
#define KMPFILE_H_INCLUDED
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
#include <fstream>
#include <string>
class KMPFile{
	private:
	//filename
	std::string filename;
	//all file data
	char *rawData=nullptr;
	union{
		char data[0x4c];
		struct{
			//always RKMD
			char magic[4];
			//file length
			unsigned int filelen;
			//number sections, 15 usually
			unsigned short numsec;
			//header length, 0x4c
			unsigned short headlen;
			//version number, default 0x9d8
			unsigned int version;
			//offsets
			unsigned int offsets[15];
		} vals;
	} header;
	//section Headers
	Header sec_heads[15];
	//sections
	Section<KTPT_entry> ktpt;
	Section<ENPT_entry> enpt;
	Section<XXPH_entry> enph;
	Section<ITPT_entry> itpt;
	Section<XXPH_entry> itph;
	Section<CKPT_entry> ckpt;
	Section<XXPH_entry> ckph;
	Section<GOBJ_entry> gobj;
	Section<POTI_entry> poti;
	Section<AREA_entry> area;
	Section<CAME_entry> came;
	Section<XXPT_entry> jgpt;
	Section<XXPT_entry> cnpt;
	Section<XXPT_entry> mspt;
	Section<STGI_entry> stgi;
	//public stuff
	public:
	KMPFile();
	KMPFile(const char *);
	~KMPFile()=default;
	//both these do a shallow coopy on header union
	KMPFile(const KMPFile &)=default;
	KMPFile& operator=(const KMPFile &)=default;
	//convert every value in header to its little endian counterpart
	void flipHead();
	void save(const char*);
	std::string name();
	Section<KTPT_entry>& KTPT();
	Section<ENPT_entry>& ENPT();
	Section<XXPH_entry>& ENPH();
	Section<ITPT_entry>& ITPT();
	Section<XXPH_entry>& ITPH();
	Section<CKPT_entry>& CKPT();
	Section<XXPH_entry>& CKPH();
	Section<GOBJ_entry>& GOBJ();
	Section<POTI_entry>& POTI();
	Section<AREA_entry>& AREA();
	Section<CAME_entry>& CAME();
	Section<XXPT_entry>& JGPT();
	Section<XXPT_entry>& CNPT();
	Section<XXPT_entry>& MSPT();
	Section<STGI_entry>& STGI();
};
#endif
