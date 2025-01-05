#include <iostream>

using namespace std;


class Shape {
    public:


   

    virtual void perimeter(){
        cout << "Calculating Perimeters.. ";

    }


};

class Rectangle : public Shape {
    private:

int length, width;
    public:
    

    Rectangle(int l, int w) : length(l), width(w){}
    void perimeter() override {
        cout << "Rectangle Perimeter: " << 2 * (length + width) << endl;
    }


};

class Circle : public Shape {
    private:
    float radius;

    public:
    Circle(float r) : radius(r) {}
     void perimeter() {
        cout << "Circle " << 2 * 3.14 * radius <<endl;
     }


};

int main() {
    Rectangle r(32,11);
    Circle c(2);

    r.perimeter();
    c.perimeter();
}
