//
// Created by Kyle Brown on 10/17/2020.
//

#include "Houses.h"

/*** Houses constructor
 *
 */
Houses::Houses() {
	max_tenants = 1;

	// populating single tenant for house (Tenant type citizen)
    Tenant * tenants[max_tenants];
    tenants[0] = new Tenant(Tenant::citizen);

	value = 100000 + (rand() % 500000) + 1;
	mortgage = 500 + (rand() % 4500) + 1;
	mortgage_duration = value / mortgage;
}


/*** Houses copy constructor
 *
 * @param orig - Houses to be copied
 * @return this - Copied Houses object
 */
Houses::Houses(Houses &orig) {
	max_tenants = orig.max_tenants;
	tenants = orig.tenants;

	value = orig.value;
	mortgage = orig.mortgage;
	mortgage_duration = orig.mortgage_duration;
}

/** Houses "equals" operator overload
 *
 * @param right - Houses to be copied
 * @return this - Copied Houses Object
 */
Houses & Houses::operator=(const Houses &right) {
    // Handles the case of self assignment x = x better
    if (&right == this) {
        return (*this);
    }

    else {
        this->max_tenants = right.max_tenants;
        this->tenants = right.tenants;

        this->value = right.value;
        this->mortgage = right.mortgage;
        this->mortgage_duration = right.mortgage_duration;

        return (*this);
    }
}

/*** Houses deconstructor
 *
 */
Houses::~Houses() {

}