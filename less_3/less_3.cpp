#define _CRT_SECURE_NO_WARNINGS
#include "simulator.h"

//0556707712 מירי 

void main() {
	simulator* s = new simulator();
	std::cout << "good!!\n";
	std::cout << s;
	if (s != NULL) {
	    s->begin();
	}
		
	std::cout << "very good!!\n";

}