#include <iostream>
#include <string>

using namespace std;


class Result{
public:
int marks;
string grade;

    Result(int m, string g){
        marks = m;
        grade = g;

    }
    void getinfo(){
        cout << "Marks : "<<marks << endl;
        cout << "Grade : " <<grade <<endl;
    }

};

int main()
{
     Result r1(80, "A"),r2(50,"C");
    r1.getinfo();
    r2.getinfo();
    

    return 0;
}