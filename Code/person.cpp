#include <iostream>
#include <string>
using namespace std;

class Person {

    private:
    string name;
    int age;
    string address;
    public:

    void set() {
        cout << "Enter Name of a Person "; getline(cin, name);
        cout << "Enter Age of a Person "; cin >> age;
        cout << "Enter Address of a Person "; getline(cin, address);
    }

    void get(){
        cout << "NAME : " << name<<endl;
        cout << "Age : " << age<<endl;
        cout << "Address : " << address<<endl;
    }
};

int main() {
    Person p;
     p.set(); p.get();

}