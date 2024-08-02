#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Maximum number of books and users
#define MAX_BOOKS 10
#define MAX_USERS 5

// Book class to represent each book
class Book {
private:
    string title;         // Title of the book
    bool isAvailable;    // Availability status of the book

public:
    // Constructor with optional title and availability parameters
    Book(string t = "", bool avail = true) : title(t), isAvailable(avail) {}

    // Getters for book properties
    string getTitle() const { return title; }
    bool getAvailability() const { return isAvailable; }

    // Methods to borrow and return the book
    void borrow() { isAvailable = false; }
    void returnBook() { isAvailable = true; }

    // Save book details to file
    void save(ofstream &outFile) const {
        outFile << title << "\n" << isAvailable << "\n";
    }

    // Load book details from file
    void load(ifstream &inFile) {
        getline(inFile, title);
        inFile >> isAvailable;
        inFile.ignore(); // Ignore the newline character left in the buffer
    }
};

// User class to represent each user
class User {
private:
    string name;           // Name of the user
    Book* borrowedBook;   // Pointer to the borrowed book

public:
    // Constructor with optional name parameter
    User(string n = "") : name(n), borrowedBook(nullptr) {}

    // Getter for user name
    string getName() const { return name; }

    // Method to borrow a book
    void borrowBook(Book &book) {
        if (book.getAvailability() && borrowedBook == nullptr) {
            borrowedBook = &book;
            book.borrow();
            cout << name << " borrowed " << book.getTitle() << endl;
        } else {
            cout << (borrowedBook ? "Already borrowed a book." : "Book is not available.") << endl;
        }
    }

    // Method to return a book
    void returnBook() {
        if (borrowedBook) {
            borrowedBook->returnBook();
            cout << name << " returned " << borrowedBook->getTitle() << endl;
            borrowedBook = nullptr;
        } else {
            cout << "No book to return." << endl;
        }
    }
};

// Function to display all available books
void displayBooks(const Book books[], int bookCount) {
    cout << "\nAvailable Books:\n";
    for (int i = 0; i < bookCount; ++i) {
        cout << (books[i].getAvailability() ? "[Available] " : "[Not Available] ") 
             << books[i].getTitle() << endl;
    }
}

int main() {
    Book books[MAX_BOOKS] = {
        Book("To Kill a Mockingbird"),
        Book("1984"),
        Book("The Great Gatsby"),
        Book("One Hundred Years of Solitude"),
        Book("Pride and Prejudice"),
        Book("The Catcher in the Rye"),
        Book("The Hobbit"),
        Book("Fahrenheit 451"),
        Book("Brave New World"),
        Book("Moby-Dick")
    }; // Initialize books directly with famous titles

    User users[MAX_USERS];   // Array to store users
    int bookCount = 10;      // Number of books
    int userCount = 0;       // Counter for users

    // Directly display books when the program starts
    displayBooks(books, bookCount);

    while (true) {
        // Menu for user choices
        cout << "\n1. Register User\n2. Borrow Book\n3. Return Book\n4. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the buffer

        if (choice == 1) {
            // Register a new user
            if (userCount >= MAX_USERS) {
                cout << "Cannot register more users." << endl;
                continue;
            }
            string name;
            cout << "Enter user name: ";
            getline(cin, name);
            users[userCount++] = User(name);
            cout << "User registered." << endl;

        } else if (choice == 2) {
            // Borrow a book
            string userName, bookTitle;
            cout << "Enter user name: ";
            getline(cin, userName);
            cout << "Enter book title: ";
            getline(cin, bookTitle);

            User* user = nullptr;
            Book* book = nullptr;
            // Find the user
            for (int i = 0; i < userCount; ++i) {
                if (users[i].getName() == userName) {
                    user = &users[i];
                    break;
                }
            }
            // Find the book
            for (int i = 0; i < bookCount; ++i) {
                if (books[i].getTitle() == bookTitle) {
                    book = &books[i];
                    break;
                }
            }

            if (user && book) {
                user->borrowBook(*book);
            } else {
                cout << "User or book not found." << endl;
            }

        } else if (choice == 3) {
            // Return a book
            string userName;
            cout << "Enter user name: ";
            getline(cin, userName);

            User* user = nullptr;
            // Find the user
            for (int i = 0; i < userCount; ++i) {
                if (users[i].getName() == userName) {
                    user = &users[i];
                    break;
                }
            }

            if (user) {
                user->returnBook();
            } else {
                cout << "User not found." << endl;
            }

        } else if (choice == 4) {
            // Exit the program
            cout << "Exiting program." << endl;
            break;

        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
