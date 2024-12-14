#include <iostream>

class Chocolate {
public:
    Chocolate(float ing1, float ing2) : ingredient1(ing1), ingredient2(ing2) {}

    void print() const {
        std::cout << "Ingredients in sizes" << ingredient1 << " and " << ingredient2 << " were used to create the chocolate. " << std::endl;
    }

private:
    float ingredient1;
    float ingredient2;
};

class ChocolateFactory {
public:
    static Chocolate createWhiteChoco(float milk, float cacao) {
        std::cout << "Created White chocolate" << std::endl;
        return Chocolate(milk * 100, cacao * 20);
    }

    static Chocolate createDarkChoco(float coffee, float cacao) {
        std::cout << "Created Dark chocolate" << std::endl;
        return Chocolate(coffee * 60, cacao * 20);
    }
};

int main() {
    Chocolate white_choco = ChocolateFactory::createWhiteChoco(5, 5);
    white_choco.print();
    
    Chocolate dark_choco = ChocolateFactory::createDarkChoco(5, 5);
    dark_choco.print();
    
    return 0;
}
