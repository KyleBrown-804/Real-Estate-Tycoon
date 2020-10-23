//
// Created by Kyle Brown on 10/17/2020.
//

#ifndef REAL_ESTATE_TYCOON_BUSINESS_H
#define REAL_ESTATE_TYCOON_BUSINESS_H
#include "Property.h"


class Business: Property {

public:
	// constructor
	Business();

	// copy constructor
	Business(Business &orig);

	// deconstructor
	~Business();
};


#endif //REAL_ESTATE_TYCOON_BUSINESS_H
