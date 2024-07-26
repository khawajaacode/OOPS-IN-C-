// Write a C++ program to create a class called Car that has private member variables for
//  company, model, and year. Implement member functions to get and set these variables

#include <iostream>
#include <string>

using namespace std;

class Car{
private:
string company,model;
int year;
public:

Car(string com, string mod, int y){
     company = com;
     model = mod;
     year = y;

}
void getinfo(){
    cout << "Company : " << company <<endl << "Model: " << model <<endl << "Year: " << year;    
}
};

int main()
{
    Car c1("TOYOTA", "Y23", 2019);
    c1.getinfo();

    

    return 0;
}