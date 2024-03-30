#pragma once
#include <iostream>
#include <string>

#include "person.h"

using namespace std;

class Client : public Person
{
    

public:
    Client(int ID, string Name, string Password, double Balance)
        : Person(ID, Name, Password, Balance) {}

    void deposit(double amount)
    {
        setBalance(getBalance() + amount);
        cout << " Deposited successfully." << endl;
    }

    void withdraw(double amount)
    {
        setBalance(getBalance() - amount);
        cout << " Withdrawn successfully." << endl;
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
                cout << " Transferred successfully to ."
                     << recipient.getName() << "." << endl;
            }
        }
    }
    void CheckBalance()
    {
        cout << " Current balance : " << getBalance() << endl;
    }
};
