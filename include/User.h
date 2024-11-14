#ifndef USER_H
#define USER_H

#include <string>
#include <array>

class User 
{
public:
    User() : ID(0), username("John Doe"), password("Password"), numOfAccounts(0) {} 
    User(int newId, std::string newUsername, std::string newPassword) 
        : ID(newId), username(newUsername), password(newPassword), numOfAccounts(0) {} 

    int getUserID()                          const { return ID; }
    std::string getUsername()                const { return username; }
    const std::array& getAccountIDs()  const { return accountIDs; }

    bool authenticate(const std::string& password);
    bool changePassword(const std::string& oldPassword, const std::string& newPassword);
    bool addAccount(int accountID);

private:
    int ID;
    static const int MAX_ACCOUNTS = 5;
    int numOfAccounts;
    std::string username;
    std::string password;
    std::array<int, MAX_ACCOUNTS> accountIDs;
};


#endif