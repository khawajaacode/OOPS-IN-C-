#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    int pageCount;

public:
    // Default constructor
    Book() : title("Unknown"), author("Unknown"), ISBN("000-0000000000"), pageCount(0) {}

    // Parameterized constructor
    Book(string t, string a, string i, int p) : title(t), author(a), ISBN(i), pageCount(p) {}

    // Copy constructor
    Book(const Book& other) : title(other.title), author(other.author), ISBN(other.ISBN), pageCount(other.pageCount) {
        cout << "Copy constructor called!" << endl;
    }

    // Function to display book details
    void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Page Count: " << pageCount << endl;
    }
};

int main() {
    // Create a Book object using parameterized constructor
    Book book1("The Catcher in the Rye", "J.D. Salinger", "0316769487", 214);
    cout << "Original Book Details:" << endl;
    book1.displayDetails();

    // Create a copy of the Book object using the copy constructor
    Book book2(book1);
    cout << "\nCopied Book Details:" << endl;
    book2.displayDetails();

    return 0;
}
