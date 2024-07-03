// Copy Constructor

//Copy Cnstructor used to Copy the Properties of one Object into Another.

//  Copy Constructor

#include <iostream>

#include<string>

using namespace std;


class Student{
public:

string name;
double* cgpaptr;

Student(string name, double cgpa){
  this->name = name;
cgpaptr = new double;
*cgpaptr = cgpa;
}

// Custom Copy Constructor
Student(Student &orgobj){
  this->name = orgobj.name;
  cgpaptr = new double;
  *cgpaptr = *orgobj.cgpaptr;
  
}


void getinfo() {
  cout << "Name: " << name << endl;
  cout << "CGPA: " << *cgpaptr << endl;
}

};

int main()
{
  Student s1("Babar",3.2);
  Student s2(s1);
  
  *(s2.cgpaptr) = 4.3;
  s1.getinfo();

    s2.name = "ali";
    s2.getinfo();
   
    

    return 0;
}