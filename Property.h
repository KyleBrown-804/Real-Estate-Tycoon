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
	int value;
	string location;
	int mortgage;
	const double property_tax = value * 0.015;
	Tenant[] tenats;
};


#endif //REAL_ESTATE_TYCOON_PROPERTY_H
