#include <iostream>
#include <string>

using namespace std;

class Rectangle {
private:
    double length;
    double width;
public:
    Rectangle() {
        length = width = 0;
    }

    void getDimensions() {
        cout << "Input Length and Width: ";
        cin >> length >> width;
    }

    double area() const {
        return length * width;
    }

    double perimeter() const {
        return 2 * (length + width);
    }

    void compareArea(Rectangle R) const {
        if (area() > R.area()) {
            cout << "The first rectangle has more area (" << area() << ") than the second rectangle (" << R.area() << ")." << endl;
        } else if (area() < R.area()) {
            cout << "The first rectangle has less area (" << area() << ") than the second rectangle (" << R.area() << ")." << endl;
        } else {
            cout << "Both rectangles have the same area (" << area() << ")." << endl;
        }
    }
};

int main() {
    Rectangle r1, r2;
    
    cout << "Enter Details of Rectangle 1:" << endl;
    r1.getDimensions();
    cout << "Area of Rectangle 1: " << r1.area() << endl;
    cout << "Perimeter of Rectangle 1: " << r1.perimeter() << endl;
    
    cout << "Enter Details of Rectangle 2:" << endl;
    r2.getDimensions();
    cout << "Area of Rectangle 2: " << r2.area() << endl;
    cout << "Perimeter of Rectangle 2: " << r2.perimeter() << endl;
    
    r1.compareArea(r2);

    return 0;
}
  