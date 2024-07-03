// Constructor
// Special method Invoked Automatically at a time of Object Creation.Used for Intialisation
#include <iostream>

#include<string>

using namespace std;

class Teacher{

  public:

// Non-Parameterized
Teacher(){

  cout<<"HI, Im a Constructor"<<endl;
}

public:
string name;
int age;
 
 private:
 double salary;

};

int main()
{
Teacher t1; // Constructor Call

    

    return 0;
}