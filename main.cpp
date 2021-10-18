/*****************************/
/** Programmer: Wayne Benge **/
/** IDE: Dev-C++ 5.11		**/
/*****************************/

#include "seatingType.h"
#include <iostream>
#include <fstream>
#define BASE_PRICE (100)

int main() {
	seatingType seating;
	std::string fname, lname;
	std::ifstream nameFile;
	nameFile.open("nameList.txt");
	while(!nameFile.eof()) {
		 nameFile >> fname >> lname;
		 seating.assignSeat(lname, fname, BASE_PRICE);
	}
	seating.printSeating();
	seating.printManifest();
	std::cout << seating.totalFares();
	
	return 0;
}

/*
Build notes:

class seatingType has unfinished members
file seatingTypeImp.cpp is undocumented
*/
