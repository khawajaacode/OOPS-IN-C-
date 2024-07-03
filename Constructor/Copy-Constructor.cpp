// Copy Constructor

//Copy Cnstructor used to Copy the Properties of one Object into Another.

// Shallow Copy Constructor

#include <iostream>

#include<string>

using namespace std;


class Student{
public:

string name;
double* cgpaPtr;

Student(string name, double cgpa){
  this->name = name;
  cgpaPtr = new double(cgpa);

}

// Custom Copy Constructor
Student(Student &orgobj){
  this->name = orgobj.name;
  this->cgpaPtr = orgobj.cgpaPtr;
}


void getinfo() {
  cout << "Name: " << name << endl;
  cout << "CGPA: " << *cgpaPtr << endl;
}

};

int main()
{
  Student s1("Babar",3.2);
   Student s2(s1);

      s1.getinfo();
      *(s2.cgpaPtr) = 4.9;

      s1.getinfo();
   
    

    return 0;
}