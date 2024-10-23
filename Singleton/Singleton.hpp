#pragma once

#include <iostream>
#include <memory>

class BankAccount {
private:
    BankAccount();

    BankAccount(const BankAccount&) = delete;
    BankAccount& operator=(const BankAccount&) = delete;

    static std::shared_ptr<BankAccount> instance;

    size_t balance;  
public:
    static std::shared_ptr<BankAccount> getInstance();

    size_t getBalance();
    void withdrawMoney(size_t value);
    void putMoney(size_t value);

};