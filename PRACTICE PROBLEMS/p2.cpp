#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Marks{
public:    
int m1;
int m2;
int m3;
 
 void in() {
    cout << "Enter Three Marks : ";
    cin>>m1>> m2 >>m3;

 }
 int sum(){
   return m1 + m2 + m3;

 }

 double avg() {
  return (m1 + m2 + m3) / 3.0;

   
 }


};




int main()
{
  Marks Total;
    Total.in();

   cout << Total.sum() << endl;
    cout << Total.avg() << endl;

    return 0;
}