#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "helperClass.h"
#include "Client.h"
#include "Person.h"

using namespace std;

class Employee : public Person
{
private:
    double Salary;

protected:
    static inline int numberOfEmployees = 22000;

public:
    Employee(string Name, string Password, double Salary)
        : Person(Name, Password)
    {
        this->setID(++numberOfEmployees);
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
    void addClient(Client client)
    {
        Client::AllClients.push_back(client);
    }
    void listClient(int id)
    {
        Client *c = searchClient(id);
        if (c != nullptr)
        {
            c->display();
        }
        else
        {
            cout << " Client not found. " << endl;
        }
    }
    void editClient(int id, string name, string password, double balance)
    {
        Client *c = searchClient(id);
        if (c != nullptr)
        {
            if (c->setName(name) && c->setPassword(password) && c->setBalance(balance))
            {
                cout << " Client information updated successfully." << endl;
            }
            else
            {
                cout << " invalid client information ." << endl;
            }
        }
        else
        {
            cout << " Client not found. " << endl;
        }
    }

    Client *searchClient(int id)
    {
        for (auto i = 0; i < Client::AllClients.size(); i++)
        {
            if (Client::AllClients[i].getID() == id)
            {
                return &Client::AllClients[i];
            }
        }
        return nullptr;
    }

    string serialize()
    {
        return getName() + "&" + getPassword() + "&" + to_string(getSalary());
    }
    void deserialize(string &line)
    {
        vector<string> tokens = Helper::split(line, '&');

        setName(tokens[0]);
        setPassword(tokens[1]);
        setSalary(stod(tokens[2]));
    }

    static inline vector<Employee> AllEmployees = {};
};