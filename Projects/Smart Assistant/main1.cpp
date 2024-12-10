#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib> // For rand() to simulate weather
using namespace std;

// --- GLOBAL VARIABLES ---
bool isDarkMode = false; // Dark mode toggle

// --- AUTHENTICATION ---
bool authenticate() {
    string username, password;
    string storedUsername = "admin", storedPassword = "1234";

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (username == storedUsername && password == storedPassword) {
        cout << "Login Successful!\n";
        return true;
    } else {
        cout << "Invalid Credentials!\n";
        return false;
    }
}

// --- PERSONALIZATION ---
string getUserName() {
    ifstream file("username.txt");
    string name;
    if (file.is_open() && getline(file, name)) {
        file.close();
        return name;
    } else {
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        ofstream outFile("username.txt");
        outFile << name;
        outFile.close();
        return name;
    }
}

// --- GREETING SYSTEM ---
void greetUser(const string &name) {
    time_t now = time(0);
    tm *localTime = localtime(&now);
    int hour = localTime->tm_hour;

    if (hour < 12)
        cout << "Good Morning, " << name << "!" << endl;
    else if (hour < 18)
        cout << "Good Afternoon, " << name << "!" << endl;
    else
        cout << "Good Evening, " << name << "!" << endl;

    cout << "Welcome to your Virtual Assistant!" << endl;
}

// --- TASK MANAGER ---
class TaskManager {
public:
    void addTask(const string &task) {
        ofstream file("tasks.txt", ios::app);
        if (file.is_open()) {
            file << task << endl;
            file.close();
            cout << "Task added successfully!" << endl;
        } else {
            cout << "Error: Unable to open the file!" << endl;
        }
    }

    void viewTasks() {
        ifstream file("tasks.txt");
        string task;
        if (file.is_open()) {
            cout << "Your Tasks:" << endl;
            while (getline(file, task)) {
                cout << "- " << task << endl;
            }
            file.close();
        } else {
            cout << "No tasks found!" << endl;
        }
    }
};

// --- CALCULATOR ---
class Calculator {
public:
    void performCalculation() {
        double num1, num2;
        char operation;
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter an operator (+, -, *, /): ";
        cin >> operation;
        cout << "Enter the second number: ";
        cin >> num2;

        switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error: Division by zero!" << endl;
            break;
        default:
            cout << "Invalid operator!" << endl;
        }
    }
};

// --- WEATHER SIMULATION ---
void displayWeather() {
    string cities[] = {"New York", "London", "Tokyo", "Mumbai", "Paris"};
    string conditions[] = {"Sunny", "Rainy", "Snowy", "Windy", "Cloudy"};
    int randomCity = rand() % 5;
    int randomTemp = rand() % 35 + 5; // 5°C to 40°C
    int randomCondition = rand() % 5;

    cout << "Weather Update:\n";
    cout << "City: " << cities[randomCity] << endl;
    cout << "Temperature: " << randomTemp << "°C" << endl;
    cout << "Condition: " << conditions[randomCondition] << endl;
}

// --- TIME TRACKER ---
void displayTime() {
    time_t now = time(0);
    tm *localTime = localtime(&now);

    cout << "Current Time: " << localTime->tm_hour << ":"
         << localTime->tm_min << ":"
         << localTime->tm_sec << endl;
}

// --- NOTES FEATURE ---
void saveNote() {
    ofstream file("notes.txt", ios::app);
    string note;
    cout << "Write your note: ";
    cin.ignore();
    getline(cin, note);
    file << note << endl;
    file.close();
    cout << "Note saved successfully!\n";
}

void viewNotes() {
    ifstream file("notes.txt");
    string note;
    cout << "Your Notes:\n";
    while (getline(file, note)) {
        cout << "- " << note << endl;
    }
    file.close();
}

// --- GUESSING GAME ---
void playGuessingGame() {
    int number = rand() % 100 + 1;
    int guess;
    cout << "Guess the number (1-100): ";
    while (true) {
        cin >> guess;
        if (guess < number) {
            cout << "Too low! Try again: ";
        } else if (guess > number) {
            cout << "Too high! Try again: ";
        } else {
            cout << "Congratulations! You guessed it!\n";
            break;
        }
    }
}

// --- DARK MODE TOGGLE ---
void toggleDarkMode() {
    isDarkMode = !isDarkMode;
    cout << (isDarkMode ? "Dark Mode Enabled" : "Light Mode Enabled") << endl;
}

// --- MAIN FUNCTION ---
int main() {
    if (!authenticate()) return 0;

    string userName = getUserName();
    greetUser(userName);

    TaskManager taskManager;
    Calculator calculator;

    int choice;
    do {
        cout << "\n--- Virtual Assistant Menu ---" << endl;
        cout << "1. Add a Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Use Calculator" << endl;
        cout << "4. Display Weather Update" << endl;
        cout << "5. Display Current Time" << endl;
        cout << "6. Save a Note" << endl;
        cout << "7. View Notes" << endl;
        cout << "8. Play Guessing Game" << endl;
        cout << "9. Toggle Dark Mode" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string task;
            cout << "Enter a task: ";
            cin.ignore();
            getline(cin, task);
            taskManager.addTask(task);
            break;
        }
        case 2:
            taskManager.viewTasks();
            break;
        case 3:
            calculator.performCalculation();
            break;
        case 4:
            displayWeather();
            break;
        case 5:
            displayTime();
            break;
        case 6:
            saveNote();
            break;
        case 7:
            viewNotes();
            break;
        case 8:
            playGuessingGame();
            break;
        case 9:
            toggleDarkMode();
            break;
        case 10:
            cout << "Exiting Virtual Assistant. Goodbye, " << userName << "!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again!" << endl;
        }
    } while (choice != 10);

    return 0;
}
