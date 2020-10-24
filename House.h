//
// Created by Kyle Brown on 10/17/2020.
//

#ifndef REAL_ESTATE_TYCOON_HOUSE_H
#define REAL_ESTATE_TYCOON_HOUSE_H
#include "Property.h"

class House: Property {
public:
	// Constructor
	House();

	// copy constructor
	House(House &orig);

	// equals operator overload
	House & operator=(const House &right);

	// deconstructor
	~House();

};


#endif //REAL_ESTATE_TYCOON_HOUSE_H
