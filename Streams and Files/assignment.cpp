#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // For formatting output
using namespace std;

class Student {
private:
    int id;
    char name[50];
    float marks;

public:
    // Constructor
    Student() : id(0), marks(0.0f) {
        name[0] = '\0'; // Initialize name as empty
    }

    // Input details
    void inputDetails() {
        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore(); // Clear input buffer
        cout << "Enter Student Name: ";
        cin.getline(name, 50);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    // Display details
    void displayDetails() const {
        cout << "ID: " << id << ", Name: " << name << ", Marks: " << fixed << setprecision(2) << marks << endl;
    }

    // Get student ID
    int getId() const {
        return id;
    }

    // Write to binary file
    void writeToFile(ofstream &outFile) const {
        outFile.write(reinterpret_cast<const char*>(this), sizeof(Student));
    }

    // Read from binary file
    void readFromFile(ifstream &inFile) {
        inFile.read(reinterpret_cast<char*>(this), sizeof(Student));
    }
};

// Function to write multiple students to a file
void writeStudentsToFile() {
    ofstream outFile("students.dat", ios::binary | ios::trunc); // Overwrite file
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    int n;
    cout << "Enter number of students to write: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Student s;
        s.inputDetails();
        s.writeToFile(outFile);
    }

    outFile.close();
    cout << "Students written to file successfully." << endl;
}

// Function to read and display all students from a file
void readStudentsFromFile() {
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    Student s;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        s.displayDetails();
    }

    inFile.close();
}

// Function to search for a student by ID
void searchStudentById() {
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cerr << "Error opening file for searching!" << endl;
        return;
    }

    int searchId;
    cout << "Enter ID to search: ";
    cin >> searchId;

    Student s;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.getId() == searchId) {
            cout << "Student found:" << endl;
            s.displayDetails();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << searchId << " not found." << endl;
    }

    inFile.close();
}

// Function to append a new student to the file
void appendStudentToFile() {
    ofstream outFile("students.dat", ios::binary | ios::app);
    if (!outFile) {
        cerr << "Error opening file for appending!" << endl;
        return;
    }

    Student s;
    s.inputDetails();
    s.writeToFile(outFile);

    outFile.close();
    cout << "Student appended to file successfully." << endl;
}

int main() {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Write Students to File\n";
        cout << "2. Read Students from File\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Append Student to File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeStudentsToFile();
                break;
            case 2:
                readStudentsFromFile();
                break;
            case 3:
                searchStudentById();
                break;
            case 4:
                appendStudentToFile();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
