#pragma once

#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <chrono>
#include <ctime>

#include "TransactionTypes.h"

class Transaction
{
public:

private:
    int transactionId;
    TransactionType type;
    double amount;
    int fromAccountID;
    int toAccountID;
    std::chrono::system_clock::time_point date; 
};

#endif