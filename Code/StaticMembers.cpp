#include <iostream>

using namespace std;

class Employee {
    
    private: 
    string name;
    int id;
    static int count;

    public:

    Employee(string n, int i) : name(n), id(i) {
            count++;        
    }

    static void displaycount() {
        cout << "Total Employee Objects " << count <<endl;

    } 
    void displayDetails() const {
         cout << "Employee Name: " << name << ", ID: " << id << endl; 
    }
};

int Employee::count = 0;

int main() {
    Employee e1("John", 101);
    Employee e2("Jane", 102);
    Employee e3("Jake", 103);

    e1.displayDetails();
    e2.displayDetails();
    e3.displayDetails();


    Employee::displaycount();


    return 0;
}