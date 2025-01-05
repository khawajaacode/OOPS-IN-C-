#include<iostream>

#include<string>

using namespace std;


class Print {
    public:
   
    void show(int x) {
        cout << "Integer Value : " << x << endl;
    }

   void show(char ch) {
    cout << "Character : " << ch << endl;
   }

};

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
};


int main() {
Print p1;
// p1.show(101); Shows Interger Value.
p1.show('&');
    Calculator calc;
    cout << "Integer addition: " << calc.add(5, 10) << endl;
    cout << "Double addition: " << calc.add(5.5, 10.5) << endl;
    return 0;
}
