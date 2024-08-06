// Question: Create a class Rectangle with private data members length and width. Write a public member
//  function to calculate the area of the rectangle. Implement getters and setters for the private data members.
// Concepts Covered: Class, Object, Encapsulation, Member functions


#include <iostream>

using namespace std;

class Rectangle{
     private:
     int length, width;

     public:
     void get(){
        int area;
        cout << "Enter Length : ";
        cin >> length;
        cout << "Enter Width : ";
        cin >> width;
        area = length * width;
     }
     void set(){
        int area;
        cout << "Length of Rectangle is : " << length << endl;
        cout << "Width of Rectangle is : " << width << endl;
        cout << "Area of Rectangle is : " << area;
     }
};
 

int main()
{
    Rectangle r1;
    r1.get();
    r1.set();

    return 0;
}