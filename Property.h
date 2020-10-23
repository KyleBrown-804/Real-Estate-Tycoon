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
};


#endif //REAL_ESTATE_TYCOON_PROPERTY_H
