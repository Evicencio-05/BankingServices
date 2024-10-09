#pragma once

#ifndef ACCOUNTTYPES_H
#define ACCOUNTTYPES_H

enum class AccountType {
    Checking, 
    Savings
};

enum class AccountStatus {
    Active,
    Suspended,
    Closed
};

#endif