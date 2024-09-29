/*
    Account class
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account 
{
public:
    Account() : balance(0) {}
    Account(int newBalance);

    void deposit(int amount);
    void withdraw(int amount);

    int getBalance();
    void printStatement();

private:
    int balance;
};

#endif