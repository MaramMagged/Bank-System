#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <string>

#include "Person.h"
#include "validation.h"
#include "helperClass.h"

using namespace std;

class Client : public Person
{
private:
    static inline int numberOfClients = 11000;
    double Balance;

public:
    Client(string Name, string Password, double Balance)
        : Person(Name, Password)
    {
        this->setID(++numberOfClients);
        setBalance(Balance);
    }

    double getBalance() { return Balance; }

    bool setBalance(double Balance)
    {
        if (Validation::minBalance(Balance))
        {
            this->Balance = Balance;
            return true;
        }
        return false;
    }

    void deposit(double amount)
    {
        setBalance(getBalance() + amount);
        cout << "Deposited successfully." << endl;
    }

    void withdraw(double amount)
    {
        setBalance(getBalance() - amount);
        cout << "Withdrawn successfully." << endl;
    }
    void transferTo(double amount, Client &recipient)
    {
        if (amount <= 0)
        {
            cout << "Invalid transfer amount." << endl;
            return;
        }
        if (amount > getBalance())
        {
            cout << "Insufficient blance for transfer." << endl;
        }
        else
        {
            setBalance(getBalance() - amount);
            {
                recipient.setBalance(recipient.getBalance() + amount);
                cout << "Transferred successfully to ."
                     << recipient.getName() << "." << endl;
            }
        }
    }

    void CheckBalance()
    {
        cout << "Current balance : " << getBalance() << endl;
    }

    string serialize()
    {
        return getName() + "&" + getPassword() + "&" + to_string(getBalance());
    }

    void deserialize(string &line)
    {
        vector<string> tokens = Helper::split(line, '&');

        setName(tokens[0]);
        setPassword(tokens[1]);
        setBalance(stod(tokens[2]));
    }

    void display()
    {
        Person::display();
        cout << "Balance : " << Balance << endl;
    }

    static inline vector<Client> AllClients = {};
};
