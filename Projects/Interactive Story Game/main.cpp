#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Character {
protected:
    string name;
    int health;

public:
    Character(string n, int he = 100) : name(n), health(he) {}

    virtual void attack(Character& target) {
        cout << name << " attacks " << target.getName() << "!" << endl;
        // Example damage
        int damage = 30;
        target.decreaseHealth(damage);
        cout << target.getName() << "'s health is now " << target.getHealth() << "%" << endl;
    }

    virtual void defend() {
        cout << name << " defends with health: " << health << "%" << endl;
    }

    virtual void status() {
        cout << name << " is in status with health: " << health << "%" << endl;
    }

    virtual ~Character() {
        cout << "Character " << name << " destroyed!" << endl;
    }

    void saveState() {
        ofstream file(name + ".txt");
        if (file.is_open()) {
            file << health << endl;
            file.close();
            cout << "Character's state has been saved." << endl;
        } else {
            cout << "Unable to save character's state." << endl;
        }
    }

    void loadState() {
        ifstream file(name + ".txt");
        if (file.is_open()) {
            file >> health;
            file.close();
            cout << "Character's state has been loaded." << endl;
        } else {
            cout << "No saved state found for " << name << "." << endl;
        }
    }

    // Accessor methods
    string getName() const { return name; }
    int getHealth() const { return health; }
    void decreaseHealth(int amount) { health -= amount; if (health < 0) health = 0; }
};

class Hero : public Character {
public:
    Hero(string n) : Character(n) {}

    void attack(Character& target) override {
        cout << name << " attacks " << target.getName() << " with a powerful strike!" << endl;
        int damage = 30;
        target.decreaseHealth(damage);
        cout << target.getName() << "'s health is now " << target.getHealth() << "%" << endl;
    }

    void status() override {
        cout << name << " is a brave hero with health: " << health << "%" << endl;
    }
};

class Villain : public Character {
public:
    Villain(string n) : Character(n) {}

    void attack(Character& target) override {
        cout << name << " attacks " << target.getName() << " with dark magic!" << endl;
        int damage = 30;
        target.decreaseHealth(damage);
        cout << target.getName() << "'s health is now " << target.getHealth() << "%" << endl;
    }

    void status() override {
        cout << name << " is a menacing villain with health: " << health << "%" << endl;
    }
};

class NPC : public Character {
public:
    NPC(string n) : Character(n) {}

    void status() override {
        cout << name << " is an NPC with health: " << health << "%" << endl;
    }
};

void playGame() {
    Character* characters[3];
    characters[0] = new Hero("Arthur");
    characters[1] = new Villain("Morgar");
    characters[2] = new NPC("Gandalf");

    // Simulate interactions
    for (int i = 0; i < 3; ++i) {
        characters[i]->loadState();
        characters[i]->status();
    }

    // Example of interaction between characters
    characters[0]->attack(*characters[1]); // Hero attacks Villain
    characters[1]->attack(*characters[2]); // Villain attacks NPC

    for (int i = 0; i < 3; ++i) {
        characters[i]->saveState();
        delete characters[i];
    }
}

int main() {
    playGame();
    return 0;
}
