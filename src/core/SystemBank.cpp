/*
    System functions for the bank
*/

#include <iostream>
#include <string>

#include "Bank.h"
#include "helpers.h"
#include "SystemBank.h"

void SystemBank::run()
{
    std::cout << "Hello! Welcom to the bank. What would you like to do today?\n"
                << "1. Create a new user\n"
                << "2. Login\n"
                << "3. Exit\n";
    int choice = 0;
    std::cin >> choice;
    while(!exit)
    {
        switch (choice)
        {
            case 1: 
                createUser();
                break;
            case 2:
                login();
                break;
            case 3:
                exit = true;
                break;
            default:
                std::cerr << "Invalid input. Please enter a number (1-3).\n";
                std::cin >> choice;
                break;
        }
    }
}

void SystemBank::createUser()
{
    std::cout << "Enter your name.\n";
    std::string name;
    std::cin >> name;

    std::cout << "Enter your password.\n";
    std::string password;
    std::cin >> password;


    std::cout << "Re-enter your password.\n";
    std::string verifyPassword;
    std::cin >> verifyPassword;

    while (password != verifyPassword) 
    {
        std::cerr << "Passwords do not match. Please enter again.\n";   
        
        std::cout << "Enter your password.\n";
        std::cin >> password;

        std::cout << "Re-enter your password.\n";
        std::cin >> verifyPassword;
    }

    systemBank.createUser(name, password);
}

void SystemBank::login()
{
    std::cout << "Enter your username\n";
    std::string username;
    std::cin >> username;

    std::cout << "Enter your password\n";
    std::string password;
    std::cin >> password;

    systemBank.authenticateUser(username, password);
}

void SystemBank::createAccount()
{
}

void SystemBank::deposit()
{
}

void SystemBank::createTransaction()
{
}
