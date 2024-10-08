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

    Account myAccount(initialInvestment);

    bool done = false;
    while (!done) {
        std::cout << "What else would you like to do?"
                << "\n 1. Deposit"
                << "\n 2. Withdraw"
                << "\n 3. Clear statement"
                << "\n 4. Print statement"
                << "\n 5. Close\n";
        int nextChoice = 0;
        getCorrectType<int>(nextChoice);
        switch (nextChoice)
        {
        case 1:
            deposit(myAccount);
            break;
        case 2:
            withdraw(myAccount);
            break;
        case 3:
            myAccount.clearStatement();
            break;
        case 4:
            myAccount.printStatement();
            break;
        case 5:
            done = true;
            break;
        default:
            std::cout << "Please enter a valid number.\n" << std::endl;
            break;
        }
    }

    return 0;
}