#include<iostream>

#include<string>

using namespace std;

class Person {
    public:
    string name;
    int age;

    Person (string name, int age){
        this->name = name;
        this->age = age;

    }
};

class Student : public Person{
    public:
    int rollno;

    Student(string name, int age, int rollno) : Person(name, age) {
        this-> rollno = rollno;
    }

void getinfo() {
    cout << "Name " << name << endl;
    cout << "Age " << age << endl;
    cout << "Roll No. " << rollno<<endl;


}
};



int main() {

    Student s1("Babar Naseer", 20, 1234);

    s1.getinfo();


    return 0;
}
