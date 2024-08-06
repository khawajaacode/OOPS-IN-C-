// Write a C++ program to implement a class called Student that has private member variables 
//for name, class, roll number, and marks. Include member functions to calculate the grade based
// on the marks and display the student's information.

#include <iostream>
#include <string>

using namespace std;

class Student{

    private: 
    string name;
    int Class, rollno, marks;

    public:
    void input(){
        cout << "Enter Name : " ;
        getline(cin>>ws, name);
        cout << "Input Roll No. : ";
        cin >> rollno;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void grade(){
        int grade = marks;
        if(marks > 90){
            cout << "You Got A Grade" << endl;
        }
        else if (marks > 70 && marks < 89){
            cout << "You Got B Grade" << endl;
        }
        else if (marks > 50 && marks < 69){
            cout << "You Got C Grade" << endl;
        }
        else{
            cout << "You Got F Grade" << endl;
        }
    }

    void getinfo(){
        cout << "Student Name : " << name << endl << "Roll NO: " << rollno << endl << "Marks : " <<  marks;
    }


};

int main()
{
    Student s1;
    s1.input();
    s1.grade();
    s1.getinfo();

    

    return 0;
}