#include <iostream>
#include <string>

class Burger{
public: 
	void set_meat(int meat) {
        std::cout<<"set meat"<<std::endl;
        m_meat = meat;
	}
	void set_bread(int bread) {
        std::cout<<"set bread"<<std::endl;
        m_bread = bread;
	}
	void set_tomato(int tomato) {
        std::cout<<"set tomato"<<std::endl;
        m_tomato = tomato;
	}	
	void set_cheese(int cheese) {
        std::cout<<"set cheese"<<std::endl;
        m_cheese = cheese;
	}
	void display() {
	    std::cout<<"burger is ready!"<<std::endl;

        std::cout << "Bread: " << m_bread << std::endl;
        std::cout << "Tomato: " << m_tomato << std::endl;
        std::cout << "Cheese: " << m_cheese << std::endl;
        std::cout << "Meat: " << m_meat << std::endl;
	}

private: 
	int m_bread;
	int m_tomato;
	int m_cheese;
	int m_meat;
};

class Builder {
public: 
    virtual void put_bread() = 0;
    virtual void put_tomato() = 0;
    virtual void put_meat() = 0;
    virtual void put_cheese() = 0;
    virtual Burger get_burger() = 0;
};

class ChickenBurgerBuilder:public Builder{
public: 
	void put_bread(){
	   burger.set_bread(2);
	}
	void put_tomato(){
	   burger.set_tomato(2);
	}
	void put_meat(){
	   burger.set_meat(2);
	}
	void put_cheese(){
		burger.set_cheese(0);
	}
	Burger get_burger(){
	   return burger;
	}

private: 
	Burger burger;
};		

class CheeseBurgerBuilder:public Builder{
public: 
	void put_bread() {
	   burger.set_bread(2);
	}
	void put_tomato() {
		burger.set_tomato(0);
	}
	void put_meat() {
	   burger.set_meat(3);
	}
	void put_cheese() {
	   burger.set_cheese(3);
	}

	Burger get_burger() {
	   return burger;
	}

private: 
	Burger burger;
};	

class BurgerMaker{
public: 	 
	void make_burger() {
	    burger_builder->put_bread();
        burger_builder->put_tomato();
        burger_builder->put_meat();
        burger_builder->put_cheese();
	}

	Burger get_burger() {
        return burger_builder->get_burger();
	}

	void set_burger_builder(Builder * builder) {
	    burger_builder = builder;
	}
private:	 
	Builder* burger_builder;
};

int main(){
    BurgerMaker maker;
    
    CheeseBurgerBuilder cheese_builder;
    maker.set_burger_builder(&cheese_builder);
    maker.make_burger();
    Burger chickenBurger = maker.get_burger();


    ChickenBurgerBuilder ham_builder;
    maker.set_burger_builder(&ham_builder);
    maker.make_burger();

    Burger burger = maker.get_burger();

    chickenBurger.display();
    std::cout << "________________" << std::endl;
    burger.display();
    
    return 0;
}