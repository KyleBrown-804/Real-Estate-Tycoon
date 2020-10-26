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

	struct Room{
		bool isOccupied;
		double currentRent;
	};

	bool isVacant;
	bool isBusiness;
	double value;
	string location;
	double mortgage;
	double mortgage_progress;
	int mortgage_duration;
	const double property_tax = value * 0.015;
	int max_tenants;
	Tenant *tenants;
	int occupied_rooms;
	double currentRent;
	Room *rooms;


    // functions for houses, apartments, and business complexes
    double get_value();
    double get_mortgage();
    string get_location();
    int get_spaces();
    int get_occupied_rooms();
    double get_rent();

    void set_value(double value);
    void set_mortgage(double mortgage);
    void set_location(double location);
    void set_vacancies(int rooms);
    string to_string();
    void spacesToString();



};


#endif //REAL_ESTATE_TYCOON_PROPERTY_H
