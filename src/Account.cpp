/*
    Account src
*/

#include "Account.h"

#include <iostream>
#include <fstream>
#include <string>

Account::Account(double newBalance) : balance(newBalance) {}

void Account::deposit(double amount) 
{
    std::ofstream statementSheet("statement.txt", std::ios_base::app);
    if (statementSheet.is_open()) {
        statementSheet << "Beginning balance: " << balance << "\t";
        balance += amount;
        statementSheet << "Ending balance: " << balance << "\n";

        statementSheet.close();
    } else {
        std::cerr << "Balance sheet could not open. Error code 1.";
    }
}

void Account::withdraw(double amount) 
{   
    std::ofstream statementSheet("statement.txt", std::ios_base::app);
    if (statementSheet.is_open()) {
        statementSheet << "Beginning balance: " << balance << "\t";
        balance -= amount;
        statementSheet << "Ending balance: " << balance << "\n";

        statementSheet.close();
    } else {
        std::cerr << "Balance sheet could not open. Error code 2.";
    }
}

double Account::getBalance() 
{
    return balance;
}

void Account::clearStatement() {
    std:: ifstream statementSheet;
    statementSheet.open("statement.txt", std::ofstream::out | std::ofstream::app);
    statementSheet.close();
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