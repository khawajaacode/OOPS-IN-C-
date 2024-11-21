#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.5, 2.5);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;

    cout << "c1: "; c1.display();
    cout << "c2: "; c2.display();
    cout << "c3 (c1 + c2): "; c3.display();
    cout << "c4 (c1 - c2): "; c4.display();
    return 0;
}
