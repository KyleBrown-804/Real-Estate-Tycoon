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

	value = 300000 + rand() % 10000;
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

Business::~Business() {

}

