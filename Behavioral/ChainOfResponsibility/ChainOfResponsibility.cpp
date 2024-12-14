#include <iostream>

class ATMHandler {
public: 
    ATMHandler (ATMHandler* obj = nullptr) {
        nextHandler = obj;
    }
    virtual void handleRequest(int amount) {
        if(nextHandler) {
            nextHandler->handleRequest(amount);
        }
    }

protected:
    ATMHandler* nextHandler;
};

class TenThousandDramHandler : public ATMHandler {
public:
    TenThousandDramHandler(ATMHandler* obj = nullptr) : ATMHandler(obj) {}
    void handleRequest (int amount) override {
        int numberOfBanknotes = amount / 10000;
        int remainingBanknotes = amount % 10000;
        if (numberOfBanknotes > 0) {
            std::cout << "Number of Ten thousand banknotes:  " << numberOfBanknotes << std::endl;
        }

        if (remainingBanknotes == 0) {
            std::cout << "Request is completed !" << std::endl;
            
        }
        else {
            ATMHandler::handleRequest(remainingBanknotes);
        }
    }
};

class FiveThousandDramHandler : public ATMHandler {
public:
    FiveThousandDramHandler(ATMHandler* obj = nullptr) : ATMHandler(obj) {}
    void handleRequest (int amount) override {
        int numberOfBanknotes = amount / 5000;
        int remainingBanknotes = amount % 5000;
        if (numberOfBanknotes > 0) {
            std::cout << "Number of Five thousand banknotes:  " << numberOfBanknotes << std::endl;
        }

        if (remainingBanknotes == 0) {
            std::cout << "Request is completed !" << std::endl;
            
        }
        else {
            ATMHandler::handleRequest(remainingBanknotes);
        }
    }
};

class OneThousandDramHandler : public ATMHandler {
public:
    OneThousandDramHandler(ATMHandler* obj = nullptr) : ATMHandler(obj) {}
    void handleRequest (int amount) override {
        int numberOfBanknotes = amount / 1000;
        int remainingBanknotes = amount % 1000;

        if (numberOfBanknotes > 0) {
            std::cout << "Number of One thousand banknotes:  " << numberOfBanknotes << std::endl;
        }

        if (remainingBanknotes == 0) {
            std::cout << "Request is completed!" << std::endl;
            
        }
        else {
            ATMHandler::handleRequest(remainingBanknotes);
        }
    }
};


int main() {
     
    ATMHandler* oneThousand = new OneThousandDramHandler; 
    ATMHandler* fiveThousand = new FiveThousandDramHandler(oneThousand);
    ATMHandler* tenThousand = new TenThousandDramHandler(fiveThousand);
    ATMHandler* atm = new ATMHandler(tenThousand);

    atm->handleRequest(17000);



    return 0;
}