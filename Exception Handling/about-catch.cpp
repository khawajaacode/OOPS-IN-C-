#include <iostream>
using namespace std;


class MyException1 : public exception{};

class MyException2 : public MyException1{};

int main() {

    int x = 10, y =0, z;

    try
    {
        throw MyException1();//string("1.5");
    }
    catch(int e) // catch int
    {
        cout << "Catch Int " << '\n';
    }
    catch(double e) // catch type double
    {
        cout << "Double Catch" << endl;
    }

    catch(char e){
        cout << "Catch char" <<endl;
    }


    catch(MyException2) {
        cout << "Catch MyException 2 class";
    }

     catch(MyException1) {
        cout << "Catch MyException 1 class";
    }

    


   // catch(...){
   //     cout << "Catch all  " << endl;
   // }
}
