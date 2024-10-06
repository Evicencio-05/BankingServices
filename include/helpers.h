#pragma once

#ifndef HELPERS_H
#define HELPERS_H

#include "Account.h"

void printStatement(Account& myAccount);
void withdraw(Account& myAccount);
void deposit(Account& myAccount);

template <typename T>
T getCorrectType(T correctType);

#endif