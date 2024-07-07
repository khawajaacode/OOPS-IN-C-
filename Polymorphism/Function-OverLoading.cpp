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




int main() {
Print p1;
// p1.show(101); Shows Interger Value.
p1.show('&');

    return 0;
}
