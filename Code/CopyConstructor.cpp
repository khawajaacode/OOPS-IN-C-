#include <iostream>

using namespace std;

class Point {
    private:
    int x;
    int y;
    public:

    Point (int x_val, int y_val) : x(x_val), y(y_val) {}

    // Point( const Point& other) : x(other.x), y(other.y) {
    //     cout << "Copy Constructor Called" <<endl;

    // } Explicit Copy Constructor

    void display() const{
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1(10,20);
   cout << "Original Point: "; 
   p1.display();

 // Point p2 = p1; cout << "Copied Point: "; p2.display();

   Point p2(p1);
   cout << "Copied";
   p2.display();
}