#include <stdexcept>
#include <ctime>
#include <chrono>

#include "Transactions.h"

const std::time_t& Transaction::getTransactionDate() const 
{   
    time_t readableTime = std::chrono::system_clock::to_time_t(date); 
    return readableTime; 
}

std::string Transaction::transactionTypeToString(TransactionType type) const 
{
    switch (type)
    {
        case TransactionType::Deposit: return "Deposit";
        case TransactionType::Withdrawal: return "Withdrawal";
        case TransactionType::Transfer: return "Transfer";
        default: throw std::invalid_argument("Unknown TransactionType");
    }
}

