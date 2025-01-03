#include <iostream>
#include <string>
using namespace std;

// Base Class for Employee
class Employee {
protected:
    int id;
    string name, role;
    float salary;
    string performanceReview;

public:
    Employee(int id, string name, string role, float salary, string performanceReview)
        : id(id), name(name), role(role), salary(salary), performanceReview(performanceReview) {}

    virtual void displayDetails() const {
        cout << "ID: " << id << ", Name: " << name 
             << ", Role: " << role << ", Salary: $" << salary 
             << ", Performance Review: " << performanceReview << endl;
    }

    virtual void calculateSalary() = 0; // Pure virtual function

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    void setName(const string& name) {
        this->name = name;
    }

    float getSalary() const {
        return salary;
    }

    void setSalary(float salary) {
        this->salary = salary;
    }

    string getPerformanceReview() const {
        return performanceReview;
    }

    void setPerformanceReview(const string& performanceReview) {
        this->performanceReview = performanceReview;
    }

    virtual ~Employee() {} // Virtual destructor for polymorphism
};

// Manager Class Derived from Employee
class Manager : public Employee {
    float bonus;

public:
    Manager(int id, string name, float salary, float bonus, string performanceReview)
        : Employee(id, name, "Manager", salary, performanceReview), bonus(bonus) {}

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Bonus: $" << bonus << endl;
    }

    void calculateSalary() override {
        salary += bonus;
    }
};

// Developer Class Derived from Employee
class Developer : public Employee {
    int projectsCompleted;

public:
    Developer(int id, string name, float salary, int projectsCompleted, string performanceReview)
        : Employee(id, name, "Developer", salary, performanceReview), projectsCompleted(projectsCompleted) {}

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Projects Completed: " << projectsCompleted << endl;
    }

    void calculateSalary() override {
        salary += projectsCompleted * 100; // Example calculation
    }
};

// Intern Class Derived from Employee
class Intern : public Employee {
    string universityName;

public:
    Intern(int id, string name, float stipend, string universityName, string performanceReview)
        : Employee(id, name, "Intern", stipend, performanceReview), universityName(universityName) {}

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "University: " << universityName << endl;
    }

    void calculateSalary() override {
        // Implement stipend calculation if needed
    }
};

// Employee Management System Class
class EmployeeManagementSystem {
    Employee* employees[100]; // Fixed array of Employee pointers
    int employeeCount;

public:
    EmployeeManagementSystem() : employeeCount(0) {}

    // Add a new Employee
    void addEmployee(Employee* emp) {
        if (employeeCount < 100) {
            employees[employeeCount++] = emp;
            cout << "Employee added successfully!\n";
        } else {
            cout << "Employee list is full!\n";
        }
    }

    // Remove an Employee by ID
    void removeEmployee(int id) {
        for (int i = 0; i < employeeCount; ++i) {
            if (employees[i]->getId() == id) {
                delete employees[i];
                for (int j = i; j < employeeCount - 1; ++j) {
                    employees[j] = employees[j + 1];
                }
                employees[--employeeCount] = nullptr;
                cout << "Employee with ID " << id << " removed successfully!\n";
                return;
            }
        }
        cout << "Employee with ID " << id << " not found.\n";
    }

    // Update Employee Details
    void updateEmployeeDetails(int id, const string& name, float salary, const string& performanceReview) {
        for (int i = 0; i < employeeCount; ++i) {
            if (employees[i]->getId() == id) {
                employees[i]->setName(name);
                employees[i]->setSalary(salary);
                employees[i]->setPerformanceReview(performanceReview);
                cout << "Employee details updated successfully!\n";
                return;
            }
        }
        cout << "Employee with ID " << id << " not found.\n";
    }

    // Display all Employees
    void listEmployees() const {
        if (employeeCount == 0) {
            cout << "No employees in the system.\n";
            return;
        }
        cout << "\nEmployee List:\n";
        for (int i = 0; i < employeeCount; ++i) {
            employees[i]->displayDetails();
            cout << "----------------------\n";
        }
    }

    // Generate a report of all employees
    void generateReport() const {
        if (employeeCount == 0) {
            cout << "No employees in the system.\n";
            return;
        }
        cout << "\nEmployee Report:\n";
        for (int i = 0; i < employeeCount; ++i) {
            employees[i]->displayDetails();
            employees[i]->calculateSalary(); // Ensure salary is up-to-date
            cout << "----------------------\n";
        }
    }

    ~EmployeeManagementSystem() {
        for (int i = 0; i < employeeCount; ++i) {
            delete employees[i];
        }
    }
};

// Main Function
int main() {
    EmployeeManagementSystem system;
    int choice;

    do {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Manager\n";
        cout << "2. Add Developer\n";
        cout << "3. Add Intern\n";
        cout << "4. List Employees\n";
        cout << "5. Remove Employee\n";
        cout << "6. Update Employee Details\n";
        cout << "7. Generate Report\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name;
                float salary, bonus;
                string performanceReview;
                cout << "Enter ID, Name, Salary, Bonus, and Performance Review: ";
                cin >> id >> name >> salary >> bonus >> performanceReview;
                system.addEmployee(new Manager(id, name, salary, bonus, performanceReview));
                break;
            }
            case 2: {
                int id, projects;
                string name;
                float salary;
                string performanceReview;
                cout << "Enter ID, Name, Salary, Projects Completed, and Performance Review: ";
                cin >> id >> name >> salary >> projects >> performanceReview;
                system.addEmployee(new Developer(id, name, salary, projects, performanceReview));
                break;
            }
            case 3: {
                int id;
                string name, university;
                float stipend;
                string performanceReview;
                cout << "Enter ID, Name, Stipend, University Name, and Performance Review: ";
                cin >> id >> name >> stipend >> university >> performanceReview;
                system.addEmployee(new Intern(id, name, stipend, university, performanceReview));
                break;
            }
            case 4:
                system.listEmployees();
                break;
            case 5: {
                int id;
                cout << "Enter the ID of the employee to remove: ";
                cin >> id;
                system.removeEmployee(id);
                break;
            }
            case 6: {
                int id;
                string name;
                float salary;
                string performanceReview;
                cout << "Enter the ID, New Name, New Salary, and New Performance Review of the employee: ";
                cin >> id >> name >> salary >> performanceReview;
                system.updateEmployeeDetails(id, name, salary, performanceReview);
                break;
            }
            case 7:
                system.generateReport();
                break;
            case 8:
                cout << "Exiting Employee Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}