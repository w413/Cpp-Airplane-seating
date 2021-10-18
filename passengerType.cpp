/*****************************/
/** Programmer: Wayne Benge **/
/** IDE: Dev-C++ 5.11		**/
/*****************************/

/***********************************************************************************************/
// Uncomment line below to print TASK macros to standard out
// #define TASK_PRINT
/***********************************************************************************************/

#include "passengerType.h"
#include "myTasks.h"
#include <iostream>
#include <iomanip>

/***********************************************************************************************/
/**** Structure passengerType:  member functions											****/
/***********************************************************************************************/

void passengerType::setnull() {
	TASK("Zeroing struct")
	fName="null";
	lName="null";
	ID=0;
	fare=0.0;
}

/***********************************************************************************************/
/**** Structure passengerType: Overloaded operators											****/
/***********************************************************************************************/

passengerType passengerType::operator=(passengerType &p) {
	this->fName=p.fName;	
	this->lName=p.lName;
	this->ID=p.ID;
	this->fare=p.fare;
	
	return *this;
}

bool passengerType::operator==(passengerType &p) {
	if(this->fName==p.fName && this->lName==p.lName && this->ID==p.ID
		&& this->fare==p.fare)
		return true;
	else
		return false;
}

std::ostream& operator<<(std::ostream &os, const passengerType &p) {
	os << p.ID << ' ' << p.lName << ' ' << p.fName << ' ' << p.fare;
	return os;
}
