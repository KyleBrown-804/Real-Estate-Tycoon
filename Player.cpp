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

void Player::flag_vancies() {
	for(int i = 0; i < num_Properties; i++){
		Property currentProp = player_properties[i];

		for(int j = 0; j < currentProp.max_tenants; j++){

			if(!currentProp.rooms[j].isOccupied) continue;

			Tenant currentTenant = currentProp.tenants[j];
			if(currentTenant.agreeability > 2 && currentTenant.maxBudget < currentProp.rooms[j].currentRent){
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

void Player::pay_mortgages() {

}

void Player::pay_taxes() {

}

double Player::get_money() {
	return bank_account;
}

/***
 *  EVENTS
 */

void Player::hurricane() {

}


void Player::tornado() {

}

void Player::earthquake() {

}

void Player::wildfire() {

}

void Player::stock_market_crash() {

}

void Player::gentrification() {

}