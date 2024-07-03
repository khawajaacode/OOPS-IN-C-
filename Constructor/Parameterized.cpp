#include <iostream>

#include<string>

using namespace std;


class Teacher{
// Parameterized Constructor
public:

string name;
int age;
string gender;
string subject;
string dept;

Teacher(string n, int a, string g, string s, string D){
  name = n;
  age = a;
  gender =  g;
  subject = s;
  dept = D;

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