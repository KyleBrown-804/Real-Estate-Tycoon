//
// Created by Kyle Brown on 10/17/2020.
//

#include "House.h"

House::House() {
	max_tenants = 1;
	tenats = new Tenant[max_tenants];

	value = rand() % 200000 + 100000;
	mortgage = rand() % 4500 + 500;
	mortgage_duration = value / mortgage;


}

House::House(House &orig) {
	max_tenants = orig.max_tenants;
	tenats = orig.tenats;

	value = orig.value;
	mortgage = orig.mortgage;
	mortgage_duration = orig.mortgage_duration;
}

House::~House() {

}