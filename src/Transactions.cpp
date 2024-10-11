#include "Transactions.h"
#include <stdexcept>

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

