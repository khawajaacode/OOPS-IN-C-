#include <iostream>
#include <string>
#include <vector>

using namespace std;

class employee
{
private:
    int ID;
    string name;
    string role;
    float salary;

public:
    employee(int ID, string name, string role, float salary) : ID(ID), name(name), role(role), salary(salary) {};

    void set_ID(int id)
    {
        ID = id;
    }

    void set_name(string nam)
    {
        name = nam;
    }

    void set_role(string rol)
    {
        role = rol;
    }

    void set_salary(float salar)
    {
        salary = salar;
    }

    void printDetail() const
    {
        cout << "ID :" << ID << endl;
        cout << "name :" << name << endl;
        cout << "role :" << role << endl;
        cout << "salary :" << salary << endl;
    }

    int get_ID() const
    {
        return ID;
    }

    string get_name() const
    {
        return name;
    }

    string get_role() const
    {
        return role;
    }

    float get_salary() const
    {
        return salary;
    }
};

class EmployeeManagement
{
private:
    vector <employee> employees;
public:
    void add_employee()
    {
        int temp_ID;
        string temp_name, temp_role;
        float temp_salary;
        cout << "Enter Employee name :";
        getline(cin >> ws, temp_name);
        cout << "Enter " << temp_name << " ID :";
        cin >> temp_ID;
        cout << "Enter " << temp_name << " role :";
        getline(cin >> ws, temp_role);
        cout << "Enter " << temp_name << " salary :";
        cin >> temp_salary;

        employees.emplace_back(temp_ID, temp_name, temp_role, temp_salary);

        cout << endl;
    }

    void remove_employee()
    {
        int id;
        cout << "Enter the ID of employee you want to remove:";
        cin >> id;
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].get_ID() == id)
            {
                int temp;
                cout << "Do you want to remove employee " << employees[i].get_name() << " enter 1 for yes :";
                cin >> temp;
                if (temp == 1)
                {
                    employees.erase(employees.begin() + i);
                    cout << "the employee has been removed\n";
                }
                else
                {
                    cout << employees[i].get_name() << "is not removed\n";
                }
                break;
            }
        }
    }

    void update_employee()
    {
        int id;
        cout << "Enter the ID of employee you want to update:";
        cin >> id;
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].get_ID() == id)
            {
                do
                {
                    int temp, temp_ID;
                    string temp_name, temp_role;
                    float temp_salary;
                    cout << "What do you want to update.\nEnter 1 for ID ,2 for name,3 for role,4 for salary\nEnter your choice here :";
                    cin >> temp;
                    if (temp == 1)
                    {
                        cout << "Current ID:" << employees[i].get_ID() << "\nEnter updated ID: ";
                        cin >> temp_ID;
                        employees[i].set_ID(temp_ID);
                        cout << "ID updated";
                    }
                    else if (temp == 2)
                    {
                        cout << "Current name:" << employees[i].get_name() << "\nEnter updated name: ";
                        getline(cin >> ws, temp_name);
                        employees[i].set_name(temp_name);
                        cout << "name updated";
                    }
                    else if (temp == 3)
                    {
                        cout << "Current role:" << employees[i].get_role() << "\nEnter updated role: ";
                        getline(cin >> ws, temp_role);
                        employees[i].set_role(temp_role);
                        cout << "role updated";
                    }
                    else if (temp == 4)
                    {
                        cout << "Current salary:" << employees[i].get_salary() << "\nEnter updated salary: ";
                        cin >> temp_salary;
                        employees[i].set_salary(temp_salary);
                        cout << "salary updated";
                    }
                    else
                    {
                        cout << "No changes done.";
                    }
                    cout << "do you want to change something else\nIf yes enter 1: ";
                    cin >> temp;
                    if (temp != 1)
                    {
                        break;
                    }

                } while (true);
            }
        }
    }

    void employee_list()
    {
        for (int i = 0; i < employees.size(); i++)
        {
            employees[i].printDetail();
            cout << endl;
        }
    }

    void print_detail()
    {
        int temp;
        cout << "Enter ID of the employee you want to print details";
        cin >> temp;
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].get_ID() == temp)
            {
                employees[i].printDetail();
            }
        }
    }
};





int main()
{
    EmployeeManagement a1;
    int flag;
    while (true) {
        cout << "What do you want to do.\nEnter 1 to add an employee\nEnter 2 to remove an employee\nEnter 3 to update an employee\nEnter 4 to print details of specific employee\nEnter 5 to print detail of all employee\nEnter your choice here :";
        cin >> flag;
        switch (flag)
        {
        case 1:
            a1.add_employee();
            break;
        case 2:
            a1.remove_employee();
            break;
        case 3:
            a1.update_employee();
            break;
        case 4:
            a1.print_detail();
            break;
        case 5:
            a1.employee_list();
            break;
        default:
            break;
        }
        cout << "\nDo you want to do anything else\nEnter 1 for yes :";
        cin >> flag;
        cout << endl;
        if (flag!=1)
        {
            break;
        }
    }
    return 0;
}
