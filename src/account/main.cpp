/*
    Main
*/

#include "Account.cpp"

#include <iostream>
#include <fstream>

int main() {
    

    Account myAccount = Account(100);
    myAccount.deposit(200);
    myAccount.withdraw(50);
    myAccount.printStatement();
    remove("statement.txt");

    return 0;
}