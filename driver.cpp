#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"

/**
 * @authors Kyle Brown, Miguel Garnica
 * @date 10/25/2020
 */
int main() {
	srand(time(NULL)); //Seeding the random number generator

	cout << "-------------------------------------" << endl;
	cout << "Made by Kyle Brown and Miguel Garnica" << endl;
    cout << "-------------------------------------"<< "\n" << endl;

    Game g;
	g.game_loop();
    return 0;
}
