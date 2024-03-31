#pragma once
#include <iostream>
#include <string>

#include "Person.h"
#include "validation.h"

using namespace std;

class Client : public Person
{
private:
    double Balance;

public:
    Client(int ID, string Name, string Password, double Balance)
        : Person(ID, Name, Password)
    {
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
};
