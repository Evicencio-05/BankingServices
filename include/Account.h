/*
    Account class
*/
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

#include "AccountTypes.h"

class Account 
{
public:
    Account() : accountID(0), userID(0), type(AccountType::Checking),
                status(AccountStatus::Active), balance(0.0) {}
    Account(int newAccountID, int creatorUserID, AccountType newType = AccountType::Checking, 
            AccountStatus newStatus = AccountStatus::Active, double initialBalance = 0.0) 
            : accountID(newAccountID), userID(creatorUserID), type(newType), 
            status(newStatus), balance(initialBalance) {
                transactionIDs.reserve(20);
            }            

    int getAccountID()                           const { return accountID; }
    int getUserID()                              const { return userID; }
    AccountType getAccountType()                 const { return type; }
    AccountStatus getAccountStatus()             const { return status; }
    double getAccountBalance()                   const { return balance; }
    const std::vector<int>& getAccountHistory()  const { return transactionIDs; }

    void setType(AccountType newType) { type = newType; }
    void setStatus(AccountStatus newStatus) { status = newStatus; }

    void deposit(double amount);
    bool withdrawal(double amount);
    void addTransaction(int transactionID);

    std::string accountTypeToString(AccountType type) const;
    std::string accountStatusToString(AccountStatus status) const;

private:
    int accountID;
    int userID;
    AccountType type;
    AccountStatus status;
    double balance;
    std::vector<int> transactionIDs;
};

#endif