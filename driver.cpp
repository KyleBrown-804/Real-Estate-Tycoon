/********************************************************************
* Program: driver.cpp
* Description: This is the main file for
*              the Real Estate Tycoon assignment.
********************************************************************/
#include "Game.h"
// #include "Player.h"
// #include "Property.h"
// #include "House.h"
// #include "Apartment.h"
// #include "Business.h"
// #include "Tenant.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
  srand(time(NULL)); //Seeding the random number generator

  Game g;
  g.game_loop();

}
