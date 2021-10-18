/*****************************/
/** Programmer: Wayne Benge **/
/** IDE: Dev-C++ 5.11		**/
/*****************************/

#include "passengerType.h"
#include <string>

#ifndef seatingType_DOT_H
#define seatingType_DOT_H

class seatingType {
/*
	Object to manage seating assignment and manifest information
*/
	public:
		seatingType(int row=17, int col=6);
			// Class constructor
			
        void availableSeats() const;
			// Prints avaliable seats to standard output in INTINTCHAR format ex(01A, 10C)
			//	starting at 01A and ending with
			//	endRowNum endColLet
		
		void assignSeat(std::string lName, std::string fName, double baseCost);
			// Randomly assigns a seat with cost baseCost
			
        bool reassignSeat(int rCurrent, int cCurrent,
						  int rNext, int cNext, double surcharge=0);
            // Reassigns seat adding surcharge to current ticket price
            // Returns false if cannot reassign
            
		void printSeating() const;
			// Prints seating table to standard output with customer ID assigned to
			//	corresponding seats.
			//		Standard seat range: 1001-1999 (Randomly assigned or non-window/aisle seats)
			//		Upgraded seat range: 2001-2999
			//		Unassigned seat: 0000
			
		void printManifest() const;
			// Prints passenger information in following format:
			//	<seat number> <ID> <last name> <first name> <fare>
			
		void lockManifest();
			// Sets locked value to true.
			//	This will prevent reassignSeat() & assignSeat() from operating as normal
			//	reassignSeat() & assignSeat() will instead print:
			// 	"Manifest is currently locked" to standard output
			
	    void unlockManifest();
	    	// Sets locked value to false
	    	//	reassignSeat() & assignSeat() will function as intended
	    	
		double totalFares() const;
			// Adds fares from all passengers and returns value
		
	private:
		// User-defined data type. Defined in passengerType.h
		passengerType **passenger;
		
		// Primitive data types
		const int rowMax;
		const int colMax;
		int passengerTotal;
		char *colLetter;
		bool locked;
		
		int seatNum(int row, int col) const;
		int getRow(int seatNum) const;
		int getCol(int seatNum) const;
		std::string seatStr(int row, int col) const;
};

#endif
