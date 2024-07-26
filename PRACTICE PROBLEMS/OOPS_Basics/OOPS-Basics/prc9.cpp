//  Write a C++ program to implement a class called Employee that has private member variables 
//  for name, employee ID, and salary.Include member functions to calculate and set salary based
//   on employee performance.


#include <iostream>
#include <string>

using namespace std;


class Employee {
private:
string name;
int id,salary,performance;

public:

Employee(){
    salary = 50000;
    id = 12345;
    name = "John Doe"; 
   
}
void input(){

    cout << "Enter Employee Performance: " << endl;
    cin >> performance;
    if(performance > 90) {
        cout << "You Have Excellent Performance you got Full Salary " << salary << endl; 
    }
  else if(performance > 50) {
    cout << "You Have Minimum Performance you got the Salary " << salary -10000 << endl;  
            }
    else {
        cout << "No Performance your Salary is : " << salary - 25000 <<endl;
    }
}

    void getinfo(){
        cout << "Employee name: " << name << endl;
        cout >> "Employee id " << id << endl;
        cout << "Employee Performance : " <<  performance<<endl;
        
    }
};

int main()
{
Employee emp;
emp.input();
emp.getinfo();
    

    return 0;
}