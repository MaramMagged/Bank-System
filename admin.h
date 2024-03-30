#pragma once
#include <iostream>
#include "person.h"

using namespace std;

class Admin : public Person
{

public:
    Admin(string Name, string Password, double Balance)
        : Person(0, Name, Password, Balance) {}
    string getName()
    {
        return Name;
    }
    string getPassword()
    {
        return Password;
    }
    double getBalance()
    {
        return Balance;
    }
    void setName(string Name)
    {
        this->Name = Name;
    }
    void setPassword(string Password)
    {
        this->Password = Password;
    }
    void setBalance(double Balance)
    {
        this->Balance = Balance;
    }
    void display()
    {
        cout << "Name: " << Name << endl;
        cout << "Password: " << Password << endl;
        cout << "Balance: " << Balance << endl;
    }
};
