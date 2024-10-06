#include "Account.h"
#include "helpers.h"

#include <iostream>
#include <limits>
#include <sstream>
#include <type_traits>
#include <string>


void deposit(Account& myAccount) {
    std::cout << "Enter the amount you would like to deposit." << std::endl;
    double deposit = 0.0;
    myAccount.deposit(getCorrectType<double>());
}

void withdraw(Account& myAccount) {
    std::cout << "Enter the amount you would like to withdraw." << std::endl;
    double withdraw = 0.0;
    myAccount.withdraw(getCorrectType<double>());
}

void printStatement(Account& myAccount) {
    myAccount.printStatement();
}

template <typename T>
T getCorrectType() {
    T userInput;
    std::string inputLine;

    while (true) {
        std::getline(std::cin, inputLine);
        std::istringstream iss(inputLine);

        if constexpr (std::is_same_v<T, std::string>) {
            userInput = inputLine;
            break;
        } else {
            if (iss >> userInput) {
                char remainingStream;
                if(iss >> remainingStream) {
                    std::cout << "Invalid input. Please only enter a "
                            << typeid(T).name() << "." << std::endl;
                } else {
                    break;
                }
            } else {
                std::cout << "Invalid input. Please enter a valid "
                        << typeid(T).name() << "." << std::endl;
            }
        }
        std::cin.clear();
    }
    return userInput;
}