#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual double area() const = 0;  // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void draw() override {
        cout << "Drawing Circle with radius " << radius << endl;
    }

    double area() const override {
        return M_PI * radius * radius;  // Correct formula for area
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() override {
        cout << "Drawing Rectangle with width " << width << " and height " << height << endl;
    }

    double area() const override {
        return width * height;  // Area of rectangle
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}

    void draw() override {
        cout << "Drawing Triangle with base " << base << " and height " << height << endl;
    }

    double area() const override {
        return 0.5 * base * height;  // Area of triangle
    }
};

int main() {
    Shape* shape;

    Circle c(5.0);  // Initialize Circle with radius
    Rectangle r(4.0, 6.0);  // Initialize Rectangle with width and height
    Triangle t(3.0, 4.0);  // Initialize Triangle with base and height

    shape = &c;
    shape->draw();
    cout << "Area: " << shape->area() << endl;

    shape = &r;
    shape->draw();
    cout << "Area: " << shape->area() << endl;

    shape = &t;
    shape->draw();
    cout << "Area: " << shape->area() << endl;

    return 0;
}
