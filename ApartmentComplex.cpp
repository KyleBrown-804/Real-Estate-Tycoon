//
// Created by Kyle Brown on 10/17/2020.
//

#include "ApartmentComplex.h"

/*** ApartmentComplex constructor
 *
 */
ApartmentComplex::ApartmentComplex() {
	max_tenants = 1 + rand() % 10;

	Tenant * tenants[max_tenants];

	// populate for number of max tenants, (Tenants of type citizen)
	for (int i = 0; i< max_tenants; i++) {
        tenants[i] = new Tenant(Tenant::citizen);
	}

	value = 300000 + (rand() % 300000) + 1;
	mortgage = 500 + (rand() % 4500) + 1;
	mortgage_duration = value / mortgage;
}


/*** ApartmentComplex copy constructor
 *
 * @param orig
 */
ApartmentComplex::ApartmentComplex(ApartmentComplex &orig) {
	max_tenants = orig.max_tenants;
	tenants = orig.tenants;

	value = orig.value;
	mortgage = orig.mortgage;
	mortgage_duration = orig.mortgage_duration;
}

/** ApartmentComplex "equals" operator overload
 *
 * @param right - ApartmentComplex to be copied
 * @return this - Copied ApartmentComplex object
 */
ApartmentComplex & ApartmentComplex::operator=(const ApartmentComplex &right) {

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

/*** ApartmentComplex destructor
 *
 */
ApartmentComplex::~ApartmentComplex() {

}