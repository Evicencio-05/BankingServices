#include <unordered_map>
#include <iostream>
#include <ctime>
#include <string>

#include "Bank.h"

Bank::Bank() {
    users.reserve(10);
    accounts.reserve(100);
    transactions.reserve(1000);
}

int Bank::createUser(const std::string &username, const std::string &password)
{   
    int userID = nextUserID++;
    users.emplace(userID, User(userID, username, password));
    std::cout << "User created with ID: "
                << userID << ".\n";
}

int Bank::createAccount(int userID, AccountType type, AccountStatus status, double initialDeposit)
{
    accounts.emplace(nextAccountID, Account(nextAccountID, userID, type, status, initialDeposit));
    users[userID].addAccount(nextAccountID);
    if (initialDeposit > 0.0) {
        createTransaction(0, nextAccountID, initialDeposit, TransactionType::Deposit);
    }


    nextAccountID++;
}

int Bank::createTransaction(int fromAccountID, int toAccountID, double amount, TransactionType type)
{
    return 0;
}

User *Bank::authenticateUser(int userID, const std::string &password)
{
    return nullptr;
}

bool Bank::deposit(int accountID, double amount)
{
    return false;
}

bool Bank::withdraw(int accountID, double amount)
{
    return false;
}

bool Bank::transfer(int fromAccountID, int toAccountID, double amount)
{
    return false;
}

void Bank::displayUserInfo(const User &user) const
{
}

void Bank::displayTransactionHistory(int accountID) const
{
}