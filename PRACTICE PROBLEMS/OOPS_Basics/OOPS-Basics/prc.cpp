//  Write a C++ program to create a class called Person that has private member variables 
// for name, age and country. Implement member functions to set and get the values of these 
// variables.
#include <iostream>
#include <string>

using namespace std;

class Person{
private: 
    string name , country;
    int age;

public:
void info(){
    cout << "Enter Person name: ";
    getline(cin>>ws,name);
    cout << "Enter Person age: ";
    cin >> age;
    cout << "Enter Person Country: ";
    getline(cin>>ws,country);
}

void getinfo(){
    cout << "Name: " << name << endl << "AGE: " << age << endl << "Country " << country;
}
};



int main()
{

    Person p1;

    p1.info();
    p1.getinfo();

    return 0;
}