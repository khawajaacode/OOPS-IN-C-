// This Pointer
// This pointer is a pointer that points to the current object.

#include <iostream>

#include<string>

using namespace std;


class Teacher{

public:

string name;
int age;
string gender;
string subject;
string dept;

Teacher(string name, int age, string gender, string subject, string Dept){

  this-> name = name;
  this->age = age;
  this->gender =  gender;
  this->subject = subject;
  this-> dept = Dept;

}



void getinfo() {

  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
  cout << "Gender: " << gender << endl;
  cout << "Subject: " << subject << endl;
  cout << "Department: " << dept << endl;

}

};

int main()
{
  Teacher t1("Babar", 20, "Male", "C++", "Software Engineering");

    t1.getinfo();
    

    return 0;
}