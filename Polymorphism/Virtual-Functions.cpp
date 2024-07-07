#include<iostream>

#include<string>

using namespace std;


class Parent {
public: 
void getinfo() {
    cout << "Parent Class.\n";
}
virtual void hello() {
    cout << "Hello From parent.\n";
}
};
class Child : public Parent {
    public:
  void  getinfo() {
    cout << "Child Class.\n";
}
 void hello() {
    cout << "Hello From Child.\n";
 }

};



int main() {
    Child c1;
    // Parent p1; 
    c1.hello();
    return 0;
}
