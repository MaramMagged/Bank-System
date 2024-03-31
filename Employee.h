#pragma once

#include "Person.h"

#include <iostream>
#include <string>

using namespace std;

class Employee : public Person
{
private:
    double Salary;

public:
    Employee(int ID, string Name, string Password, double Salary)
        : Person(ID, Name, Password)
    {
        setSalary(Salary);
    }

    double getSalary() { return Salary; }

    bool setSalary(double Salary)
    {
        if (Validation::minSalary(Salary))
        {
            this->Salary = Salary;
            return true;
        }
        return false;
    }

    void display()
    {
        Person::display();
        cout << "Salary: " << Salary << endl;
    }
};