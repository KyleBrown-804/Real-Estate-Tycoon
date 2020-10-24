//
// Created by Kyle Brown on 10/23/20.
//

#include "utilities.h"
#include <sstream>
#include <iostream>

using namespace std;

// Basically works as a parse int
int check_and_convert_input(std::string& input) {
    int choice;
    istringstream iss(input);

    // Valid parsed int
    if(iss >> choice) {

        if(choice <= 3 && choice >= 1) {
            return choice;
        }
    }

    cout << "invalid input" << endl;
    return -1;
}


