// Question: Create a class Circle with a constructor that takes the radius as an argument. 
// The class should also have a destructor and a member function to calculate the area of the circle.
// Concepts Covered: Constructors, Destructors, Member functions, Basic Math operations.


#include <iostream>
#include <cmath>

using namespace std;



class Circle{
    public:
    // Initializes the `radius_` member variable with the provided `radius` value.
    Circle(double radius) : radius_(radius){
        cout << "Radius is Created"<<endl;
    }
    ~Circle(){
        cout << ".\n Circle Destroyed";
    }
    double calculateArea(){
        return (2 * M_PI * radius_*radius_);
    }
    private:
    double radius_;
};
int main()
{

    Circle circle(5.0);
    double area = circle.calculateArea();
    cout << "Area " << area;


    return 0;
}