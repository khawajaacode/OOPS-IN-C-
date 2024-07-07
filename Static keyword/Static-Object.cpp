#include<iostream>

#include <string>

using namespace std;


class ABC{
public:
ABC(){
    cout << "Constructor\n";
}
~ABC(){
    cout << "Destructor.\n";
}
};

int main() {
    if(true){
        static ABC obj;

    }
    cout << "End of Main Function";
}