//
// Created by Kyle Brown on 10/17/2020.
//

#ifndef REAL_ESTATE_TYCOON_PROPERTY_H
#define REAL_ESTATE_TYCOON_PROPERTY_H

#include <string>
#include "Tenant.h"
using namespace std;

class Property {

	/***
	 * fields
	 */

public:

	// constructor
	Property();

	// copy constructor
	Property(Property &orig);

	// Deconstructor
	~Property();

	int value;
	string location;
	int mortgage;
	int mortgage_duration;
	const double property_tax = value * 0.015;
	int max_tenants;
	Tenant *tenats;

	// idk what this refers to so I made it int temporarily
	int spaces;

    // functions for houses, apartments, and business complexes
    double get_value();
    int get_mortgage();
    string get_location();
    int get_spaces();

};


#endif //REAL_ESTATE_TYCOON_PROPERTY_H
