//
// Created by Kyle Brown on 10/17/2020.
//

#ifndef REAL_ESTATE_TYCOON_TENANT_H
#define REAL_ESTATE_TYCOON_TENANT_H


class Tenant {

public:

    // enum Tenant type
    enum Type {
        citizen,
        business
    };

	// constructor
	Tenant(Type tenType);

	// copy constructor
	Tenant(Tenant &orig);

	// equals operator overload
	Tenant & operator=(const Tenant &right);

	// deconstructor
	~Tenant();

	// fields
	    int agreeability;
	    int maxBudget;
        Type tenantType;
};


#endif //REAL_ESTATE_TYCOON_TENANT_H
