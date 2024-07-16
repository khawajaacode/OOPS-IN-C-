// // Write a C++ program to implement a class called Circle that has
//  private member variables for radius. Include member functions to
//   calculate the circle's area and circumference.

#include <iostream>




using namespace std;

class Circle {
    private:
    double radius;

    public:
    void getRadius(double r) {
      radius = r;

    }
    void Area(){
      cout << "Area of Circle " << 3.14 * radius *radius <<endl;

    }
    void circumference(){
      cout << "Circumference of Circle : " << 2 * 3.14 * radius << endl;
    }

    

};


int main()
{
      Circle c1;
      float rad;
      cout << "Enter Radius : ";
      cin >>rad;
       c1.getRadius(rad);
       c1.Area();
       c1.circumference();
    

    return 0;
}