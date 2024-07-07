#include<iostream>

#include<string>

using namespace std;


class Student {
    public:
   
    string name;

    Student() {
        cout << "Non-Parameterized Constructor.\n";

    }
    Student(string name) {
        this->name =name;
        cout << "Parameterized Constructor.\n";

    }

};




int main() {
// Student s1; // non
Student s1("Babar Naseer");

    return 0;
}
