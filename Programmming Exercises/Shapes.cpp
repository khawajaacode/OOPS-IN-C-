#include <iostream>
#include <cmath> // For M_PI and sqrt

// Base class
class Shape {
public:
    // Virtual functions for calculating area and perimeter
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class for Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};

// Derived class for Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }
};

// Derived class for Triangle
class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    double area() const override {
        double s = (a + b + c) / 2; // Semi-perimeter
        return sqrt(s * (s - a) * (s - b) * (s - c)); // Heron's formula
    }

    double perimeter() const override {
        return a + b + c;
    }
};

int main() {
    // Creating objects of derived classes
    Shape* shapes[] = {
        new Circle(5),
        new Rectangle(4, 6),
        new Triangle(3, 4, 5)
    };

    // Looping through the shapes array and displaying the area and perimeter
    for (Shape* shape : shapes) {
        std::cout << "Area: " << shape->area() << std::endl;
        std::cout << "Perimeter: " << shape->perimeter() << std::endl;
        std::cout << std::endl;
    }

    // Deleting the allocated memory
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
