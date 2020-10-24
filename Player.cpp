//
// Created by Miguel on 10/23/2020.
//

#include "Player.h"

Player::Player() {
    bank_account = 500000;
    num_Properties = 0;
    has_Vacancies = false;
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

}

void Player::sell_property() {

}

void Player::view_properties() {

    for(int i = 0; i < num_Properties; i++) {

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