/*
    Account src
*/

#include <iostream>
#include <fstream>
#include <string>

#include "Account.h"

bool Account::deposit(double amount) { balance += amount;}
bool Account::addTransaction(int transactionID) { transactionIDs.push_back(transactionID); }
bool Account::withdrawal(double amount) 
{
    if (balance > amount) {
        balance -= amount;
        return true;
    } 
    return false;
}

std::string Account::accountTypeToString(AccountType type) const 
{
    switch (type) 
    {
        case AccountType::Checking: return "Checking";
        case AccountType::Savings: return "Savings";
        default: throw std::invalid_argument("Unknown AccountType");
    }
}

std::string Account::accountStatusToString(AccountStatus status)  const 
{
    switch (status) 
    {
        case AccountStatus::Active: return "Active";
        case AccountStatus::Suspended: return "Suspended";
        case AccountStatus::Closed: return "Closed";
        default: throw std::invalid_argument("Unknown AccountStatus");
    }
}