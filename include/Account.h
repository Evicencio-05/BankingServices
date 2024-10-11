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

    inline int getAccountID()                           const { return accountID; }
    inline int getUserID()                              const { return userID; }
    inline AccountType getAccountType()                 const { return type; }
    inline AccountStatus getAccountStatus()             const { return status; }
    inline double getAccountBalance()                   const { return balance; }
    inline const std::vector<int>& getAccountHistory()  const { return transactionIDs; }

    inline void setType(AccountType newType) { type = newType; }
    inline void setStatus(AccountStatus newStatus) { status = newStatus; }

    inline bool deposit(double amount);
    inline bool withdrawal(double amount);
    inline bool addTransaction(int transactionID);

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