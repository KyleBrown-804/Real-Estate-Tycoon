/********************************************************************
* Program: Game.cpp
* Description: This is the implementation file for the Game class in
*              the Real Estate Tycoon assignment.
********************************************************************/
#include "Game.h"
#include "utilities.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/********************************************************************
*                           Game::Game
* This is the constructor for the Game class. It starts the game off
* with 3 of each kind of property and creates an array of three
* for each.
********************************************************************/
Game::Game()
{
  num_houses = 3;
  houses = new House[num_houses];
  num_a = 3;
  a_complexes = new Apartment[num_a];
  num_b = 3;
  b_complexes = new Business[num_b];
}

/********************************************************************
*                           Game::Game
* This is the copy constructor for a Game object.
********************************************************************/
Game::Game(const Game& g)
{
  copy(g);
}

/********************************************************************
*                           Game::~Game
* This is the destructor for the Game class.
********************************************************************/
Game::~Game()
{
  delete [] houses;
  houses = NULL;

  delete [] a_complexes;
  a_complexes = NULL;

  delete [] b_complexes;
  b_complexes = NULL;
}

/********************************************************************
*                           Game::Game
* This is the assignment operator overload function for the Game
* class.
********************************************************************/
Game &Game::operator=(const Game& g)
{
  if(this->houses != NULL)
    delete [] this->houses;

  if(this->a_complexes != NULL)
    delete [] this->a_complexes;

  if(this->b_complexes != NULL)
    delete [] this->b_complexes;

  copy(g);
}

/********************************************************************
*                           Game::copy
* This is the copy function for the Game class. Performs a deep copy
* when a Game object gets set equal to another Game object.
* Probably isn't actually needed in this program.
********************************************************************/
void Game::copy(const Game& g)
{
  this->player = g.player;
  this->num_houses = g.num_houses;
  this->houses = new House[this->num_houses];

  for (int i = 0; i < this->num_houses; i++)
  {
    this->houses[i] = g.houses[i];
  }
  this->num_a = g.num_a;
  this->a_complexes = new Apartment[this->num_a];

  for (int i = 0; i < this->num_a; i++)
  {
    this->a_complexes[i] = g.a_complexes[i];
  }
  this->num_b = g.num_b;
  this->b_complexes = new Business[this->num_b];

  for (int i = 0; i < this->num_b; i++)
  {
    this->b_complexes[i] = g.b_complexes[i];
  }
}

/********************************************************************
*                           Game::game_loop
* This is the game loop for the entire game. It repeats the game
* for each turn until the player reaches $1,000,000 or $0.
********************************************************************/
void Game::game_loop()
{
  int turn_count = 1;
  do
  {
    if(player.get_num_properties() != 0)
    {
      player.flag_vancies();
      player.collect_rent();
      player.pay_mortgages();

      if(turn_count % 12 == 0)
      {
        player.pay_taxes();
      }

      random_event();
    }

    if ((player.get_money() < 0) || (player.get_money() > 1000000))
      break;

    // money ??
    cout << "\nBank account balance: $" << player.get_money() << endl;
    //Give player option to buy, sell, or adjust rent
    turn_choice();

    turn_count++;
  } while((player.get_money() > 0) && (player.get_money() < 1000000));

  if (player.get_money() >= 1000000)
  {
    cout << "\nYour bank account is over $1,000,000. You won!!!" << endl;
    cout << "\nYou won!!!" << endl;
    cout << "\nYou won!!!" << endl;
    cout << "\nYou won!!!" << endl;
  }
  else if (player.get_money() <= 0)
  {
    cout << "You went bankrupt. You lost :(" << endl;
    cout << ":(\n:(\n:(" << endl;
  }
}

/********************************************************************
*                           Game::random_event
* Creates a random number between 1 and 6 that chooses which random
* event will happen each turn.
********************************************************************/
void Game::random_event()
{
  int random_event = rand() % (6 -1) + 1;

  switch(random_event)
  {
    case 1: player.hurricane();//hurricane in the SE. properties down 50%
            break;
    case 2: player.tornado();//tornado in the Midwest. properties down 30%
            break;
    case 3: player.earthquake();//earthquake in the NW. down 10%
            break;
    case 4: player.wildfire();//wildfire in the SW. down 25%
            break;
    case 5: player.stock_market_crash();//stock market crash. all down 30%
            break;
    case 6: player.gentrification();//gentrification. all up 20%
            break;
  }
}

