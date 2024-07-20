#include <iostream>
#include <string>

using namespace std;

class Book{
    public:
    int pages, price;
    string title;
  
 

    Book(int p, int pr, string t){
        pages = p;
        price = pr;
        title = t;
       
    }
     void getinfo(){
        cout <<"Pages: " << pages<<endl;
        cout << "Price: " << price<<endl;
        cout << "Title: " <<title<<endl;
     }
};


int main()
{
    Book b1(444,1000,"ALCHEMIST");

    b1.getinfo();

    Book b2(b1);
    b2.getinfo();

    

    return 0;
}