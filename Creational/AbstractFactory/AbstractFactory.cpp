#include <iostream>

class Chocolate {
public:
    Chocolate(float ing1, float ing2) : ingredient1(ing1), ingredient2(ing2) {}

    void print() const {
        std::cout << "Ingredients in sizes " << ingredient1 << " and " << ingredient2 << " were used to create the chocolate." << std::endl;
    }

private:
    float ingredient1;
    float ingredient2;
};

class ChocolateFactory {
public:
    virtual ~ChocolateFactory() = default;

    virtual Chocolate createChocolate(float mainIngredient, float cacao) const = 0;
};

class WhiteChocolateFactory : public ChocolateFactory {
public:
    Chocolate createChocolate(float milk, float cacao) const override {
        std::cout << "Created White chocolate" << std::endl;
        return Chocolate(milk * 100, cacao * 20);
    }
};

class DarkChocolateFactory : public ChocolateFactory {
public:
    Chocolate createChocolate(float coffee, float cacao) const override {
        std::cout << "Created Dark chocolate" << std::endl;
        return Chocolate(coffee * 60, cacao * 20);
    }
};

int main() {
    ChocolateFactory* whiteFactory = new WhiteChocolateFactory;
    Chocolate whiteChoco = whiteFactory->createChocolate(5, 5);
    whiteChoco.print();

    ChocolateFactory* darkFactory = new DarkChocolateFactory;
    Chocolate darkChoco = darkFactory->createChocolate(5, 5);
    darkChoco.print();

    return 0;
}
