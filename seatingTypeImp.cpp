/*****************************/
/** Programmer: Wayne Benge **/
/** IDE: Dev-C++ 5.11		**/
/*****************************/

/***********************************************************************************************/
// Uncommentting line below will print TASK macros to standard out
//#define TASK_PRINT
// Uncommenting line below will run code contained in DEBUG macros
//#define DEBUG_ON
/***********************************************************************************************/

#include "passengerType.h"
#include "seatingType.h"
#include "myTasks.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

/***********************************************************************************************/
/**** Object seatingType: public functions													****/
/***********************************************************************************************/

seatingType::seatingType(int row, int col) : rowMax(row), colMax(col) { // In progress
	TASK("Checking row for overflow and underflow")
	if(row==100)
		throw std::overflow_error("Row too large; Max 99");
	if(row<=0)
		throw std::underflow_error("Row too small; Min 1");
		
	TASK("Checking col for overflow and underflow")
	if(col==27)
		throw std::overflow_error("Column too large; Max 26");
	if(col<=0)
		throw std::underflow_error("Column too small; Min 1");
		
	TASK("Setting size of two-dimensional array, passenger")
	passenger = new passengerType*[rowMax];
	for(int i=0; i<rowMax; ++i)
		passenger[i] = new passengerType[colMax];
		
	TASK("Initializing two-dimensional array, passenger")
	for(int r=0; r<rowMax; ++r)
		for(int c=0; c<colMax; ++c)
			passenger[r][c].setnull();
	passengerTotal=0;
	colLetter = new char[colMax];
	
	TASK("Initializing array, colLetter")
	for(int i=0; i<colMax; ++i)
		colLetter[i]=static_cast<char>(i+65);
		
	TASK("Unlocking manifest")
	locked=false;
	
	TASK("Setting seed")
	srand(time(NULL));
}

void seatingType::availableSeats() const { // Unfinished; Current Flags
	TASK("Print available seats")
	for(int r=0; r<rowMax; ++r) {
		for(int c=0; c<colMax; ++c)
			if(passenger[r][c].lName=="null") {
				std::cout << seatStr(r,c) << ' ';
			} else {
				std::cout << "N/A" << ' ';
			}
		std::cout << std::endl;
	}
}

void seatingType::assignSeat(std::string lName, std::string fName, double baseCost) { // Unfinished
	
	passengerType null;
	int seatNum, row, col;
	null.setnull();
	TASK("Checking manifest status")
	if(passengerTotal==colMax*rowMax)
		lockManifest();
	if(locked==true) {
		std::cout << "\n**Manifest is Locked (No Changes Allowed)**\n";
		return;
	}
	
	TASK("Selecting seat number")
	do {
		seatNum=rand()%(rowMax*colMax);
		row=getRow(seatNum);
		col=getCol(seatNum);
	} while(!(passenger[row][col] == null));
	
	TASK("Assigning seat")
	++passengerTotal;
	passenger[row][col].lName = lName;
	passenger[row][col].fName = fName;
	passenger[row][col].fare = baseCost;
	passenger[row][col].ID = passengerTotal + 1000;
	
}

bool seatingType::reassignSeat(int rCurrent, int cCurrent,
							   int rNext, int cNext, double surcharge) { // Unfinished
	passengerType null;
	null.setnull();
	TASK("Checking manifest status")
	if(locked==true) {
		std::cout << "\n**Manifest is Locked (No Changes Allowed)**\n";
		return false;
	}
	
	TASK("Checking if seat is available")
	if(!(passenger[rNext][cNext] == null)) {
		std::cout << "Seat taken; please select new seat\n";
		return false;
	}
	
	TASK("Assigning new seat")
	passenger[rCurrent][cCurrent] = passenger[rNext][cNext];
	
	TASK("Deallocating old seat")
	passenger[rCurrent][cCurrent] = null;
	
	TASK("Adding surcharge")
	passenger[rNext][cNext].fare+=surcharge;
	
	return true;
}

void seatingType::printSeating() const { // Finished; Untested
	TASK("Printing seating")
	for(int r=0; r<rowMax; ++r) {
		for(int c=0; c<colMax; ++c) {
			std::cout << std::setw(4) << std::setfill('0')
				<< passenger[r][c].ID << ' ';
		}
		std::cout << std::endl;
	}
}

void seatingType::printManifest() const {
	TASK("Printing Manifest")
	for(int r=0; r<rowMax; ++r)
		for(int c=0; c<colMax; ++c)
			if(passenger[r][c].lName=="null")
				continue;
			else {
				std::cout << seatStr(r,c) << ' ';
				std::cout << passenger[r][c] << std::endl;
			}
}

void seatingType::lockManifest() {
	TASK("Locking manifest")
	locked=true;	
}

void seatingType::unlockManifest() {
	TASK("Unlocking manifest")
	locked=false;
}

double seatingType::totalFares() const { // Finished; Untested
	double total=0.0;
	
	TASK("Totaling fares")
	for(int r=0; r<rowMax; ++r)
		for(int c=0; c<colMax; ++c)
			total+=passenger[r][c].fare;
	return total;
}

/***********************************************************************************************/
/**** Object seatingType: private functions													****/
/***********************************************************************************************/

int seatingType::seatNum(int row, int col) const {
	TASK("Calculating raw integer seat number")
	return (row*colMax)+col;
}

int seatingType::getRow(int seatNum) const { 
	TASK("Calculating row")
	return seatNum/colMax;
}

int seatingType::getCol(int seatNum) const {
	TASK("Calculating col")
	return seatNum%colMax;
}

std::string seatingType::seatStr(int row, int col) const {
	int rowNum, num = seatNum(row,col);
	std::string ret;
	
	TASK("Converting row and column to human-readable")
	rowNum = getRow(num)+1;
	ret = static_cast<char>((rowNum/10)+48);
	ret+= static_cast<char>((rowNum%10)+48);
	ret+= colLetter[getCol(num)];
	return ret;
}
