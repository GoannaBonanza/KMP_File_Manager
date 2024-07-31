CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -Wpedantic
ENTRYS=KTPT_entry.o XXPH_entry.o ENPT_entry.o ITPT_entry.o CKPT_entry.o GOBJ_entry.o POTI_entry.o AREA_entry.o CAME_entry.o XXPT_entry.o STGI_entry.o
ENTRY_DEPS=endian.h display.h
OBJECT_FILES=main.o Section.o KMPFile.o display.o endian.o $(ENTRYS)

KMP: $(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) $(OBJECT_FILES) -o KMP
	
main.o: main.cc Section.h $(ENTRYS) $(ENTRY_DEPS) KMPFile.h
	$(CXX) $(CXXFLAGS) -c main.cc
	
entry.a: $(ENTRYS)
	ar rvs entry.a $(ENTRYS)

KTPT_entry.o: KTPT_entry.cc KTPT_entry.h $(ENTRY_DEPS)
	$(CXX) $(CXXFLAGS) -c KTPT_entry.cc

XXPH_entry.o: XXPH_entry.cc XXPH_entry.h $(ENTRY_DEPS)
	$(CXX) $(CXXFLAGS) -c XXPH_entry.cc

ENPT_entry.o: ENPT_entry.cc ENPT_entry.h $(ENTRY_DEPS)
	$(CXX) $(CXXFLAGS) -c ENPT_entry.cc

ITPT_entry.o: ITPT_entry.cc ITPT_entry.h $(ENTRY_DEPS)
	$(CXX) $(CXXFLAGS) -c ITPT_entry.cc

CKPT_entry.o: CKPT_entry.cc CKPT_entry.h $(ENTRY_DEPS)
	$(CXX) $(CXXFLAGS) -c CKPT_entry.cc

GOBJ_entry.o: GOBJ_entry.cc GOBJ_entry.h $(ENTRY_DEPS)
	$(CXX) $(CXXFLAGS) -c GOBJ_entry.cc
	
POTI_entry.o: POTI_entry.cc POTI_entry.h $(ENTRY_DEPS)
	$(CXX) $(CXXFLAGS) -c POTI_entry.cc

AREA_entry.o: AREA_entry.cc AREA_entry.h $(ENTRY_DEPS)
	$(CXX) $(CXXFLAGS) -c AREA_entry.cc

CAME_entry.o: CAME_entry.cc CAME_entry.h $(ENTRY_DEPS)
	$(CXX) $(CXXFLAGS) -c CAME_entry.cc
	
XXPT_entry.o: XXPT_entry.cc XXPT_entry.h $(ENTRY_DEPS)
	$(CXX) $(CXXFLAGS) -c XXPT_entry.cc

STGI_entry.o: STGI_entry.cc STGI_entry.h $(ENTRY_DEPS)
	$(CXX) $(CXXFLAGS) -c STGI_entry.cc

Section.o: Section.cc Section.h
	$(CXX) $(CXXFLAGS) -c Section.cc

endian.o: endian.cc endian.h
	$(CXX) $(CXXFLAGS) -c endian.cc
	
display.o: display.cc display.h
	$(CXX) $(CXXFLAGS) -c display.cc
	
KMPFile.o: KMPFile.cc KMPFile.h Section.h
	$(CXX) $(CXXFLAGS) -c KMPFile.cc

clean:
	rm -f KMP *.o *.a
