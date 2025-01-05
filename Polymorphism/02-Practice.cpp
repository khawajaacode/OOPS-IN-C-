#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
public:
    virtual void getData() = 0; // Pure virtual function
    virtual void isOutstanding() = 0; // Pure virtual function
};

class Student : public Person {
private:
    float gpa;
public:
    void getData() override {
        cout << "Enter Student Name: "; cin >> name;
        cout << "Enter Student GPA: "; cin >> gpa;
    }

    void isOutstanding() override {
        if (gpa > 3.5)
            cout << "The student " << name << " is outstanding." << endl;
        else
            cout << "The student " << name << " is not outstanding." << endl;
    }
};

class Professor : public Person {
private:
    int numPubs;
public:
    void getData() override {
        cout << "Enter Professor Name: "; cin >> name;
        cout << "Enter Number of Publications: "; cin >> numPubs;
    }

    void isOutstanding() override {
        if (numPubs > 10)
            cout << "The professor " << name << " is outstanding." << endl;
        else
            cout << "The professor " << name << " is not outstanding." << endl;
    }
};

int main() {
    Person* persons[2];

    Student s;
    Professor p;

    persons[0] = &s;
    persons[1] = &p;

    for (int i = 0; i < 2; i++) {
        persons[i]->getData();
    }

    for (int i = 0; i < 2; i++) {
        persons[i]->isOutstanding();
    }

    return 0;
}