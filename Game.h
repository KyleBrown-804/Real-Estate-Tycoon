//
// Created by Miguel on 10/23/2020.
//

#ifndef REAL_ESTATE_TYCOON_GAME_H
#define REAL_ESTATE_TYCOON_GAME_H

#include "House.h";
#include "Apartment.h"
#include "Business.h"
#include "Player.h"

class Game {

public:

	/***
	 * functions
	 */
	// constructor
	Game();

	// copy constructor
	Game(const Game &g);

	// deconstructor
	~Game();

	// assignment operator
	Game & operator=(const Game &g);

	// copy function
	void copy(const Game& g);

	// game loop
	void game_loop();

	// random event
	void random_event();

	// player makes a choice
	void turn_choice();

	// buying properties
	void buy_property();

	// buy house
	void buy_house(int h_idx);

	// buy apartment complex
	void buy_a_complex(int a_idx);

	// buy business complex
	void buy_b_complex(int b_idx);

	/***
	 * fields
	 */

	// property, houses, apartment and business complexes

	// houses
	int num_houses;
	House[] houses;

	// apartments
	int num_a = 3;
	Apartment[] a_complexes;

	// businesses
	int num_b = 3;
	Business[] b_complexes;

	// Player
	Player player;

};


#endif //REAL_ESTATE_TYCOON_GAME_H

