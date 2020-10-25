//
// Created by Kyle Brown on 10/17/2020.
//

#include "BusinessComplex.h"

const string sizes[] = {"small", "medium", "large"};

/*** BusinessComplex constructor
 *
 */
BusinessComplex::BusinessComplex() {
    // initialization
	max_tenants = 1 + rand() % 5;
	roomSizes = new string[max_tenants];
    Tenant * tenants[max_tenants];

    // populate for number of max tenants, (Tenants of type business)
    for (int i = 0; i< max_tenants; i++) {
        tenants[i] = new Tenant(Tenant::business);

        // specifying a business room size
        int size_id = rand() % 3;
        roomSizes[i] = sizes[size_id];
    }

	value = 400000 + (rand() % 200000) + 1;
	mortgage = 500 + (rand() % 4500) + 1;
	mortgage_duration = value / mortgage;
}

/***
 *
 * @param orig
 */
BusinessComplex::BusinessComplex(BusinessComplex &orig) {
	max_tenants = orig.max_tenants;
	tenants = orig.tenants;
	location = orig.location;
	value = orig.value;
	mortgage = orig.mortgage;
	mortgage_duration = orig.mortgage_duration;
}

/** BusinessComplex "equals" operator overload
 *
 * @param right - BusinessComplex to be copied
 * @return this - Copied BusinessComplex object
 */
BusinessComplex & BusinessComplex::operator=(const BusinessComplex &right) {
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

BusinessComplex::~BusinessComplex() {

}

