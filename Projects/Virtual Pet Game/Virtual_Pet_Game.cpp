#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Pet {
protected:
    string name;
    int hunger;
    int happiness;
    int health;

public:
    Pet(string n, int h = 50, int hap = 50, int he = 50) : name(n), hunger(h), happiness(hap), health(he) {}

    virtual void feed() {
        hunger -= 10;
        if (hunger < 0) hunger = 0;
        cout << name << " has been fed. Hunger: " << hunger << endl;
    }

    virtual void play() {
        happiness += 10;
        hunger += 5;
        if (happiness > 100) happiness = 100;
        cout << name << " is playing. Happiness: " << happiness << ", Hunger: " << hunger << endl;
    }

    void checkHealth() {
        health = 100 - (hunger / 2);
        if (health < 0) health = 0;
        cout << name << "'s health is " << health << endl;
    }

    virtual void makeSound() {
        cout << name << " is making a sound!" << endl;
    }

    virtual ~Pet() {
        cout << name << " has been destroyed." << endl;
    }

    void saveState() {
        ofstream file(name + ".txt");
        if (file.is_open()) {
            file << hunger << endl;
            file << happiness << endl;
            file << health << endl;
            file.close();
            cout << "Pet's state has been saved." << endl;
        } else {
            cout << "Unable to save pet's state." << endl;
        }
    }

    void loadState() {
        ifstream file(name + ".txt");
        if (file.is_open()) {
            file >> hunger;
            file >> happiness;
            file >> health;
            file.close();
            cout << "Pet's state has been loaded." << endl;
        } else {
            cout << "No saved state found for " << name << "." << endl;
        }
    }
};

class Dog : public Pet {
public:
    Dog(string n) : Pet(n) {}

    void makeSound() override {
        cout << name << " barks!" << endl;
    }
};

class Cat : public Pet {
public:
    Cat(string n) : Pet(n) {}

    void makeSound() override {
        cout << name << " meows!" << endl;
    }
};

class Bird : public Pet {
public:
    Bird(string n) : Pet(n) {}

    void makeSound() override {
        cout << name << " chirps!" << endl;
    }
};

int main() {
    Pet* myPets[3];

    myPets[0] = new Dog("Buddy");
    myPets[1] = new Cat("Whiskers");
    myPets[2] = new Bird("Tweety");

    for (int i = 0; i < 3; ++i) {
        myPets[i]->loadState();
        myPets[i]->makeSound();
        myPets[i]->feed();
        myPets[i]->play();
        myPets[i]->checkHealth();
        myPets[i]->saveState();
        delete myPets[i];
    }

    return 0;
}
