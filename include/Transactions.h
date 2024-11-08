#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <chrono>
#include <ctime>
#include <string>

#include "TransactionTypes.h"

class Transaction
{
public:
    Transaction() : transactionID(0), type(TransactionType::None), 
                    amount(0.0), fromAccountID(0), toAccountID(0) 
                    {
                        date = std::chrono::system_clock::now();
                    }

    Transaction(int tranID, TransactionType tranType, double tranAmount, 
                int tranFromAccountId, int tranToAccountId, 
                std::chrono::system_clock::time_point tranDate = std::chrono::system_clock::now())
        : transactionID(tranID), type(tranType), amount(tranAmount), 
            fromAccountID(tranFromAccountId), toAccountID(tranToAccountId), date(tranDate) {}

    int getTransactionID()                      const { return transactionID; }
    TransactionType getTransactionType()        const { return type; }
    double getTransactionAmount()               const { return amount; }
    int getFromAccountID()                      const { return fromAccountID; }
    int getToAccountID()                        const { return toAccountID; }

    const std::string getTransactionDate() const;
    std::string transactionTypeToString(TransactionType type) const;

private:
    int transactionID;
    TransactionType type;
    double amount;
    int fromAccountID;
    int toAccountID;
    std::chrono::system_clock::time_point date; 
};

#endif