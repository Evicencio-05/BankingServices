#ifndef SYSTEM_H
#define SYSTEM_H



#include "Bank.h"

class System
{
public:
    System() {}

    void run();
    void createUser();
    void login();
    
    void createAccount();
    void deposit()
    void createTransaction();

private:
    Bank systemBank;
    bool exit;
};

#endif