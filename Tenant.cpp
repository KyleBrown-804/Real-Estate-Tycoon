//
// Created by Kyle Brown on 10/17/2020.
//

#include <cstdlib>
#include "Tenant.h"
#include <iostream>

using namespace std;

Tenant::Tenant() {

}

/** Tenant Constructor
 *
 * @description 50/50 chance the tenant is assigned a citizen or business type,
 * random agree-ability score between 1-5, and random max budget depending on type
 * of tenant.
 */
Tenant::Tenant(Type tenType) {

	dead = false;
    if(tenType == citizen) {
         tenantType = citizen;
         maxBudget = 500 + (rand() % 5000) + 1;
    }
    else {
        tenantType = business;
        maxBudget = 2000 + (rand() % 10000) + 1;
    }

    agreeability = (rand() % 5) + 1;
}

/** Tenant Copy Constructor
 *
 * @param orig
 */
Tenant::Tenant(Tenant &orig) {
    tenantType = orig.tenantType;
    agreeability = orig.agreeability;
    maxBudget = orig.maxBudget;
}

/** Tenant equals operator overload
 *
 * @param right - Tenant object to be copied
 * @return this - The copied Tenant object
 */
Tenant & Tenant::operator=(const Tenant &right) {

	if (&right == this) {
		return (*this);
	}

	else {
		this->tenantType = right.tenantType;
		this->agreeability = right.agreeability;
		this->maxBudget = right.maxBudget;
		return (*this);
	}
}

/** Tenant destructor
 *
 */
Tenant::~Tenant() {

}