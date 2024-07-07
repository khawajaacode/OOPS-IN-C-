#include<iostream>

#include<string>

using namespace std;


class Parent {
public: 
void getinfo() {
    cout << "Parent Class.\n";
}
};
class Child : public Parent {
    public:
  void  getinfo() {
    cout << "Child Class.\n";
}

};



int main() {
    Child c1;
    // Parent p1; 
    c1.getinfo();
    return 0;
}
