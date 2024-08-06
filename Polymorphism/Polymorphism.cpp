#include <iostream>
using namespace std;

// base class
class Shape {
  public:

    // function of base class
    void shape_name() {
        cout << "Shape" << endl;
    }
};

// derived class
class Square : public Shape {
  public:

    // overriding function of derived class
    void shape_name() {
        cout << "Square" << endl;
    }
};

int main() {

    // create class objects
    Shape shape;
    Square square;

    // call function from Shape class
    shape.shape_name();

    // call function from Square class
    square.shape_name();

    return 0;
}