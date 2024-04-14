#pragma once

#include "Person.h"
#include <iostream>
#include <string>
#include <vector>
#include "helperClass.h"
#include "Client.h"

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
                cout << " Clientinformation updated successfully." << endl;
            }
            else
            {
                cout << " invalid  client information ." << endl;
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
    //****************************************
    string serialize()
    {
        return to_string(ID) + "&" + Name + "&" + Password + "&" + to_string(Salary);
    }
    void deserialize(string &line)
    {
        vector<string> tokens = Parser::split(line, '&');
        ID = stoi(tokens[0]);
        Name = tokens[1];
        Password = tokens[2];
        Salary = stod(tokens[3]);
    }
    void display()
    {
        Person::display();
        cout << "Salary : " << Salary << endl;
    }
};