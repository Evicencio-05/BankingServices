#ifndef HELPERS_H
#define HELPERS_H

#include "Account.h"

void withdraw(Account& myAccount);
void deposit(Account& myAccount);

template <typename T>
T getCorrectType(T& paramToMatch);

#endif