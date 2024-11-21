#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string color;

public:
    void setColor(string c) {
        color = c;
    }

    void displayColor() {
        cout << "Color: " << color << endl;
    }
};

class Circle : public Shape {
private:
    float radius;

public:
    void setRadius(float r) {
        radius = r;
    }

    void displayArea() {
        cout << "Area of Circle: " << 3.14159 * radius * radius << endl;
    }
};

int main() {
    Circle circle;
    circle.setColor("Red");
    circle.setRadius(5.0);
    circle.displayColor();
    circle.displayArea();
    return 0;
}
