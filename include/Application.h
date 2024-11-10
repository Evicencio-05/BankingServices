#ifndef APPLICATION_H
#define APPLICATION_H

#include "Bank.h"

#include <string>

class Application
{
public:
    Application() {}

    void run();
    void createUser();
    void login();
    void login(const std::string& username, const std::string& password);
    void userLoop(const User& user);
    
    void deposit(int userID);
    void withdrawal(int userID);
    void transfer(int userID);
    void createAccount(int userID);

private:
    Bank application;
    const int MAX_LOGIN_ATTEMPTS = 5;
};

#endif