//
// Created by Kyle Brown on 10/17/2020.
//

#include "Apartment.h"

/*** Apartment constructor
 *
 */
Apartment::Apartment() {
	max_tenants = 1 + rand() % 10;
	tenats = new Tenant[max_tenants];

	value = 300000 + rand() % 10000;
	mortgage = 500 + rand() % 4500;
	mortgage_duration = value / mortgage;
}


/*** Apartment copy constructor
 *
 * @param orig
 */
Apartment::Apartment(Apartment &orig) {
	max_tenants = orig.max_tenants;
	tenats = orig.tenats;

	value = orig.value;
	mortgage = orig.mortgage;
	mortgage_duration = orig.mortgage_duration;
}

/** Apartment "equals" operator overload
 *
 * @param right - Apartment to be copied
 * @return this - Copied Apartment object
 */
Apartment & Apartment::operator=(const Apartment &right) {

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

/*** Apartment destructor
 *
 */
Apartment::~Apartment() {

}