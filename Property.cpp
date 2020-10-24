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
	//return max_tenants;
	return -1;
}

string Property::get_location() {
	return location;
}

