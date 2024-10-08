#include "Account.h"
#include "helpers.h"

#include <iostream>
#include <limits>
#include <sstream>
#include <type_traits>
#include <string>


void deposit(Account& myAccount) {
    std::cout << "Enter the amount you would like to deposit.\n" << std::endl;
    double deposit = 0.0;
    myAccount.deposit(getCorrectType(deposit));
}

void withdraw(Account& myAccount) {
    std::cout << "Enter the amount you would like to withdraw.\n" << std::endl;
    double withdraw = 0.0;
    myAccount.withdraw(getCorrectType(withdraw));
}

template <typename T>
T getCorrectType(T& paramToMatch) {
    std::cin >> paramToMatch;
    while (std::cin.fail())
    {
        std::cerr << "**Input failure**\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please input a valid " << typeid(T).name() << ".\n";
        std::cin >> paramToMatch;
    }
    return paramToMatch;
}
