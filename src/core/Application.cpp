/*
    System functions for the bank
*/

#include <iostream>
#include <string>

#include "Bank.h"
#include "helpers.h"
#include "Application.h"

void Application::run()
{
    std::cout << "Hello! Welcome to the bank. " 
                << "What would you like to do today?\n"
                << "1. Create a new user\n"
                << "2. Login\n"
                << "3. Exit\n";
    int choice = 0;
    std::cin >> choice;

    bool exit = false;

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

    std::cout << "Goodbye!\n";
}

void Application::createUser()
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
    application.createUser(name, password);
    login(name, password);
}

void Application::login()
{
    User* user = nullptr;
    int attempts = 0;
    while (user == nullptr && attempts > MAX_LOGIN_ATTEMPTS) 
    {
        attempts++;
        std::cout << "Enter your username\n";
        std::string username;
        std::cin >> username;

        std::cout << "Enter your password\n";
        std::string password;
        std::cin >> password;

        user = application.authenticateUser(username, password);
        if (user == nullptr)
        {
            std::cerr << "Authentification failed. You have "
                        << MAX_LOGIN_ATTEMPTS - attempts 
                        << " attempts left.\n";
        }
    }

    if (user != nullptr)
    {
        userLoop(*user);
    
        delete user;
        user = nullptr;
    }
}

void Application::login(const std::string& username, const std::string& password)
{

    User* user = application.authenticateUser(username, password);
    if (user == nullptr)
    {
        std::cerr << "Application error!\n"
                    << "*User not created.*\n";
    } 
    else 
    {
        userLoop(*user);
        
        delete user;
        user = nullptr;
    }
}

void Application::userLoop(const User& user)
{   
    bool exit = false;

    std::cout << "What would you like to do?\n"
            << "1. Deposit\n"
            << "2. Withdrawal\n"
            << "3. Transfer\n"
            << "4. View Statement\n"
            << "5. Open Account\n"
            << "6. Exit\n";
    int choice = 0;
    std::cin >> choice;

    int userID = user.getUserID();
    
    while (!exit)
    {
        std::cout << "What would you like to do?\n";

        switch (choice)
        {
            case 1:
                deposit(userID);
                break;
            case 2:
                withdrawal(userID);
                break;
            case 3:
                transfer(userID);
                break;
            case 4:
                application.displayTransactionHistory(userID);
                break;
            case 5:
                createAccount(userID);
                break;
            case 6:
                exit = true;
                break;
            default:
                std::cerr << "Invalid input. Please enter a number (1-5).\n";
                std::cin >> choice;
                break;
        }
    }
}


void Application::deposit(int userID)
{
    std::cout << "How much would you like to deposit?\n";
    std::string stringAmount;
    std::cin >> stringAmount;
    double amount = std::stod(stringAmount);

    application.deposit(userID, amount);
}

void Application::withdrawal(int userID)
{
    std::cout << "How much would you like to withdrawal?\n";
    std::string stringAmount;
    std::cin >> stringAmount;
    double amount = std::stod(stringAmount);
    
    bool successful = application.withdraw(userID, amount);

    if (!successful)
    {
        std::cerr << "Withdrawal not completed. Insufficient balance.\n";
    }
}

void Application::transfer(int userID)
{
    std::cout << "How much would you like to transfer?\n";
    std::string stringAmount;
    std::cin >> stringAmount;
    double amount = std::stod(stringAmount);

    std::cout << "Enter recipient username.\n";
    std::string recipientUsername;
    std::cin >> recipientUsername;

    if (application.userExists(recipientUsername))
    {
        
    }

}

void Application::createAccount(int userID)
{

}