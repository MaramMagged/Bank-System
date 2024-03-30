#pragma once
#include <iostream>
#include "person.h"
#include "validation.h"
#include "exceptions.h"
#include "client.h"
#include "admin.h"
#include "Employee.h"

using namespace std;

int main()
{

   // creat a client

   Client client(1, "Maram", "Pass254", " 1000.0")
       client.display();

   // Deposit money into the client's account
   client.deposit(500.0);
   client.CheckBalance();

   // withdraw money from the client's account
   client.withdraw(200.0);
   client.CheckBalance();

   // creat an employee

   Employee employee(2, "jane savier", "emp547", 8.0);
   employee.display();

   // creat an admin
   Admin admin(3, "Adam zi", "admin6548", 5.0);
   admin.display();

   return 0;
}