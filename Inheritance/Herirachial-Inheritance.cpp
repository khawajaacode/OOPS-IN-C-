#include<iostream>

#include<string>

using namespace std;

class Person {
public:
string name;
int age;

};


class Student : public Person {
    public:
    int rollno;
    string name;

};
class Teacher : public Person {
    public:
    string subj;
    double salary;

};
class TA : public Student, public Teacher{

};


int main() {
TA t1;
t1.Student::name = "Tom Cruise";
t1.subj = "Math";

cout << t1.Student::name <<endl;
cout << t1.subj <<endl;




    return 0;
}
