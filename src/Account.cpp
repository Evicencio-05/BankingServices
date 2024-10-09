/*
    Account src
*/

#include <iostream>
#include <fstream>
#include <string>

#include "Account.h"

void Account::deposit(double amount) { balance += amount;}
void Account::addTransaction(int transactionID) { transactionIDs.push_back(transactionID); }
bool Account::withdrawal(double amount) {
    if (balance > amount) {
        balance -= amount;
        return true;
    } 
    return false;
}