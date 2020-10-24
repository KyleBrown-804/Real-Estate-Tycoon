//
// Created by Kyle Brown on 10/17/2020.
//

#ifndef REAL_ESTATE_TYCOON_APARTMENTCOMPLEX_H
#define REAL_ESTATE_TYCOON_APARTMENTCOMPLEX_H
#include "Property.h"

class ApartmentComplex: public Property {

public:
	// constructor
	ApartmentComplex();

	// copy constructor
	ApartmentComplex(ApartmentComplex &orig);

	// equals operator overload
    ApartmentComplex & operator=(const ApartmentComplex &right);

    // deconstructor
	~ApartmentComplex();
};


#endif //REAL_ESTATE_TYCOON_APARTMENTCOMPLEX_H
