#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <chrono>
#include <ctime>

#include "TransactionTypes.h"

class Transaction
{
public:
    Transaction() : transactionID(0), type(TransactionType::None), 
                    amount(0.0), fromAccountID(0), toAccountID(0) {
                        date = std::chrono::system_clock::now();
                    }
    Transaction(int tranID, TransactionType tranType, double tranAmount, 
                int tranFromAccountId, int tranToAccountId, 
                std::chrono::system_clock::time_point tranDate = std::chrono::system_clock::now())
        : transactionID(tranID), type(tranType), amount(tranAmount), 
            fromAccountID(tranFromAccountId), toAccountID(tranToAccountId), date(tranDate) {}

    inline int getTransactionID()               const { return transactionID; }
    inline TransactionType getTransactionType() const { return type; }
    inline double getTransactionAmount()        const { return amount; }
    inline int getFromAccountID()               const { return fromAccountID; }
    inline int getToAccountID()                 const { return toAccountID; }
    inline std::time_t getTransactionDate()     const { return std::chrono::system_clock::to_time_t(date); }

private:
    int transactionID;
    TransactionType type;
    double amount;
    int fromAccountID;
    int toAccountID;
    std::chrono::system_clock::time_point date; 
};

#endif