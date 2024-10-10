#include <unordered_map>
#include <iostream>
#include <ctime>
#include <chrono>
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
    std::cout << "User created with ID: " << userID << ".\n";
    return userID;
}

int Bank::createAccount(int userID, AccountType type, AccountStatus status, double initialDeposit)
{
    int accountID = nextAccountID++;
    accounts.emplace(accountID, Account(accountID, userID, type, status, initialDeposit));
    users[userID].addAccount(accountID);
    if (initialDeposit > 0.0) {
        createTransaction(0, accountID, initialDeposit, TransactionType::Deposit);
    }
    std::cout << "Account created with ID: " << accountID << std::endl;
    return accountID;
}

int Bank::createTransaction(int fromAccountID, int toAccountID, double amount, TransactionType type)
{
    int transactionID = nextTransactionID++;
    std::chrono::system_clock::time_point currentDate = std::chrono::system_clock::now();
    transactions.emplace(transactionID, Transaction(transactionID, type, 
                                                amount, fromAccountID, toAccountID, currentDate));
    if (fromAccountID != 0) accounts[fromAccountID].addTransaction(transactionID);
    if (toAccountID != 0) accounts[toAccountID].addTransaction(transactionID);
    return transactionID;
}

User *Bank::authenticateUser(int userID, const std::string &password)
{
    auto it = users.find(userID);
    if (it != users.end() && it->second.authenticate(password)) 
    {
        return &(it->second);
    }
    return nullptr;
}

bool Bank::deposit(int accountID, double amount)
{
    auto it = accounts.find(accountID);
    if (it != accounts.end())
    {
        it->second.deposit(amount);
        createTransaction(0, accountID, amount, TransactionType::Deposit);
        std::cout << "Deposited $<< " << amount << " to account ID: "
                    << accountID << std::endl;
        return true;
    }
    return false;
}

bool Bank::withdraw(int accountID, double amount)
{
    auto it = accounts.find(accountID);
    if (it != accounts.end() && it->second.getAccountBalance() >= amount) 
    {
        it->second.withdrawal(amount);
        createTransaction(accountID, 0, amount, TransactionType::Withdrawal);
        std::cout << "Withdrew $<< " << amount << " from account ID: "
                    << accountID << std::endl;
        return true;
    }
    std::cout << "Withdrawal FAILED from Account ID: " << accountID << std::endl;
    return false;
}

bool Bank::transfer(int fromAccountID, int toAccountID, double amount)
{
    auto fromAccountIt = accounts.find(fromAccountID);
    auto toAccountIt = accounts.find(toAccountID);
    if (fromAccountIt != accounts.end() && toAccountIt != accounts.end()
        && fromAccountIt->second.getAccountBalance( )
    return false;
}

void Bank::displayUserInfo(const User &user) const
{
}

void Bank::displayTransactionHistory(int accountID) const
{
}
