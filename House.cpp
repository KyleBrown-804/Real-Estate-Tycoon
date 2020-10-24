//
// Created by Kyle Brown on 10/17/2020.
//

#include "House.h"

/*** House constructor
 *
 */
House::House() {
	max_tenants = 1;
	tenats = new Tenant[max_tenants];

	value = 100000 + (rand() % 500000) + 1;
	mortgage = 500 + rand() % 4500;
	mortgage_duration = value / mortgage;
}


/*** House copy constructor
 *
 * @param orig - House to be copied
 * @return this - Copied House object
 */
House::House(House &orig) {
	max_tenants = orig.max_tenants;
	tenats = orig.tenats;

	value = orig.value;
	mortgage = orig.mortgage;
	mortgage_duration = orig.mortgage_duration;
}

/** House "equals" operator overload
 *
 * @param right - House to be copied
 * @return this - Copied House Object
 */
House & House::operator=(const House &right) {
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

/*** House deconstructor
 *
 */
House::~House() {

}