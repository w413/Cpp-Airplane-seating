/*****************************/
/** Programmer: Wayne Benge **/
/** IDE: Dev-C++ 5.11		**/
/*****************************/

#include <iostream>

#ifndef passengerType_DOT_H
#define passengerType_DOT_H

struct passengerType {
/*
	Stucture to hold passenger information
*/
	std::string fName;
	std::string lName;
	int ID;
	double fare;
	
	void setnull();
	
	passengerType operator=(passengerType&);
	bool operator==(passengerType&);
	friend std::ostream& operator<<(std::ostream &os, const passengerType &p);
};

#endif
