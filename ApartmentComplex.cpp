//
// Created by Kyle Brown on 10/17/2020.
//

#include "ApartmentComplex.h"

/*** ApartmentComplex constructor
 *
 */
ApartmentComplex::ApartmentComplex() {
	max_tenants = 1 + rand() % 10;

	tenants = new Tenant[max_tenants];

	// populate for number of max tenants, (Tenants of type citizen)
	for (int i = 0; i< max_tenants; i++) {
		Tenant *temp = new Tenant(Tenant::citizen);
        tenants[i] = *temp;
	}

	value = 300000 + (rand() % 300000) + 1;
	mortgage = 500 + (rand() % 4500) + 1;
	mortgage_duration = value / mortgage;

	rooms = new Room[max_tenants];
	for(int i = 0; i < max_tenants; i++){
		rooms[i].isOccupied = true;
		rooms[i].currentRent = 400;
	}
}


/*** ApartmentComplex copy constructor
 *
 * @param orig
 */
ApartmentComplex::ApartmentComplex(ApartmentComplex &orig) {
	value = orig.value;
	location = orig.location;
	mortgage = orig.mortgage;
	mortgage_duration = orig.mortgage_duration;
	max_tenants = orig.max_tenants;
	tenants = orig.tenants;
	rooms = orig.rooms;
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
		this->location = right.location;
		this->value = right.value;
		this->mortgage = right.mortgage;
		this->mortgage_duration = right.mortgage_duration;
		this->rooms = rooms;

        return (*this);
    }
}

/*** ApartmentComplex destructor
 *
 */
ApartmentComplex::~ApartmentComplex() {

}