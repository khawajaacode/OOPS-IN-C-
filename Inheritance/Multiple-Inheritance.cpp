#include<iostream>

#include<string>

using namespace std;


class Student {
    public:
    int rollno;
    string name;

};
class Teacher {
    public:
    string subj;
    double salary;

};
class TA : public Student, public Teacher{

};


int main() {
TA t1;
t1.name = "Tom Cruise";
t1.subj = "Math";

cout << t1.name <<endl;
cout << t1.subj <<endl;




    return 0;
}
