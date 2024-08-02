#include <iostream>
#include <string>

using namespace std;

class Laptop{
    public:
    string brand;
    string model;
    double price;

    Laptop(string b, string m, double p) : brand(b), model(m), price(p) {}
    
    void displaydetails(){
        cout << "Brand : " << brand <<endl;
        cout << "model : " << model <<endl;
        cout << "price : $" << price <<endl;
    }


};

int main()
{

    Laptop l1("APPLE", "MacBook Pro", 199.9);
    l1.displaydetails();
    

    return 0;
}