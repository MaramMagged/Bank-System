#pragma once
#include "validation.h"
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    int ID;
    string Name;
    string Password;

public:
    Person(int ID, string Name, string Password)
    {
        setID(ID);
        setName(Name);
        setPassword(Password);
    }

    int getID() { return ID; }
    string getName() { return Name; }
    string getPassword() { return Password; }

    void setID(int ID) { this->ID = ID; }
    bool setName(string Name)
    {
        if (Validation::nameValid(Name))
        {
            this->Name = Name;
            return true;
        }
        return false;
    }
    bool setPassword(string Password)
    {
        if (Validation::passValid(Password))
        {
            this->Password = Password;
            return true;
        }
        return false;
    }

    void display()
    {
        cout << "ID: " << ID << endl;
        cout << "Name: " << Name << endl;
        cout << "Password: " << Password << endl;
    }
};