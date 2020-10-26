//
// Created by Kyle Brown on 10/23/20.
//

#include "utilities.h"
#include <sstream>
#include <iostream>

using namespace std;

// Works as a parse int
int check_and_convert_input(std::string& input) {
    int number;
    istringstream iss(input);

    // Valid parsed int
    if(iss >> number) {
        return number;
    }

    cout << "invalid input, not an integer" << endl;
    return -1;
}