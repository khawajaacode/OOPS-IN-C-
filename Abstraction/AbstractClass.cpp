#include<iostream>

#include <string>

using namespace std;

class Shape { // Abstract Class
virtual void draw() = 0; // pure Virtual Function
};

class Circle : public Shape{
    public:
    void draw() {
        cout << "Drawing A Circle.\n";
    }
};
int main(){
Circle c1;
c1.draw();

    return 0;
}