#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"

int main() {
	srand(time(NULL)); //Seeding the random number generator

	Game g;
	g.game_loop();
    return 0;
}
