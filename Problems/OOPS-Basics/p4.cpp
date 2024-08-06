#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class Book {
private:
    int bookID;  
    int bookPages; 
    double price;  

public:
    void get() {
        cout << "Book ID: ";
        cin >> bookID;
        cout << "Book Pages: ";
        cin >> bookPages;
        cout << "Price: ";
        cin >> price;
    }

    void show() {
        cout << "Book ID: " << bookID << endl;
        cout << "Book Pages: " << bookPages << endl;
        cout << "Price: " << price << fixed << setprecision(2) << endl; // Format price to 2 decimal places
    }

    double getPrice() const { 
        return price;
    }

    void set(int id, int pg, double pr) {  
        bookID = id;
        bookPages = pg;
        price = pr;
    }
};

int main() {
    Book b1, b2;
    b1.get();
    b2.set(3, 500, 696.0); 

    cout << "The Detail of Costly Book is as Follows" << endl;
    if (b1.getPrice() > b2.getPrice()) {
        b1.show();
    } else {
        b2.show();
    }

    return 0;
}
