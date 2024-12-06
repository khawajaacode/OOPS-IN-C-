#include<iostream>

using namespace std;

class Employee {

    public:
    string name;
    int ID;

    

};

class Manager : public Employee {
    public:
    void manage() {
        name = "John";
        cout  << name << " Manager Manages all Worker" << endl;

    }
};

class Worker : public Employee {
public:
    void Work() {

        ID = 12345;
        cout  << ID << " Worker Work under Manger";
    }
};

int main() {
    Manager m;
    m.manage();
    Worker w;
    w.Work();
}