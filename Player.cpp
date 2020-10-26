//
// Created by Miguel on 10/23/2020.
//

#include "Player.h"
#include "Property.h"
#include "Houses.h"
#include "BusinessComplex.h"
#include "utilities.h"
#include <iostream>
#include <list>
#include <iterator>
#include <cstdlib>

using namespace std;

Player::Player() {
    bank_account = 500000;
    num_Properties = 0;
    has_Vacancies = false;
    player_properties = new Property[20];
}

Player::Player(Player &orig) {

}

/**
 *  @description We ran out of time to implement, however luckily 90% of our data
 *  is primitive values (except a few arrays) which are deleted implicitly.
 */
Player::~Player() {

}

int Player::get_num_properties() {
    return num_Properties;
}

/** Collect Rent
 *
 * @description collects rent from all properties which are not tagged
 * as completely vacant (no tenants).
 */
void Player::collect_rent() {
	for(int i = 0; i < num_Properties; i++){
	    Property currentProp = player_properties[i];

	    if(currentProp.isVacant) {
            continue;
	    }

		bank_account += currentProp.get_rent();
	}

	cout << "[RENT] Rent has been collected from all applicable properties!" << endl;
}

/**
 * @description Checks if rent is too high for a tenant, if so the
 * room is flagged as "un-occupied" therefore it will always be skipped
 * later.
 */
void Player::flag_vancies() {
	for(int i = 0; i < num_Properties; i++){
		Property currentProp = player_properties[i];

		for(int j = 0; j < currentProp.max_tenants; j++){

			if(!currentProp.rooms[j].isOccupied) continue;

			Tenant currentTenant = currentProp.tenants[j];
			if(currentTenant.agreeability >= 2 && currentTenant.maxBudget < currentProp.rooms[j].currentRent){
				cout << "Yikes! A tenant has left property #"<< i+1 << " because the rent is too damn high!" << endl;
			    currentProp.rooms[j].isOccupied = false;
			}
			else if(currentTenant.agreeability < 2 && currentTenant.maxBudget < currentProp.rooms[j].currentRent) {
			    cout << "The rent is to high for a tenant, however they are unreasonable and are refusing to leave! \n" <<
                        "In order to collect rent from them again, you must lower rent!" << endl;
			}
		}

        /** [SETS TO VACANT IF APPLICABLE]
		 * Goes through and checks if current residents exist
         * if not then it stays flagged as vacant.
		 */
		player_properties[i].isVacant = true;

		for(int j = 0; j < player_properties[i].max_tenants; j++) {

		    if(player_properties[i].rooms[j].isOccupied) {
				player_properties[i].isVacant = false;
                j = player_properties[i].max_tenants;
		    }
		}
	}
}

/**
 * @description Checks is any properties are completely vacant
 *
 * @return boolean - true if there is at least one vacant property else false
 */
bool Player::has_vacant_properties() {
    for(int i = 0; i < num_Properties; i++) {
        Property currentProp = player_properties[i];
        if(currentProp.isVacant && !currentProp.isSold) {
            return true;
        }
    }

    return false;
}

/**
 * @description Adds property to players properties
 *
 * @param p - the property to be added
 */
void Player::add_property(Property p) {
	if (num_Properties < 20) {

	    if(has_vacant_properties()) {
	        for(int i = 0; i < num_Properties; i++) {
	            if(player_properties[i].isSold) {
	                player_properties[i] = p;
	            }
	        }
	    }
	    else {
            player_properties[num_Properties] = p;
            num_Properties++;
	    }
	}
}

/**
 * @description Gets the list of all vacant properties then prompts the
 * user to pick which one to sell, then asks them for an asking price of sale
 * then randomly selects a selling event.
 */
void Player::sell_property() {
	int numVacant = 0;
	for(int i = 0; i < num_Properties; i++){
		if(player_properties[i].isVacant && !player_properties[i].isSold){
			numVacant++;
		}
	}

	int *vacant_indexes = new int[numVacant];
	int j = 0;
	for(int i = 0; i < num_Properties; i++){
		if(player_properties[i].isVacant && !player_properties[i].isSold){
			vacant_indexes[j] = i;
			j++;
		}
	}

	string input = "0";
	int prop_index = 0;

	do {
        printVacancies();
		cout << "Which property # would you like to sell?" << "\n" << endl;
		getline(cin, input);
		prop_index = check_and_convert_input(input);
	}
	while ( (prop_index < 1 || prop_index > num_Properties) && !isSellable(prop_index-1, vacant_indexes, numVacant));

	getSellingPrice(prop_index-1);

}

