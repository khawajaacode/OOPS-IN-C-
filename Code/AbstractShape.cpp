#include <iostream>

using namespace std;

class Shape {
    public:
    virtual double area() = 0;
};

class Rectangle : public Shape {

    private: 
    int length;
    int width;
    public:

    Rectangle(int l, int w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }
};

class Triangle : public Shape{
    private: 
    int height;
    int base;

    public:

    Triangle(int b, int h) : base(b), height(h) {}

    double area() override {
        return 0.5*height*base;
    }

};

int main() {

    Rectangle r(5, 9);
    Triangle t(4,2);

    cout << "Area of Rectangle " << r.area() <<endl;
    cout << "Area of Triangle " << t.area() ;

    return    0;

}