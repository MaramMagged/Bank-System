#pragma once

#include <iostream>

#include "Employee.h"
#include "Client.h"
#include "helperClass.h"

using namespace std;

class Admin : public Employee
{
private:
    static inline int numberOfAdmins = 33000;
    double Salary;

public:
    Admin(string Name, string Password, double Salary)
        : Employee(Name, Password, Salary)
    {
        this->setID(++numberOfAdmins);
        Employee::numberOfEmployees--;
    }

    void SetSalary(double Salary)
    {
        this->Salary = Salary;
    }

    void addEmployee(Employee employee) // New
    {
        Employee::AllEmployees.push_back(employee);
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
            if (Employee::AllEmployees[i].getID() == id)
            {
                return &Employee::AllEmployees[i];
            }
        }
        return nullptr;
    }
};
