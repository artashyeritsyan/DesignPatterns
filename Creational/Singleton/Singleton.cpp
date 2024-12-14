#include "Singleton.hpp"

BankAccount::BankAccount() {
    std::cout << "BankAccount is created" << std::endl;
}

std::shared_ptr<BankAccount> BankAccount::getInstance() {
    if (!instance) {
        instance = std::make_shared<BankAccount>();
    }
    return instance;
}

size_t BankAccount::getBalance()
{
    std::cout << "Balance: " << balance << std::endl;
    return balance;
}

void BankAccount::withdrawMoney(size_t value) {
    if (value > balance) {
        std::cerr << "No enough money" << std::endl;
        return;
    }

    balance -= value;
}

void BankAccount::putMoney(size_t value)
{
    balance += value;
}

std::shared_ptr<BankAccount> BankAccount::instance = nullptr;
