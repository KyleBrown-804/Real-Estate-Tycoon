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

	// equals operator overload
	Property & operator=( const Property &right);

	// Deconstructor
	~Property();

	double value;
	string location;
	double mortgage;
	int mortgage_duration;
	const double property_tax = value * 0.015;
	int max_tenants;
	Tenant *tenants;


    // functions for houses, apartments, and business complexes
    double get_value();
    double get_mortgage();
    string get_location();
    int get_spaces();
    int get_max_tenants();

    void set_tenants(int tenants);
    void set_value(double value);
    void set_mortgage(double mortgage);
    void set_location(double location);


};


#endif //REAL_ESTATE_TYCOON_PROPERTY_H
