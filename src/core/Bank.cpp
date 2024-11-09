#include <unordered_map>
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include <utility>

#include "Bank.h"

int Bank::createUser(const std::string& username, const std::string &password)
{   
    int userID = nextUserID++;
    users.emplace(username, User(userID, username, password));
    std::cout << "User created with ID: " << userID << ".\n";
    return userID;
}

int Bank::createAccount(std::string& username, AccountType type, AccountStatus status, double initialDeposit)
{
    int accountID = nextAccountID++;
    User& user = users[username];
    int userID = user.getUserID();
    accounts.emplace(accountID, Account(accountID, userID, type, status, initialDeposit));
    user.addAccount(accountID);
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
    transactions.emplace(transactionID, 
                        Transaction(transactionID, type, 
                                    amount, fromAccountID, 
                                    toAccountID, currentDate));
    if (fromAccountID != 0) accounts[fromAccountID].addTransaction(transactionID);
    if (toAccountID != 0) accounts[toAccountID].addTransaction(transactionID);
    return transactionID;
}

User* Bank::authenticateUser(std::string& username, const std::string &password)
{
    auto it = users.find(username);
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
    if (it != accounts.end() && it->second.withdrawal(amount)) 
    {
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
        && fromAccountIt->second.withdrawal(amount))  
    {
        toAccountIt->second.deposit(amount);
        createTransaction(fromAccountID, toAccountID, amount, TransactionType::Transfer);
        std::cout << "Transfer of $" << amount << "\nFrom account ID " << fromAccountID
                    << "\nTo account ID: " << toAccountID << std::endl; 
        return true;
    }
    std::cout << "**FAILED**\nTransfer of $" << amount << "\nFrom account ID " << fromAccountID
                << "\nTo account ID: " << toAccountID << std::endl; 
    return false;
}

void Bank::displayUserInfo(const User &user) const
{
    std::cout << "User ID: " << user.getUserID() 
                << "\n\tName: " << user.getUsername()
                << "\n\tAccounts: " << std::endl;
    for (int accountID : user.getAccountIDs())
    {
        auto it = accounts.find(accountID);
        if (it != accounts.end())
        {
            std::cout << "\tAccount ID: " << it->second.getAccountID()
                        << "\t\tType: " << it->second.accountTypeToString(it->second.getAccountType())
                        << "\t\tBalance: " << it->second.getAccountBalance()
                        << "\t\tActive: " << it->second.accountStatusToString(it->second.getAccountStatus())
                        << std::endl; 
        }
    }
}

void Bank::displayTransactionHistory(int accountID) const
{
    auto it = accounts.find(accountID);
    if (it != accounts.end()) 
    {
        std::cout << "Transaction history for account ID: " << accountID;
        for (int transactionID : it->second.getAccountHistory())
        {
            auto transactionIt = transactions.find(transactionID);
            if (transactionIt != transactions.end())
            {
                const Transaction& transaction = transactionIt->second;
                std::cout << "\n\tTransaction ID: " << transaction.getTransactionID()
                            << "\t\tType: " << transaction.transactionTypeToString(transaction.getTransactionType())
                            << "\t\tAmount: " << transaction.getTransactionAmount()
                            << "\t\tDate: " << transaction.getTransactionDate()
                            << std::endl;
            }
        }
    }
}
