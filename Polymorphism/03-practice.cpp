#include<iostream>
using namespace std;


class Base {
    public:
    virtual void show()  = 0;


};
class Derived:public Base{
    public:
    void show() {
        cout << "Derived class 1" <<endl;

    }

};
class Derived2:public Base{
public:
 void show() {
        cout << "Derived class 2" <<endl;

    }

};

int main(){
    Base *ptr[2];
    Derived d1;
    Derived2 d2;

    ptr[0] = &d1;
    ptr[1] = &d2;

    ptr[0]->show();
    ptr[1]->show();




}
