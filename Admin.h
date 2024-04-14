#pragma once
#include <iostream>
#include "Employee.h"
#include "Client.h"
#include "HelperClass.h"

using namespace std;

class Admin : public Employee
{
private:
    double Salary;

public:
    Admin(int ID, string Name, string Password, double Salary)
        : Employee(ID, Name, Password, Salary) {}

    void SetSalary(double Salary)
    {
        this->Salary = Salary;
    }

    void addClient(Client *client) // New
    {
        Employee::addClient(client); // New
    }
    void listClient(int id) // New
    {
        Employee::listClient(id);
    }
    void editClient(int id, string Name, string Password, double Balance) // New
    {
        Employee::editClient(id, Name, Password, Balance);
    }

    void addEmployee(Employee employee) // New
    {
        Employee::addClient(&employee);
        cout << " Employee added successfully ." << endl;
    }
    void listEmployee(int id) // New
    {
        Employee *e = searchEmployee(id);
        if (e != nullptr)
        {
            e->display();
        }
        else
        {
            cout << "Employee not found" << endl;
        }
    }
    void editEmployee(int id, string Name, string Password, double Salary)
    {
        Employee *e = searchEmployee(id);
        if (e != nullptr)
        {
            if (e->setPassword(Name) && e->setPassword(Password) && e->setSalary(Salary))
            {
                cout << "Employee updated successfully" << endl;
            }
            else
            {
                cout << " Invalid employee information ." << endl;
            }
        }
        else
        {
            cout << "Employee not found" << endl;
        }
    }
    Employee *searchEmployee(int id)
    {
        for (auto i = 0; i < Client::AllClients.size(); i++)
        {
            if (Employee::AllClients[i]->getID() == id)
            {
                return &Employee::AllClients[i];
            }
        }
        return nullptr;
    }
};
