#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    string characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(string id, string n, int lvl, int hp, string weapon) : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() {
        cout << name << " attacks with " << weaponType << endl;
    }

    virtual void defend() {
        cout << name << " defends." << endl;
    }

    virtual void displayStats() {
        cout << "Character ID: " << characterID << ", Name: " << name << ", Level: " << level << ", Health Points: " << healthPoints << ", Weapon: " << weaponType << endl;
    }
};

class Warrior : public Character {
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(string id, string n, int lvl, int hp, string weapon, int armor, int damage) : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() override {
        cout << name << " performs a melee attack with " << meleeDamage << " damage." << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Armor Strength: " << armorStrength << ", Melee Damage: " << meleeDamage << endl;
    }
};

class Mage : public Character {
private:
    int manaPoints;
    int spellPower;

public:
    Mage(string id, string n, int lvl, int hp, string weapon, int mana, int spell) : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(spell) {}

    void defend() override {
        cout << name << " uses a magical barrier with " << spellPower << " power." << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Mana Points: " << manaPoints << ", Spell Power: " << spellPower << endl;
    }
};

class Archer : public Character {
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(string id, string n, int lvl, int hp, string weapon, int arrows, int accuracy) : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        cout << name << " performs a ranged attack with " << rangedAccuracy << "% accuracy." << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Arrow Count: " << arrowCount << ", Ranged Accuracy: " << rangedAccuracy << "%" << endl;
    }
};

class Rogue : public Character {
private:
    int stealthLevel;
    int agility;

public:
    Rogue(string id, string n, int lvl, int hp, string weapon, int stealth, int agi) : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agi) {}

    void displayStats() override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << ", Agility: " << agility << endl;
    }
};

int main() {
    Warrior warrior("WT001", "Tufa", 5, 100, "Sword", 50, 30);
    Mage mage("MA001", "Admist", 7, 80, "Staff", 100, 40);
    Archer archer("AF001", "Destire", 6, 70, "Bow", 50, 90);
    Rogue rogue("RA001", "Garrett", 4, 60, "Dagger", 70, 85);

    warrior.displayStats();
    warrior.attack();
    warrior.defend();

    mage.displayStats();
    mage.attack();
    mage.defend();

    archer.displayStats();
    archer.attack();
    archer.defend();

    rogue.displayStats();
    rogue.attack();
    rogue.defend();

    return 0;
}