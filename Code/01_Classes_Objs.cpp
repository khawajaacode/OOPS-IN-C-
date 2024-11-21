#include<iostream>
using namespace std;


class Book{

private:
string title;
string author;
float price;

public:

void set(){
    cout << "Enter the Book title "; getline(cin, title);
    cout << "Enter the Book Author "; getline(cin, author); 
    cout << "Enter Price "; cin >> price;

}   

void get(){
    cout << "The Title of Book is " << title <<endl;
    cout << "The Author of Book is " << author <<endl;
    cout << "The Price of Book is " << price <<endl;
}

};

int main() {
    Book b;
    b.set();
    b.get();
}