/**
 * @description prompts user for selling price
 * @param prop_i - property index to be sold
 */
void Player::getSellingPrice(int prop_i) {

	string askingPrice;
	double sellingPrice;

	cout << "What price would you like to sell at?" << endl;
	getline(cin, askingPrice);
	sellingPrice = check_and_convert_input(askingPrice);

	int luck = (rand() % 3) +1;
	if(luck == 3){
		cout << "You sold it for your asking price! " << sellingPrice << endl;
		bank_account += sellingPrice;
	}else if(luck == 2){
		sellingPrice = player_properties[prop_i].value;
		cout << "You sold it for the original property value! " << sellingPrice << endl;
		bank_account += sellingPrice;
	}else{
		sellingPrice = (player_properties[prop_i].value * 0.9);
		cout << "You sold it for your 10% less of original property value! " << sellingPrice << endl;
		bank_account += sellingPrice;
	}

	player_properties[prop_i].isSold = true;
}

/**
 * @description prints a list of all the vacant properties available
 */
void Player::printVacancies(){

    cout <<"================ VACANCIES ==================" << endl;
    for(int i = 0; i < num_Properties; i++){
		if(player_properties[i].isVacant && !player_properties[i].isSold){
			cout << "Property #" << i+1 << " is vacant" << endl;
			cout << player_properties[i].to_string() << endl;
		}
	}
}

/**
 * @description checks if the input property is sellable
 *
 * @param prop_i - the users selected property number
 * @param vacants - the array of vacant properties
 * @param size - array size of vacant properties
 * @return boolean - true if the input is a available vacant property
 */
bool Player::isSellable(int prop_i, int *vacants, int size){
	for(int i = 0; i < size; i++){
		if(vacants[i] == prop_i){
			return true;
		}
	}
	cout << "This property is not vacant!!" << endl;
	cout << "You can only sell vacant properties" << endl;
	return false;
}

/**
 * @description Prints out a list of all the player's current properties
 * if property is vacant then 'Vacant Property' is printed out instead
 */
void Player::view_properties() {
    for(int i = 0; i < num_Properties; i++) {

		cout << "================LIST OF PROPERTIES================" << endl;
		cout << "Property #" << i+1 << endl;

		if(player_properties[i].isSold) {
		    cout << "Sold property" << endl;
		}
        else if(player_properties[i].isVacant) {
            cout << "Vacant property" << endl;
            continue;
        }

		cout << player_properties[i].to_string() << endl;
    }
}

/**
 * @description Adjusts the rent inputs for a specific house, or apartment. If the property is
 * a business then the user is prompted again for which unit space to adjust rent for.
 */
void Player::adjust_rent_inputs() {
    string input = "0";
    int prop_index = 0;

    do {
        cout << "Which property # would you like to adjust rent for?" << "\n" << endl;
        getline(cin, input);
        prop_index = check_and_convert_input(input);
    }
    while (prop_index < 1 || prop_index > num_Properties);

    int adjusted_rent = 0;
    do {
        cout << "What will the new rent value be? (over 400 min and under max 5000)" << "\n" << endl;
        getline(cin, input);
        adjusted_rent = check_and_convert_input(input);
    }
    while (adjusted_rent < 400 || adjusted_rent > 5000);

    // adjusts rents specifically for specific business spaces
    if(player_properties[prop_index-1].isBusiness) {
        adjust_business_rents((prop_index - 1), adjusted_rent);
    }

    // adjust rent for houses & apartments
    else {
        Property currentProp = player_properties[prop_index-1];

        for(int i = 0; i < currentProp.max_tenants; i++) {
            if(!currentProp.rooms[i].isOccupied) {
                continue;
            }
            currentProp.rooms[i].currentRent = adjusted_rent;
        }

        cout << "[Adjusted Rent] Rent has been adjusted for all tenants" << endl;
    }
}

/**
 * @description specialty function that adjusts rent for a specific space
 * in a business complex.
 *
 * @param prop_i - the property index for the player's properties array
 * @param adjusted - the new rent value for the business
 */
