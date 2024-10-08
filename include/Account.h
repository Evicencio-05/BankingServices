/*
    Account class
*/

#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account 
{
public:
    Account() : balance(0) {}
    Account(double newBalance);

    void deposit(double amount);
    void withdraw(double amount);

    double getBalance();
    void clearStatement();
    void printStatement();

private:
    int accountID;
    int userID;
    std::string accountType;
    double balance;
    std::vector<int> transactionId;
};

#endif