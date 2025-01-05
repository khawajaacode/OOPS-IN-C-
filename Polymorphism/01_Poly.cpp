#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() = 0;
};

class Rectangle : public Shape {
private:
    int length, width;
public:
    Rectangle(int l, int w) : length(l), width(w) {}
    void area() override {
        cout << "Rectangle area: " << length * width << endl;
    }
};

class Triangle : public Shape {
private:
    int base, height;
public:
    Triangle(int b, int h) : base(b), height(h) {}
    void area() override {
        cout << "Triangle area: " << 0.5 * base * height << endl;
    }
};

int main() {
    Shape *ptr[2];
    Rectangle r(10, 5);
    Triangle t(100, 2);

    ptr[0] = &r;
    ptr[1] = &t;

    for (int i = 0; i < 2; i++) {
        ptr[i]->area();
    }

    return 0;
}