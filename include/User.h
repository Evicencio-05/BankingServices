#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User 
{
public:
    User() : ID(0), username("John Doe"), password("Password") {} 
    User(int newId, std::string newUsername, std::string newPassword) 
        : ID(newId), username(newUsername), password(newPassword) {} 

    inline int getUserID()                          const { return ID; }
    inline std::string getUsername()                const { return username; }
    inline const std::vector<int>& getAccountIDs()  const { return accountIDs; }

    bool authenticate(const std::string& password);
    bool changePassword(const std::string& oldPassword, const std::string& newPassword);
    bool addAccount(int accountID);

private:
    int ID;
    std::string username;
    std::string password;
    std::vector<int> accountIDs;
};


#endif