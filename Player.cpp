//
// Created by Miguel on 10/23/2020.
//

#include "Player.h"
#include "Property.h"
#include <iostream>
#include "Houses.h"
#include <list>
#include <iterator>

using namespace std;

Player::Player() {
    bank_account = 500000;
    num_Properties = 0;
    has_Vacancies = false;
    player_properties = new Property[20];
}

Player::Player(Player &orig) {

}

Player::~Player() {

}

int Player::get_num_properties() {
    return num_Properties;
}

void Player::collect_rent() {
	for(int i = 0; i < num_Properties; i++){
		bank_account += player_properties[i].get_rent();
	}
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
			if(currentTenant.agreeability > 2 && currentTenant.maxBudget < currentProp.rooms[j].currentRent){
				cout << "Yikes! A tenant has left property #"<< i+1 << " because the rent is too damn high!" << endl;
			    currentProp.rooms[j].isOccupied = false;
			}
		}
	}
}

bool Player::has_vacant_properties() {

}

void Player::add_property(Property p) {

	if (num_Properties < 20) {
		player_properties[num_Properties] = p;
		num_Properties++;
	}
}

void Player::sell_property() {

}

void Player::view_properties() {

    for(int i = 0; i < num_Properties; i++) {
		cout << "=============" << endl;
		cout << "Property #" << i+1 << endl;
		cout << player_properties[i].to_string() << endl;
    }
}

void Player::adjust_rent_inputs() {

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

    cout << "Mortgages have been paid for all properties!" << endl;
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

        if(currentProp.isSold) {
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

        if(currentProp.isSold) {
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

        if(currentProp.isSold) {
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

        if(currentProp.isSold) {
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

        if(currentProp.isSold) {
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

        if(currentProp.isSold) {
            continue;
        }

        currentProp.value *= 1.20;
    }

    cout << "Good news finally! Hipsters with their IPA's and underground Indie / Ska bands \n"
            "have helped bring culture and pretentiousness to your city! \n"
            "Due to gentrification all of your property values have increased by 20%! " << endl;
}