//
// Created by Kyle Brown on 10/17/2020.
//

#include "Property.h"
#include <cstdlib>

const string locations[] = {"SE", "NE", "Midwest", "SW", "NW"};

/*** Property Constructor
 *
 */
Property::Property(){
	int loc_id = rand() % 5;
	location = locations[loc_id];
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
	max_tenants = orig.max_tenants;
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

double Property::get_mortgage() {
	return mortgage;
}

int Property::get_spaces() {
	return max_tenants;
}

string Property::get_location() {
	return location;
}

int Property::get_max_tenants() {
	return max_tenants;
}

void Property::set_tenants(int tenants) {
	max_tenants = tenants;
}

