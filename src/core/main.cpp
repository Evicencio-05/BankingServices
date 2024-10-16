/*
    Main
*/

#include "Account.cpp"
#include "helpers.cpp"

#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::cout << "Hello lets get started with your account. What is your initial investment?\n";
    double initialInvestment = 0.0;
    getCorrectType<double>(initialInvestment);

    

    return 0;
}