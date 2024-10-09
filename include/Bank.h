#pragma once

#ifndef BANK_H
#define BANK_H

#include <unordered_map>
#include <iostream>
#include <ctime>
#include <string>

#include "User.h"
#include "Account.h"
#include "Transactions.h"
#include "TransactionTypes.h"

class Bank 
{
private:
    Bank() : nextUserID(1), nextAccountID(10001), nextTransactionID(1000001) {}

    int createUser(const std::string& username, const std::string& password);
    int createAccount(int userID, TransactionType type, double initialDeposit = 0.0);
    int createTransaction
    User* authenticateUser(int userID, const std::string& password);


public:
    std::unordered_map<int, User> users;
    std::unordered_map<int, Account> accounts;
    std::unordered_map<int, Transaction> transactions;
    int nextUserID;
    int nextAccountID;
    int nextTransactionID;
};

#endif
