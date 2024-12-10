#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib> // For rand() to simulate weather
using namespace std;

// Greeting System
void greetUser() {
    time_t now = time(0);
    tm *localTime = localtime(&now);
    int hour = localTime->tm_hour;

    if (hour < 12)
        cout << "Good Morning!" << endl;
    else if (hour < 18)
        cout << "Good Afternoon!" << endl;
    else
        cout << "Good Evening!" << endl;
    cout << "Welcome to your Virtual Assistant!" << endl;
}

// Task Manager
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

// Calculator
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

// Weather Simulation
void displayWeather() {
    string cities[] = {"New York", "London", "Tokyo", "Mumbai", "Paris"};
    int randomIndex = rand() % 5;
    int randomTemp = rand() % 35 + 5; // Temperature range: 5°C to 40°C

    cout << "Weather Update:" << endl;
    cout << "City: " << cities[randomIndex] << endl;
    cout << "Temperature: " << randomTemp << "°C" << endl;
    cout << "Condition: " << (randomTemp > 25 ? "Sunny" : "Cloudy") << endl;
}

// Time Tracker
void displayTime() {
    time_t now = time(0);
    tm *localTime = localtime(&now);

    cout << "Current Time: " << localTime->tm_hour << ":"
         << localTime->tm_min << ":"
         << localTime->tm_sec << endl;
}

// Main Function
int main() {
    greetUser();
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
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string task;
            cout << "Enter a task: ";
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
            cout << "Exiting Virtual Assistant. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again!" << endl;
        }
    } while (choice != 6);

    return 0;
}
