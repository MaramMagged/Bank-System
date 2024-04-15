#pragma once

#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "helperClass.h"

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <sstream>

using namespace std;

class Parser
{
public:
    static Client ParseToClient(const string &line)
    {
        vector<string> tokens = Helper::split(line, '&');

        string name = tokens[0];
        string password = tokens[1];
        double balance = stod(tokens[2]);

        return Client(name, password, balance);
    }
    static Employee ParseToEmployee(const string &line)
    {
        vector<string> tokens = Helper::split(line, '&');

        string name = tokens[0];
        string password = tokens[1];
        double salary = stod(tokens[2]);

        Employee e(name, password, salary);
        return e;
    }
    static Admin ParseToAdmin(const string &line)
    {
        vector<string> tokens = Helper::split(line, '&');

        string name = tokens[0];
        string password = tokens[1];
        double salary = stod(tokens[2]);

        Admin a(name, password, salary);
        return a;
    }
};
