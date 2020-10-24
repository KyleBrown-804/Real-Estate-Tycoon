//
// Created by Kyle Brown on 10/17/2020.
//

#ifndef REAL_ESTATE_TYCOON_APARTMENT_H
#define REAL_ESTATE_TYCOON_APARTMENT_H
#include "Property.h"

class Apartment: public Property {

public:
	// constructor
	Apartment();

	// copy constructor
	Apartment(Apartment &orig);

	// equals operator overload
    Apartment & operator=(const Apartment &right);

    // deconstructor
	~Apartment();
};


#endif //REAL_ESTATE_TYCOON_APARTMENT_H
