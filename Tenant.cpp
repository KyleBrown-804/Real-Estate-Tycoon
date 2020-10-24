//
// Created by Kyle Brown on 10/17/2020.
//

#include <cstdlib>
#include "Tenant.h"
#include <iostream>

using namespace std;

/** Tenant Constructor
 *
 * @description 50/50 chance the tenant is assigned a citizen or business type,
 * random agree-ability score between 1-5, and random max budget depending on type
 * of tenant.
 */
Tenant::Tenant() {
    bool isCitizen = (rand() % 2) != 0;

    if(isCitizen) {
         tenantType = citizen;
         maxBudget = 500 + (rand() % 5000);
    }
    else {
        tenantType = business;
        maxBudget = 2000 + (rand() % 10000);
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
    tenantType = right.tenantType;
    agreeability = right.agreeability;
    maxBudget = right.maxBudget;
}

/** Tenant destructor
 *
 */
Tenant::~Tenant() {

}