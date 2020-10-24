//
// Created by Kyle Brown on 10/17/2020.
//

#include "Business.h"

const string *sizes;

/*** Business constructor
 *
 */
Business::Business() {
	max_tenants = 1 + rand() % 5;
	tenats = new Tenant[max_tenants];
	sizes = new string[max_tenants];

	value = 400000 + (rand() % 200000) + 1;
	mortgage = 500 + rand() % 4500;
	mortgage_duration = value / mortgage;
}

/***
 *
 * @param orig
 */
Business::Business(Business &orig) {
	max_tenants = orig.max_tenants;
	tenats = orig.tenats;

	value = orig.value;
	mortgage = orig.mortgage;
	mortgage_duration = orig.mortgage_duration;
}

/** Business "equals" operator overload
 *
 * @param right - Business to be copied
 * @return this - Copied Business object
 */
Business & Business::operator=(const Business &right) {
    // Handles the case of self assignment x = x better
    if (&right == this) {
        return (*this);
    }

    else {
        this->max_tenants = right.max_tenants;
        this->tenats = right.tenats;

        this->value = right.value;
        this->mortgage = right.mortgage;
        this->mortgage_duration = right.mortgage_duration;

        return (*this);
    }
}

Business::~Business() {

}

