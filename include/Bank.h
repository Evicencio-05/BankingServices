#ifndef BANK_H
#define BANK_H

#include <unordered_map>
#include <iostream>
#include <ctime>

#include <User.h>
#include <Account.h>
#include <Transactions.h>

class Bank 
{
private:

public:
    std::unordered_map<int, User> users;
    std::unordered_map<int, Account> accounts;
    std::unordered_map<int, Transaction> transactions;
    int nextUserID;
    int nextAccountID;
    int nextTransactionID;

};

#endif
