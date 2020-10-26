//
// Created by Kyle Brown on 10/17/2020.
//

#include "Property.h"
#include "Tenant.h"
#include <cstdlib>

const string locations[] = {"SE", "NE", "Midwest", "SW", "NW"};

/*** Property Constructor
 *
 */
Property::Property(){
	int loc_id = rand() % 5;
	location = locations[loc_id];
	mortgage_progress = 0;
    isSold = false;
}

/*** Property copy constructor
 *
 * @param orig - Property to be copied
 */
Property::Property(Property &orig) {
	value = orig.value;
	location = orig.location;
	mortgage = orig.mortgage;
	mortgage_duration = orig.mortgage_duration;
	mortgage_progress = orig.mortgage_progress;
	max_tenants = orig.max_tenants;
	tenants = orig.tenants;
	rooms = orig.rooms;
	isSold = orig.isSold;
}

Property & Property::operator=(const Property &right) {
	// Handles the case of self assignment x = x better
	if (&right == this) {
		return (*this);
	}

	else {
		this->max_tenants = right.max_tenants;
		this->tenants = right.tenants;
		this->location = right.location;
		this->value = right.value;
		this->mortgage = right.mortgage;
		this->mortgage_duration = right.mortgage_duration;
		this->mortgage_progress = right.mortgage_progress;
		this->isSold = right.isSold;
		this->rooms = right.rooms;

		return (*this);
	}
}

/*** Property destructor
 *
 */
Property::~Property() {

}

double Property::get_value() {
	return value;
}

/**
 * @description Collects all rent payments for the given property
 *
 * @return total_rent - combined rent payments
 */
double Property::get_rent() {
	double total_rent = 0;
	for(int i = 0; i < max_tenants; i++){
		if(!rooms[i].isOccupied) continue;
		if(tenants[i].agreeability < 2 && tenants[i].maxBudget < rooms[i].currentRent) continue;

		total_rent += rooms[i].currentRent;
	}
	return total_rent;
}

double Property::get_mortgage() {
	return mortgage;
}

int Property::get_spaces() {
	return max_tenants;
}

string Property::get_location() {
	return location;
}

int Property::get_occupied_rooms() {
	return occupied_rooms;
}

string Property::to_string() {
	string str;
	str += "Property Value:\t" + std::to_string(value);
	str += "\nMortgage:\t" + std::to_string(mortgage);
	str += "\nLocation:\t" + location;
	str += "\nUnits:\t" + std::to_string(max_tenants);
	return str;
}

