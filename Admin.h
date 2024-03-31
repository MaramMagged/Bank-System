#pragma once
#include <iostream>
#include "Employee.h"

using namespace std;

class Admin : public Employee
{
private:
    double Salary;

public:
    Admin(int ID, string Name, string Password, double Salary)
        : Employee(ID, Name, Password, Salary) {}
};
