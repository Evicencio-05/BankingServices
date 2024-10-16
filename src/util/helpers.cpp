#include "Account.h"

#include <iostream>
#include <limits>
#include <sstream>
#include <type_traits>
#include <string>

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
