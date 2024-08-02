#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a) : name(n), age(a) {}

    // Function to display details of the person
    void displayPersonDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class
class Student : public Person {
private:
    char grade;

public:
    // Constructor
    Student(string n, int a, char g) : Person(n, a), grade(g) {}

    // Function to display details of the student
    void displayStudentDetails() {
        displayPersonDetails(); // Calling base class function
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    // Creating an object of the derived class
    Student student("John Doe", 20, 'A');
    
    // Displaying the student's details
    student.displayStudentDetails();

    return 0;
}
