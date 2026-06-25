#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits> // Required for clearing the input buffer

using namespace std;

// 1. Abstraction & Encapsulation: Base class representing a generic character
class Character {
private:
    // Encapsulation: Private variables to hide sensitive data
    string name;
    int health;
    int attackPower;

public:
    // Constructor
    Character(string n, int hp, int ap) : name(n), health(hp), attackPower(ap) {}

    // Getter and Setter methods (Part of Encapsulation)
    string getName() const { return name; }
    int getHealth() const { return health; }
    
    void reduceHealth(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }
    
    int getAttackPower() const { return attackPower; }

    // 3. Polymorphism: Virtual function to be overridden by derived/child classes
    virtual void attack(Character& target) {
        // Generates random damage between 80% and 120% of base attack power
        int minDamage = attackPower * 0.8;
        int maxDamage = attackPower * 1.2;
        int actualDamage = minDamage + (rand() % (maxDamage - minDamage + 1));

        cout << name << " attacks " << target.getName() << " for " << actualDamage << " damage!\n";
        target.reduceHealth(actualDamage);
    }

    bool isAlive() const { return health > 0; }

    // Virtual destructor to prevent memory leaks in polymorphic inheritance
    virtual ~Character() {}
};

// 2. Inheritance: Hero child class derived from Character base class
class Hero : public Character {
private:
    string heroClass;
    int specialEnergy;

public:
    Hero(string n, string cls, int hp, int ap) 
        : Character(n, hp, ap), heroClass(cls), specialEnergy(50) {}

    // Polymorphism: Method Overriding
    void attack(Character& target) override {
        cout << "[" << heroClass << "] ";
        Character::attack(target); // Calls the base class attack logic
    }

    // Unique capability for the Hero class
    void specialSkill(Character& target) {
        if (specialEnergy >= 20) {
            // Generates randomized critical damage (approx. double the base power)
            int baseSpecial = getAttackPower() * 2;
            int minDamage = baseSpecial * 0.9;
            int maxDamage = baseSpecial * 1.3;
            int actualDamage = minDamage + (rand() % (maxDamage - minDamage + 1));

            cout << "\n🔥 " << getName() << " uses Special Skill on " << target.getName() 
                 << " for " << actualDamage << " Critical Damage!\n";
            target.reduceHealth(actualDamage);
            specialEnergy -= 20;
        } else {
            cout << "\n❌ Not enough energy for Special Skill! Performing normal attack instead.\n";
            attack(target);
        }
    }

    void displayStatus() {
        cout << getName() << " (" << heroClass << ") - Health: " << getHealth() << " | Energy: " << specialEnergy << "\n";
    }
};

// 2. Inheritance: Enemy child class derived from Character base class
class Enemy : public Character {
private:
    string enemyType;

public:
    Enemy(string n, string type, int hp, int ap) 
        : Character(n, hp, ap), enemyType(type) {}

    // Polymorphism: Method Overriding
    void attack(Character& target) override {
        cout << "😈 [" << enemyType << "] ";
        Character::attack(target);
    }
};

int main() {
    srand(time(0)); // Seed for random number generation

    cout << "=======================================\n";
    cout << "   WELCOME TO THE OOP TEXT-BASED RPG   \n";
    cout << "=======================================\n";

    // Initialize Hero object
    string heroName;
    cout << "Enter your Hero's Name: ";
    cin >> heroName;
    
    Hero myHero(heroName, "Warrior", 150, 20);
    
    // Demonstration of Polymorphism: Base class pointer referencing a child class object
    Character* bossEnemy = new Enemy("Malakor", "Dragon Boss", 180, 15);

    cout << "\nAn evil " << bossEnemy->getName() << " has appeared! Battle Starts!\n";

    // Core Gameplay / Battle Loop
    while (myHero.isAlive() && bossEnemy->isAlive()) {
        myHero.displayStatus();
        cout << "Boss Health: " << bossEnemy->getHealth() << "\n\n";
        
        cout << "Choose your action:\n";
        cout << "1. Normal Attack\n";
        cout << "2. Use Special Skill (Costs 20 Energy)\n";
        
        int choice;
        // Input validation loop: Prevents infinite loops and invalid options
        while (true) {
            cout << "Enter choice (1-2): ";
            if (cin >> choice && (choice == 1 || choice == 2)) {
                break; // Valid input received
            }
            cout << "❌ Invalid input! Please enter 1 or 2.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Execution of Hero's turn
        if (choice == 2) {
            myHero.specialSkill(*bossEnemy);
        } else {
            myHero.attack(*bossEnemy);
        }

        // Execution of Enemy's turn if still alive
        if (bossEnemy->isAlive()) {
            cout << "\n---------------------------------------\n";
            bossEnemy->attack(myHero);
            cout << "---------------------------------------\n\n";
        }
    }

    // Determine and display the match results
    cout << "=======================================\n";
    if (myHero.isAlive()) {
        cout << "🎉 VICTORY! You have defeated " << bossEnemy->getName() << " and saved the kingdom!\n";
    } else {
        cout << "💀 GAME OVER! " << myHero.getName() << " was defeated by " << bossEnemy->getName() << ".\n";
    }
    cout << "=======================================\n";

    // Dynamic memory cleanup to avoid memory leaks
    delete bossEnemy; 

    return 0;
}
