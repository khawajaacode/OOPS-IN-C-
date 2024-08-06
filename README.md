# OOPS IN C++

This project is an implementation of Object-Oriented Programming (OOP) principles in C++. It serves as a comprehensive example of using classes, inheritance, polymorphism, encapsulation, and abstraction in C++. The goal is to provide a solid foundation for understanding OOP concepts through practical examples and explanations.

## Features

- Comprehensive examples of OOP principles
- Well-documented code with comments
- Modular and reusable code structure
- Real-world scenarios demonstrating OOP applications

## Installation

Clone the repository:

```bash
  git clone https://github.com/khawajaacode/OOPS.git
```

Navigate to the project directory:

```bash
    cd OOPS
```

Compile the code using a C++ compiler (e.g., g++)


```bash
g++ main.cpp -o main
```

## Usage

```sh
./main
```



## Classes and Objects

This section covers the basics of classes and objects in C++. A class is a blueprint for creating objects, and an object is an instance of a class.

Example:

```
class Animal {
public:
    string name;
    int age;

    void speak() {
        cout << "The animal speaks." << endl;
    }
};

int main() {
    Animal dog;
    dog.name = "Buddy";
    dog.age = 3;
    dog.speak();

    return 0;
}
```


## Inheritance:

Inheritance allows a class to inherit properties and behaviors from another class.

Example:

```
class Animal {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();
    myDog.bark();

    return 0;
}
```

## Polymorphism
Polymorphism allows methods to do different things based on the object it is acting upon.

Example:

```
class Animal {
public:
    virtual void makeSound() {
        cout << "Some generic animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* myAnimal = new Dog();
    myAnimal->makeSound(); // Outputs: Woof!

    myAnimal = new Cat();
    myAnimal->makeSound(); // Outputs: Meow!

    return 0;
}
```
## Encapsulation
Encapsulation restricts direct access to some of the object's components, which can prevent the accidental modification of data.

Example:

```
class Person {
private:
    string name;
    int age;

public:
    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void setAge(int age) {
        if(age > 0) {
            this->age = age;
        }
    }

    int getAge() {
        return age;
    }
};

int main() {
    Person person;
    person.setName("John");
    person.setAge(30);

    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;

    return 0;
}
```
## Abstraction
Abstraction is the concept of hiding the complex implementation details and showing only the essential features of an object.

Example:

```
class AbstractEmployee {
    virtual void askForPromotion() = 0; // Pure virtual function
};

class Employee : public AbstractEmployee {
private:
    string name;
    int age;
    float salary;

public:
    Employee(string name, int age, float salary) : name(name), age(age), salary(salary) {}

    void askForPromotion() override {
        if (age > 30)
            cout << name << " got promoted!" << endl;
        else
            cout << name << ", sorry, no promotion!" << endl;
    }
};

int main() {
    Employee emp1("John", 28, 50000);
    Employee emp2("Doe", 35, 60000);

    emp1.askForPromotion();
    emp2.askForPromotion();

    return 0;
}
```
# Projects

## Virtual Pet Game

### Description
A C++ application that simulates taking care of a virtual pet. Users can feed, play with, and take care of their pet, observing its health and happiness levels.

### Technologies Used
- C++
- Object-Oriented Programming

### Installation Instructions
1. Clone the repository: `git clone (https://github.com/khawajaacode/OOPS/tree/main/Projects`
2. Navigate to the project directory: `cd virtual-pet-game`
3. Build the project: `make`

### Usage
Run the application using: `./virtual_pet_game`

---

## Interactive Story Game

### Description
An interactive story game where users make choices that affect the storyline. Built using C++ with an emphasis on OOP principles.

### Technologies Used
- C++
- Object-Oriented Programming

### Installation Instructions
1. Clone the repository: `git clone https://github.com/khawajaacode/OOPS/tree/main/Projects`
2. Navigate to the project directory: `cd interactive-story-game`
3. Build the project: `make`

### Usage
Run the application using: `./interactive_story_game`

---

## Virtual Library System

### Description
A virtual library system that allows users to manage a collection of books. Features include viewing, borrowing, and returning books.

### Technologies Used
- C++
- Object-Oriented Programming

### Installation Instructions
1. Clone the repository: `git clone https://github.com/khawajaacode/OOPS/tree/main/Projects)`
2. Navigate to the project directory: `cd virtual-library-system`
3. Build the project: `make`

### Usage
Run the application using: `./virtual_library_system`

---

## Smart Home Automation System

### Description
A C++ project that simulates a smart home automation system, including features like controlling lights, thermostat, and security systems.

### Technologies Used
- C++
- Object-Oriented Programming

### Installation Instructions
1. Clone the repository: `git clone https://github.com/khawajaacode/OOPS/tree/main/Projects`
2. Navigate to the project directory: `cd smart-home-automation-system`
3. Build the project: `make`

### Usage
Run the application using: `./smart_home_automation_system`


