//
// Created by Kyle Brown on 10/17/2020.
//

#ifndef REAL_ESTATE_TYCOON_HOUSES_H
#define REAL_ESTATE_TYCOON_HOUSES_H
#include "Property.h"

class Houses: public Property {
public:
	// Constructor
	Houses();

	// copy constructor
	Houses(Houses &orig);

	// equals operator overload
	Houses & operator=(const Houses &right);

	// deconstructor
	~Houses();

};


#endif //REAL_ESTATE_TYCOON_HOUSES_H
