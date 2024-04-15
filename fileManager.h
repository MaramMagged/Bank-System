#pragma once
#include <iostream>
#include <fstream>
#include <srting>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

class FileManager
{
public:
    static void AddClient(Client &client, string &fileName)
    {
        Helper::saveObject(fileName, client);
    }

    static void AddEmployee(Employee &employee, string &fileName)
    {
        Helper::saveObject(fileName, employee);
    }

    static void AddAdmin(Admin &admin, string &fileName)
    {
        Helper::saveObject(fileName, admin);
    }

    static vector<Client> getAllClients(string &fileName)
    {
        vector<Client> Client;
        Helper::getObjects<Client>(fileName);
        return Client;
    }
    static vector<Employee> getAllEmployees(string &fileName)
    {
        vector<Employee> employee;
        Helper::getObjects<Employee>(fileName);
        return employee;
    }
    static vector<Admin> getAllAdmins(string &fileName)
    {
        vector<Admin> admin;
        Helper::getObjects<Admin>(fileName);
        return admin;
    }
    static void removeAllClients(string &fileName)
    {
        Helper::clearFile(fileName);
    }

    static void removeAllEmployees(string &fileName)
    {
        Helper::clearFile(fileName);
    }
    static void removeAllAdmins(string &fileName)
    {
        Helper::clearFile(fileName);
    }
};