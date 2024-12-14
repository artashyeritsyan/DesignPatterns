#include <iostream>
#include <vector>

class Warrior {
public:
    virtual Warrior* clone() const = 0;
    virtual void showSkill() const = 0;
    // virtual ~Warrior() = default;
    void setSkill(const std::string& skill) {
        this->skill = skill;
    }
    
protected:
    std::string skill;
};

class Swordsman : public Warrior {
public:
    Swordsman(const std::string& skill) : skill(skill) {}
    Swordsman(const Swordsman& other) : skill(other.skill) {}

    Warrior* clone() const override {
        return new Swordsman(*this);
    }

    void showSkill() const override {
        std::cout << "class Swordsman, skill: " << skill << std::endl;
    }

private:
    std::string skill;
};

class Archer : public Warrior {
public:
    Archer(const std::string& skill) : skill(skill) {}
    Archer(const Archer& other) : skill(other.skill) {}

    Warrior* clone() const override {
        return new Archer(*this);
    }

    void showSkill() const override {
        std::cout << "class Archer, skill: " << skill << std::endl;
    }

private:
    std::string skill;
};

class Mage : public Warrior {
public:
    Mage(const std::string& skill) : skill(skill) {}
    Mage(const Mage& other) : skill(other.skill) {}

    Warrior* clone() const override {
        return new Mage(*this);
    }

    void showSkill() const override {
        std::cout << "class Mage, skill: " << skill << std::endl;
    }

private:
    std::string skill;
};

class Army {
public:
    void addWarrior(Warrior* warrior) {
        warriors.push_back(warrior);
    }

    void removeWarrior(int index) {
        if (index >= 0 && index < warriors.size()) {
            warriors.erase(warriors.begin() + index);
        } 
    }

    void showWarriorsSkills() {
        for(int i = 0; i < warriors.size(); i++) {
            warriors[i]->showSkill();
        }
    }

private:
    std::vector<Warrior*> warriors;
};

int main() {

    Warrior* wr1 = new Swordsman("Berserk");
    Warrior* wr2 = new Archer("MultiShot");
    Warrior* wr3 = new Mage("Fireball");

    Army* army = new Army;
    army->addWarrior(wr1);
    army->addWarrior(wr2);
    army->addWarrior(wr3);
    army->showWarriorsSkills();

    std::cout << "------" << std::endl;

    Warrior* wr1Clone = wr1->clone();
    Warrior* wr2Clone = wr2->clone();

    army->addWarrior(wr1Clone);
    army->addWarrior(wr2Clone);
    army->showWarriorsSkills();





    return 0;
}

