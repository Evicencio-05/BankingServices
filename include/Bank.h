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
public:
    Bank() : nextUserID(1), 
        nextAccountID(10001), 
        nextTransactionID(1000001) 
    {
        users.reserve(10);
        accounts.reserve(100);
        transactions.reserve(1000);
    }

    int createUser(const std::string& username, const std::string& password);
    int createAccount(std::string& username, AccountType type, 
                        AccountStatus status = AccountStatus::Active, 
                        double initialDeposit = 0.0);
    int createTransaction(int fromAccountID, 
                            int toAccountID, 
                            double amount, 
                            TransactionType type);

    User* authenticateUser(std::string& username, const std::string& password);

    bool deposit(int accountID, double amount);
    bool withdraw(int accountID, double amount);
    bool transfer(int fromAccountID, int toAccountID, double amount);

    void displayUserInfo(const User& user) const;
    void displayTransactionHistory(int accountID) const;

private:
    std::unordered_map<std::string, User> users;
    std::unordered_map<int, Account> accounts;
    std::unordered_map<int, Transaction> transactions;
    int nextUserID;
    int nextAccountID;
    int nextTransactionID;
};

#endif
