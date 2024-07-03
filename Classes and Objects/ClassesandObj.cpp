#include <iostream>
#include <string>

using namespace std;

class Teacher {
public:

// // Non-Parameterized Constructor
//   Teacher() {
//     cout << "Hi Iam Constructor \n";
//   }
 // Paramerterized 
  Teacher(string n, string d, string s, double sal) {
    name = n;
    dept = d;
    salary = sal;
    subject = s;
  }
  void getinfo()
  {
    cout << "name : " << name << endl;
    cout << "Subject : " << subject << endl;
  } 

  private: 
  double salary;

  public: 
  string name;
  string dept;
  string subject;

  void changeDept(string newDpt) {
    dept = newDpt;
  }

  // Setter
  void setSalary(double s) {
    salary = s;
  }

  // Getter
  double getSalary() {
    return salary;
  }
};

// Encapsulation
class Accounts{
  private: // Data Hiding
  double Balance;
  double Password;

  public:
  double Accountid;
  string Accountname;
};




int main() {
  Teacher t1("BABAR","ComputerScience", "Math ", 5000.3  ); // Constructor Call
  t1.getinfo();






 

  return 0;
}