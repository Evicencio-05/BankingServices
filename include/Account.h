/*
    Account class
*/

#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account 
{
public:
    Account() : balance(0) {}
    Account(double newBalance);

    void deposit(double amount);
    void withdraw(double amount);

    double getBalance();
    void clearStatement();
    void printStatement();

private:
    double balance;
};

#endif