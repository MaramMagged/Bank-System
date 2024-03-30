#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    int ID;
    string Name;
    string Password;
    double Balance;

public:
    Person(int ID, string Name, string Password, double Balance)

    {
        this->ID = ID;
        this->Name = Name;
        this->Password = Password;
        this->Balance = Balance;
    }
    int getID() { return ID; }
    string getName() { return Name; }
    string getPassword() { return Password; }
    double getBalance() { return Balance; }

    void setID(int ID) { this->ID = ID; }
    void setName(string Name) { this->Name = Name; }
    void setPassword(string Password) { this->Password = Password; }
    void setBalance(double Balance)
    {
        this->Balance = Balance;
    }
    void display()
    {
        cout << "ID: " << ID << endl;
        cout << "Name: " << Name << endl;
        cout << "Password: " << Password << endl;
        cout << "Balance: " << Balance << endl;
    }
};
int main()
{
    return 0;
}