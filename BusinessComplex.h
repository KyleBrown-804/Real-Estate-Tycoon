//
// Created by Kyle Brown on 10/17/2020.
//

#ifndef REAL_ESTATE_TYCOON_BUSINESSCOMPLEX_H
#define REAL_ESTATE_TYCOON_BUSINESSCOMPLEX_H
#include "Property.h"

class BusinessComplex: public Property {

public:
	// constructor
	BusinessComplex();

	// copy constructor
	BusinessComplex(BusinessComplex &orig);

	// equals operator overload
    BusinessComplex & operator=(const BusinessComplex &right);

    // deconstructor
	~BusinessComplex();

	/**
	 * fields
	 */
	string * roomSizes;
};


#endif //REAL_ESTATE_TYCOON_BUSINESSCOMPLEX_H
