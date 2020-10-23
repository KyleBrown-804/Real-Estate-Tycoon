//
// Created by Kyle Brown on 10/17/2020.
//

#include "Property.h"

const string locations[] = {"SE", "NE", "Midwest", "SW", "NW"};

Property::Property(){
	int loc_id = rand() % 5;
	location = locations[loc_id];
}


Property::Property(Property &orig) {
	value = orig.value;
	location = orig.location;
	mortgage = orig.mortgage;
	mortgage_duration = orig.mortgage_duration;
	max_tenants = orig.max_tenants;

}

Property::~Property() {

}

