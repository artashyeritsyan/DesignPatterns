#include <iostream>
#include <string>

class Soldier {
public:
    virtual std::string getWeapons() const {
        return "Knife";
    }
    virtual ~Soldier() = default;
};

class WeaponDecorator : public Soldier {
protected:
    Soldier* soldier_;
public:
    WeaponDecorator(Soldier* soldier) : soldier_(soldier) {}
    virtual std::string getWeapons() const override {
        return soldier_->getWeapons();
    }
};

class PistolDecorator : public WeaponDecorator {
    int ammoCount_;
public:
    PistolDecorator(Soldier* soldier, int ammoCount) 
        : WeaponDecorator(soldier), ammoCount_(ammoCount) {}

    std::string getWeapons() const override {
        return soldier_->getWeapons() + ", Pistol (Ammo: " + std::to_string(ammoCount_) + ")";
    }
};

class GunDecorator : public WeaponDecorator {
    int ammoCount_;
public:
    GunDecorator(Soldier* soldier, int ammoCount)
        : WeaponDecorator(soldier), ammoCount_(ammoCount) {}

    std::string getWeapons() const override {
        return soldier_->getWeapons() + ", Gun (Ammo: " + std::to_string(ammoCount_) + ")";
    }
};

class GrenadeDecorator : public WeaponDecorator {
    std::string grenadeType_;
public:
    GrenadeDecorator(Soldier* soldier, const std::string& grenadeType) 
        : WeaponDecorator(soldier), grenadeType_(grenadeType) {}

    std::string getWeapons() const override {
        return soldier_->getWeapons() + ", Grenade (" + grenadeType_ + ")";
    }
};

int main() {
    Soldier* soldier = new Soldier();
    std::cout << "Soldier Weapons: " << soldier->getWeapons() << std::endl;

    Soldier* soldierWithPistol = new PistolDecorator(soldier, 15);
    std::cout << "Soldier with Pistol: " << soldierWithPistol->getWeapons() << std::endl;

    Soldier* soldierWithGun = new GunDecorator(soldierWithPistol, 30);
    std::cout << "Soldier with Pistol and Gun: " << soldierWithGun->getWeapons() << std::endl;

    Soldier* fullyArmedSoldier = new GrenadeDecorator(soldierWithGun, "Flash");
    std::cout << "Fully Armed Soldier: " << fullyArmedSoldier->getWeapons() << std::endl;

    return 0;
}
