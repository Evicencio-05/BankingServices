#ifndef SYSTEMBANK_H
#define SYSTEMBANK_H

#include "Bank.h"

class SystemBank
{
public:
    SystemBank() : exit(false) {}

    void run();
    void createUser();
    void login();
    
    void createAccount();
    void deposit();
    void createTransaction();

private:
    Bank systemBank;
    bool exit;
};

#endif