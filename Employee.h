#pragma once
#include "person.h"
#include "client.h"
#include <iostream>
#include <string>

using namespace std;

class Employee : public Person
{

public:
    Employee(string Name, string Password, double Blance)
        : Person(0, Name, Password, Blance) {}
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
        cout << Name << endl;
        cout << Password << endl;
        cout << Balance << endl;
    }
};
int main(){};