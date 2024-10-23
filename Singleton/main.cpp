#include "Singleton.hpp"

int main() {
    auto account = BankAccount::getInstance();
    
    account->getBalance();
    
    account->putMoney(10000);
    account->getBalance();

    account->withdrawMoney(50000);
    account->withdrawMoney(3000);
    account->getBalance();

    
    return 0;
}