void Player::adjust_business_rents(int prop_i, int adjusted) {

    // prints out list of business spaces in complex
    player_properties[prop_i].spacesToString();

    string input = "0";
    int bus_unit_index;
    do {
        cout << "Which business space do you want to change rent for?" << "\n" << endl;
        getline(cin, input);
        bus_unit_index = check_and_convert_input(input);
    }
    while (bus_unit_index < 1 || bus_unit_index > player_properties[prop_i].max_tenants);

    // changes the current rent for the specific business space
    player_properties[prop_i].rooms[bus_unit_index-1].currentRent = adjusted;
    cout << "Rent has been adjusted for the business in room #" << bus_unit_index << "\n" << endl;
}

/**
 * Deducts mortgage payments from bank account for all properties
 */
void Player::pay_mortgages() {

    for(int i = 0; i < num_Properties; i++) {
        Property currentProp = player_properties[i];

        if (currentProp.mortgage_progress >= currentProp.value) {
            continue;
        }

        bank_account -= currentProp.mortgage;
        currentProp.mortgage_progress += currentProp.mortgage;
    }

    cout << "[Mortgage] Mortgages have been paid for all properties!" << endl;
}

/**
 * Pays property taxes for all properties by deducting from the bank account
 */
void Player::pay_taxes() {
    for(int i = 0; i < num_Properties; i++) {
        Property currentProp = player_properties[i];

        bank_account -= (currentProp.value * 0.015);

        cout << "\n" <<"Oof, the government took your money from the yearly property taxes!" << endl;
    }
}

/**
 * Gets current player bank account total
 * @return bank_account - current bank total
 */
double Player::get_money() {
	return bank_account;
}

/***
 * ----------------------------------------------------
 *  EVENTS
 * ----------------------------------------------------
 */
void Player::hurricane() {

    for(int i = 0; i < num_Properties; i++) {
        Property currentProp = player_properties[i];

        if(currentProp.isVacant) {
            continue;
        }

        if(currentProp.location.compare("SE")) {
            currentProp.value *= .50;
        }
    }

    cout << "Oh *!$% a hurricane! All of your South East properties have been hit, \n"
            "subsequently all property values have been decreased by 50%" << endl;
}

void Player::tornado() {
    for(int i = 0; i < num_Properties; i++) {
        Property currentProp = player_properties[i];

        if(currentProp.isVacant) {
            continue;
        }

        if(currentProp.location.compare("Midwest")) {
            currentProp.value *= .70;
        }
    }

    cout << "Woooowwwww a darn tornado done come through and ruined all yer Midwest properties! \n"
            "All Midwest properties have been reduced by 30%" << endl;
}

void Player::earthquake() {
    for(int i = 0; i < num_Properties; i++) {
        Property currentProp = player_properties[i];

        if(currentProp.isVacant) {
            continue;
        }

        if(currentProp.location.compare("NW")) {
            currentProp.value *= .90;
        }
    }

    cout << "2fbekw jgb f293r9!!! That Earthquake completely leveled all of your North West properties! \n"
            "Now all North West properties have lost 10% their normal value!" << endl;
}

void Player::wildfire() {
    for(int i = 0; i < num_Properties; i++) {
        Property currentProp = player_properties[i];

        if(currentProp.isVacant) {
            continue;
        }

        if(currentProp.location.compare("SW")) {
            currentProp.value *= .75;
        }
    }

    cout << "Rip... as a result of a random gender reveal party, all of your South West properties have \n"
            "been burnt to a crisp! Now South West properties have reduced in value by 25%!" << endl;
}

void Player::stock_market_crash() {
    for(int i = 0; i < num_Properties; i++) {
        Property currentProp = player_properties[i];

        if(currentProp.isVacant) {
            continue;
        }

        currentProp.value *= .70;
    }

    cout << "Damnit those bitcoin farmers and wall street cats screwed us again! Somehow they broke the stock \n"
            "market and now all your properties have had values decreased by 30%!" << endl;
}

void Player::gentrification() {
    for(int i = 0; i < num_Properties; i++) {
        Property currentProp = player_properties[i];

        if(currentProp.isVacant) {
            continue;
        }

        currentProp.value *= 1.20;
    }

    cout << "Good news finally! Hipsters with their IPA's and underground Indie / Ska bands \n"
            "have helped bring culture and pretentiousness to your city! \n"
            "Due to gentrification all of your property values have increased by 20%! " << endl;
}