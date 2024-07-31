#include "Section.h"
#include "endian.h"
void flipSecHead(Header& h){
	flip(h.vals.total_obj);
	flip(h.vals.addit_info);
}
