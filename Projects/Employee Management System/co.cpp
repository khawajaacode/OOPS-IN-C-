#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Class for Employee
class Employee {
protected:
    int id;
    string name, role;
    float salary;

public:
    Employee(int id, string name, string role, float salary)
        : id(id), name(name), role(role), salary(salary) {}

    virtual void displayDetails() const {
        cout << "ID: " << id << ", Name: " << name 
             << ", Role: " << role << ", Salary: $" << salary << endl;
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

    virtual ~Employee() {} // Virtual destructor for polymorphism
};

// Manager Class Derived from Employee
class Manager : public Employee {
    float bonus;

public:
    Manager(int id, string name, float salary, float bonus)
        : Employee(id, name, "Manager", salary), bonus(bonus) {}

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
    Developer(int id, string name, float salary, int projectsCompleted)
        : Employee(id, name, "Developer", salary), projectsCompleted(projectsCompleted) {}

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Projects Completed: " << projectsCompleted << endl;
    }

    void calculateSalary() override {
        // Implement salary calculation based on projects completed
        salary += projectsCompleted * 100; // Example calculation
    }
};

// Intern Class Derived from Employee
class Intern : public Employee {
    string universityName;

public:
    Intern(int id, string name, float stipend, string universityName)
        : Employee(id, name, "Intern", stipend), universityName(universityName) {}

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
    vector<Employee*> employees;

public:
    // Add a new Employee
    void addEmployee(Employee* emp) {
        employees.push_back(emp);
        cout << "Employee added successfully!\n";
    }

    // Remove an Employee by ID
    void removeEmployee(int id) {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if ((*it)->getId() == id) {
                delete *it;
                employees.erase(it);
                cout << "Employee with ID " << id << " removed successfully!\n";
                return;
            }
        }
        cout << "Employee with ID " << id << " not found.\n";
    }

    // Update Employee Details
    void updateEmployeeDetails(int id, const string& name, float salary) {
        for (auto& emp : employees) {
            if (emp->getId() == id) {
                emp->setName(name);
                emp->setSalary(salary);
                cout << "Employee details updated successfully!\n";
                return;
            }
        }
        cout << "Employee with ID " << id << " not found.\n";
    }

    // Display all Employees
    void listEmployees() const {
        if (employees.empty()) {
            cout << "No employees in the system.\n";
            return;
        }
        cout << "\nEmployee List:\n";
        for (const auto& emp : employees) {
            emp->displayDetails();
            cout << "----------------------\n";
        }
    }

    ~EmployeeManagementSystem() {
        for (auto& emp : employees) delete emp;
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
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name;
                float salary, bonus;
                cout << "Enter ID, Name, Salary, and Bonus: ";
                cin >> id >> name >> salary >> bonus;
                system.addEmployee(new Manager(id, name, salary, bonus));
                break;
            }
            case 2: {
                int id, projects;
                string name;
                float salary;
                cout << "Enter ID, Name, Salary, and Projects Completed: ";
                cin >> id >> name >> salary >> projects;
                system.addEmployee(new Developer(id, name, salary, projects));
                break;
            }
            case 3: {
                int id;
                string name, university;
                float stipend;
                cout << "Enter ID, Name, Stipend, and University Name: ";
                cin >> id >> name >> stipend >> university;
                system.addEmployee(new Intern(id, name, stipend, university));
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
                cout << "Enter the ID, New Name, and New Salary of the employee: ";
                cin >> id >> name >> salary;
                system.updateEmployeeDetails(id, name, salary);
                break;
            }
            case 7:
                cout << "Exiting Employee Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
