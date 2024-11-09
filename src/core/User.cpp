#include "User.h"

#include <string>

bool User::authenticate(const std::string &password)
{
    return password == this->password;
}

bool User::changePassword(const std::string& oldPassword, 
                            const std::string& newPassword)
{
    if (authenticate(oldPassword))
    {
        password = newPassword;
        return true;
    }
    return false;
}

bool User::addAccount(int accountID)
{
    return false;
}
