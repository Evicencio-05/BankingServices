/*
    Main
*/

#include "Account.cpp"

#include <iostream>
#include <limits>
#include <fstream>
#include <string>

void deposit(Account& myAccount);
void withdraw(Account& myAccount);
void printStatement(Account& myAccount); 
double getDouble();

int main() {
    std::cout << "Hello lets get started with your account. What is your initial investment?" << std::endl;
    double initialInvestment = getDouble();

    Account myAccount(initialInvestment);

    bool done = false;
    while (!done) {
        std::cout << "What else would you like to do?"
                << "\n 1. Deposit"
                << "\n 2. Withdraw"
                << "\n 3. Print statement"
                << "\n 4. Close" << std::endl;
        char nextChoice;
        std::cin >> nextChoice;
        switch (nextChoice)
        {
        case 1:
            deposit(myAccount);
            break;
        case 2:
            withdraw(myAccount);
            break;
        case 3:
            printStatement(myAccount);
            break;
        case 4:
            done = true;
            break;
        default:
            std::cout << "Please enter a valid number." << std::endl;
            break;
        }
    }

    return 0;
}

void deposit(Account& myAccount) {
    std::cout << "Enter the amount you would like to deposit." << std::endl;
    myAccount.deposit(getDouble());
}

void withdraw(Account& myAccount) {
    std::cout << "Enter the amount you would like to withdraw." << std::endl;
    myAccount.withdraw(getDouble());

}

void printStatement(Account& myAccount) {
    myAccount.printStatement();
}

double getDouble() {
    double amount = 0.0;
    std::cin >> amount;
    while (!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number. (Ex. '123.45')" << std::endl;
        std::cin >> amount;
    }
    return amount;
}

void chooseOption() {

}