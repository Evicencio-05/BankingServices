/*
    Main
*/

#include <iostream>
#include <string>

#include "Bank.h"
#include "helpers.h"
#include "Application.h"

int main() {
    
    Application systemBank = Application();

    systemBank.run();    

    return 0;
}