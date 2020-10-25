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
	tenants = new Tenant[max_tenants];
	Tenant *temp = new Tenant(Tenant::citizen);
    tenants[0] = *temp ;

	value = 100000 + (rand() % 500000) + 1;
	mortgage = 500 + (rand() % 4500) + 1;
	mortgage_duration = value / mortgage;

	rooms = new Room[max_tenants];

	for(int i = 0; i < max_tenants; i++){
		rooms[i].isOccupied = true;
		rooms[i].currentRent = 400;
	}
}


/*** Houses copy constructor
 *
 * @param orig - Houses to be copied
 * @return this - Copied Houses object
 */
Houses::Houses(Houses &orig) {
	value = orig.value;
	location = orig.location;
	mortgage = orig.mortgage;
	mortgage_duration = orig.mortgage_duration;
	max_tenants = orig.max_tenants;
	tenants = orig.tenants;
	rooms = orig.rooms;
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
		this->location = right.location;
		this->value = right.value;
		this->mortgage = right.mortgage;
		this->mortgage_duration = right.mortgage_duration;
		this->rooms = right.rooms;
        return (*this);
    }
}

/*** Houses deconstructor
 *
 */
Houses::~Houses() {

}