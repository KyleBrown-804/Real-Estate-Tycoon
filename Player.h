//
// Created by Miguel on 10/23/2020.
//

#ifndef REAL_ESTATE_TYCOON_PLAYER_H
#define REAL_ESTATE_TYCOON_PLAYER_H

#include "Player.h"
#include "Property.h"
#include <list>
#include <iterator>

class Player {
public:

	/***
	 * functions
	 */
	// constructor
	Player();

	// copy constructor
	Player(Player &orig);

	// deconstructor
	~Player();

	// get number of properties
	int get_num_properties();

	// collect rent on all properties
	void collect_rent();

	// flag all vacancies of tenants who have left
	void flag_vancies();

	// return true if any vacant properties
	bool has_vacant_properties();

	// sell a property
	void sell_property();

	// add a property;
	void add_property(Property p);

	// view all properties
	void view_properties();

	// adjust rent
	void adjust_rent_inputs();

	// pay mortages on properties
	void pay_mortgages();

	// pay all property taxes
	void pay_taxes();

	// return money in bank account
	double get_money();

	// hurricane in the SE. properties down 50%
	void hurricane();

	// tornado in the Midwest. properties down 30%
	void tornado();

	// earthquake in the NW. down 10%
	void earthquake();

	// wildfire in the SW. down 25%
	void wildfire();

	//stock market crash. all down 30%
	void stock_market_crash();

	// gentrification. all up 20%
	void gentrification();

private:
    /**
     * Fields
     */
    int num_Properties;
    bool has_Vacancies;
    double bank_account;

    Property *player_properties;

};


#endif //REAL_ESTATE_TYCOON_PLAYER_H
