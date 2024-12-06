#include<iostream>

using namespace std;

class Student {
    private:
    string name;
    int rollno;
    float marks;

    public:
    void set(){
        cout << "Enter Student Name: "; getline(cin,name);
        cout << "Enter The Roll No. " ; cin >> rollno;
        cout << "Enter the Marks of Student "; cin>>marks;
    } 

    void get() {
        cout << "Name: " << name <<endl;
        cout << "Rollno: " << rollno <<endl;
        cout << "Marks: " << marks <<endl;
    }
};

int main() {
    Student s;
    s.set();
    s.get();
}