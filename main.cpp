#include <iostream>

#include "Admin.h"
#include "Client.h"
#include "Employee.h"

using namespace std;

int main()
{
    // creat a client
    Client client("Maram", "Pass25411", 2000.0);
    client.display();
    cout << endl;

    // Deposit money into the client's account
    client.deposit(500.0);
    client.CheckBalance();
    cout << endl;

    // withdraw money from the client's account
    client.withdraw(200.0);
    client.CheckBalance();
    cout << endl;

    // creat an employee
    Employee employee("Jane Savier", "emp54723", 8000.0);
    employee.display();
    cout << endl;

    // creat an admin
    Admin admin("Adam Zi", "admin6548", 5000.0);
    admin.display();
    cout << endl;
}