/********************************************************************
*                           Game::turn_choice
* This is called by the game loop each turn and it is where the
* user interacts with the game. They can choose to either buy a
* property, sell a property, or adjust rent on a property or space in
* a Business Complex. The user's turn will repeat if they choose an
* option they can't actually do.
********************************************************************/
void Game::turn_choice()
{
  string input = "0";
  int valid_input = 0;
  bool turn_repeat = false; //repeats the turn if player selects an option
                            //they can't do.
  do
  {
    turn_repeat = false;

    cout << endl << "\nWhat would you like to do?\n" <<
      "1. Buy a property.\n" <<
      "2. Sell a property.\n" <<
      "3. Adjust rent on a property.\n" << endl;

    do
    {
      cout << "Enter a number between 1 and 3: ";
      getline(cin, input);
      valid_input = check_and_convert_input(input);

    } while (valid_input > 3 || valid_input < 1);

    switch(valid_input)
    {
      case 1: buy_property();
              break;
      case 2: if(player.has_vacant_properties())
                player.sell_property();
              else
              {
                cout << "\nYou don't have any properties for sale!" << endl;
                turn_repeat = true;
              }
              break;
      case 3: if(player.get_num_properties() > 0)
              {
                player.view_properties();
                player.adjust_rent_inputs();
              }
              else
              {
                cout << "\nYou don't have any properties!" << endl;
                turn_repeat = true;
              }
              break;
      default: break;
    }
  } while (turn_repeat == true);
}

/********************************************************************
*                           Game::buy_property
* Displays a random property from each of the game arrays for the
* player to choose from to buy. They can choose to buy either a
* house, apartment complex, or business complex.
********************************************************************/
void Game::buy_property()
{
  int h_idx = rand() % num_houses;
  int a_idx = rand() % num_a;
  int b_idx = rand() % num_b;

  string input = "0";
  int valid_input = 0;

  cout << "\nHere are some properties that you could buy:\n" << endl;

  cout << "1. House Price: " << houses[h_idx].get_value() <<
    " Mortgage: " << houses[h_idx].get_mortgage() <<
    " Location: " << houses[h_idx].get_location() << endl;

  cout << "2. Apartment Complex Price: " <<
    a_complexes[a_idx].get_value() <<
    " Mortgage: " << a_complexes[a_idx].get_mortgage() <<
    " Location: " << a_complexes[a_idx].get_location() <<
    " Units: " << a_complexes[a_idx].get_spaces() << endl;

  cout << "3. Business Complex Price: " <<
    b_complexes[b_idx].get_value() <<
    " Mortgage: " << b_complexes[b_idx].get_mortgage() <<
    " Location: " << b_complexes[b_idx].get_location() <<
    " Units: " << b_complexes[b_idx].get_spaces() << endl;

    cout << "\nWhich one would you like to buy?\n" << endl;

    do
    {
      cout << "Enter a number between 1 and 3: ";
      getline(cin, input);
      valid_input = check_and_convert_input(input);

    } while (valid_input > 3 || valid_input < 1);

    switch(valid_input)
    {
      case 1: buy_house(h_idx);
              break;
      case 2: buy_a_complex(a_idx);
              break;
      case 3: buy_b_complex(b_idx);
              break;
      default: break;
    }
}

/********************************************************************
*                           Game::buy_house
* The house that the player chose to buy in the buy_property function
* is added to the player's array of properties and a new house is
* generated into the same location in the array for the game.
********************************************************************/
void Game::buy_house(int h_idx)
{
  player.add_property(houses[h_idx]); // [NOTE] need to fix inheritance with Property being "private"
  houses[h_idx] = House(); //generate new property into game array
  cout << "\nCongratulations on purchasing the house!\n" << endl;
}

/********************************************************************
*                           Game::buy_a_complex
* The apartment complex that the player chose to buy in the buy_property
* function is added to the player's array of properties and a new
* apartment complex is generated into the same location in the array
* for the game.
********************************************************************/
void Game::buy_a_complex(int a_idx)
{
  player.add_property(a_complexes[a_idx]);  // [NOTE] need to fix inheritance with Property being "private"
  a_complexes[a_idx] = Apartment();
    cout << "\nCongratulations on purchasing the apartment complex!\n" <<
      endl;
}

/********************************************************************
*                           Game::buy_b_complex
* The business complex that the player chose to buy in the buy_property
* function is added to the player's array of properties and a new
* business complex is generated into the same location in the array
* for the game.
********************************************************************/
void Game::buy_b_complex(int b_idx)
{
  player.add_property(b_complexes[b_idx]); // [NOTE] need to fix inheritance with Property being "private"
  b_complexes[b_idx] = Business(); //generate new property into game array
    cout << "\nCongratulations on purchasing the business complex!\n" <<
      endl;
}
