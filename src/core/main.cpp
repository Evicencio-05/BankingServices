/*
    Main
*/

#include <iostream>
#include <string>

#include "Bank.h"
#include "helpers.h"
#include "SystemBank.h"

int main() {
    
    SystemBank systemBank = SystemBank();

    systemBank.run();    

    return 0;
}