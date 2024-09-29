/*
    Account src
*/

#include "Account.h"

#include <iostream>
#include <fstream>
#include <string>

Account::Account(int newBalance) : balance(newBalance) {}

void Account::deposit(int amount) 
{
    std::ofstream statementSheet("statement.txt", std::ios_base::app);
    if (statementSheet.is_open()) {
        statementSheet << "Beginning balance: " << balance << "\n";
        balance += amount;
        statementSheet << "Ending balance: " << balance << "\n";

        statementSheet.close();
    } else {
        std::cerr << "Balance sheet could not open. Error code 1.";
    }
}

void Account::withdraw(int amount) 
{   
    std::ofstream statementSheet("statement.txt", std::ios_base::app);
    if (statementSheet.is_open()) {
        statementSheet << "Beginning balance: " << balance << "\n";
        balance -= amount;
        statementSheet << "Ending balance: " << balance << "\n";

        statementSheet.close();
    } else {
        std::cerr << "Balance sheet could not open. Error code 2.";
    }
}

int Account::getBalance() 
{
    return balance;
}

void Account::printStatement() 
{
    std::ifstream statementSheet("statement.txt");
    if (statementSheet.good()) {
        std::string line;
        while(std::getline(statementSheet, line)) {
            std::cout << line << std::endl;
        }
        statementSheet.close();
    } else {
        std::cerr << "Statement sheet could not be retrieved. Error code 3.";
    }
}