#include <iostream>

using namespace std;

class Person{
    private: 
    string name;
    int age;

    public:
    Person(string n, int a) : name(n), age(a) {
    }

    void display(){
        cout << "Name " << name <<endl;
        cout << "Age : " << age<<endl;
    }

};

class Student : public Person {

    public:
    int roll;
    float marks;

    Student(string n, int a, int r, float m )  : Person(n,a), roll(r) , marks(m) {
 
    }
    void sdisplay() {
    
        cout << roll<<endl;
        cout << marks;
    }

};





int main()
{
    Student s("Babar", 20, 4737, 90.0);
    s.display();
    s.sdisplay();






}   
