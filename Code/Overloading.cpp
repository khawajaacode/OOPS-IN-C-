#include<iostream>
#include<fstream>

using namespace std;

// class Area1{
//     public:


//     int area(int l, int w)  {
//         return l*w;
//     }
//      float area(float a, float b) {
//         return a *b;
//     }
// };

// int main() {


// Area1 a;
// cout << a.area(2, 3);
// cout <<a.area(4.0,3.9);

// }


class Shape {

    public:

    virtual void draw() = 0;



};
class Circle :  public Shape{

    public:
    void draw() {
        cout << "Circle" << endl;

    }
};

class Rectangle: public Shape {

    public:
    void draw() {
        cout << "Rectangle" <<endl;

    }
};


int main() {
    // Circle c1;   

   // c1.draw();

    // int x=2, y=0, z;

    // try
    // {
    //     if (y==0)
    //     {
    //        throw "STRING";

    //     }

    //     z= x/y;
    //     cout << z <<endl;
        
    // }
    // catch(string e)
    // {
    //   cout  << e<< '\n';
    // }
    
    // cout << "Program Continiue";


   
    

































    return 0;

}

