#include "display.h"
#include <iostream>
std::ostream& disp_vec(std::ostream& os, const float* vector, int count){
	for(int i=0; i<count; i++) os << vector[i] << ' ';
	return os;
}
std::ostream& disp_vals(std::ostream& os, const unsigned short* vector, int count){
	for(int i=0; i<count; i++) os << vector[i] << ' ';
	return os;
}
