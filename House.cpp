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

	value = 100000 + rand() % 200000;
	mortgage = 500 + rand() % 4500;
	mortgage_duration = value / mortgage;
}


/*** House copy constructor
 *
 * @param orig - House to be copied
 */
House::House(House &orig) {
	max_tenants = orig.max_tenants;
	tenats = orig.tenats;

	value = orig.value;
	mortgage = orig.mortgage;
	mortgage_duration = orig.mortgage_duration;
}


/*** House deconstructor
 *
 */
House::~House() {

}