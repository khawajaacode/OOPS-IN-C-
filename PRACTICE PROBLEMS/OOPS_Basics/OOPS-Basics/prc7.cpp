//  Write a C++ program to create a class called Person that has private member variables for name, age and country. Implement member functions to set and get the values of these variables.
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person{
private:
string name, country;

public:
 Person(string name, string country){
    this-> name = name;
    this-> country = country;
 }

 void getinfo(){
    cout << name << setw(10) << country;
 }
};
int main()
{

    Person p1("Babar", "USA");
  p1.getinfo();


    return 0;
}