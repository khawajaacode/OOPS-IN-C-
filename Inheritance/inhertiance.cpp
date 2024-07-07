#include<iostream>

#include<string>

using namespace std;

class Person {
    public:
    string name;
    int age;

    Person (){
        cout << "Parent Constructor.\n";
    }
};

class Student : public Person{
    public:
    int rollno;

    Student() {
        cout << "Child Constructor. \n";
    }

void getinfo() {
    cout << "Name " << name << endl;
    cout << "Age " << age << endl;


}
};



int main() {

    Student s1;
    s1.name = "Babar";
    s1.age = 20;

    s1.getinfo();


    return 0;
}
