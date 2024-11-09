#ifndef SYSTEMBANK_H
#define SYSTEMBANK_H

#include "Bank.h"

class SystemBank
{
public:
    SystemBank() {}

    void run();
    void createUser();
    void login();
    void userLoop(const User& user);
    
    void deposit(int userID);
    void withdrawal(int userID);
    void transfer(int userID);
    void createAccount(int userID);

private:
    Bank systemBank;
    const int MAX_LOGIN_ATTEMPTS = 5;
};

#endif