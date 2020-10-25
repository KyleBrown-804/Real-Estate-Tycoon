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

}

void Player::flag_vancies() {

}

bool Player::has_vacant_properties() {

}

void Player::add_property(Property p) {

	if (num_Properties < 20) {
		player_properties[0] = p;
		num_Properties++;
	}
}

void Player::sell_property() {

}

void Player::view_properties() {

    for(int i = 0; i < num_Properties; i++) {
		cout << player_properties[i].get_location() << endl;
		cout << player_properties[i].get_value() << endl;
		cout << player_properties[i].get_mortgage() << endl;
		cout << player_properties[i].get_spaces() << endl;
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