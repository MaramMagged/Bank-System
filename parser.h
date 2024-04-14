#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include "Employee.h"
#include "Admin.h"
#include "Client.h"

using namespace std;

class Parser
{
public:
    static vector<string> split(const string &line, char delimiter)
    {
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }
    static Client ParseToClient(const string &line)
    {
        vector<string> tokens = split(line, '&');
        int id = stoi(tokens[0]);
        string name = tokens[1];
        string password = tokens[2];
        double balance = stod(tokens[3]);

        return Client(id, name, password, balance);
    }
    static Employee ParseToEmployee(const string &line)
    {
        vector<string> tokens = split(line, '&');

        int id = stoi(tokens[0]);
        string name = tokens[1];
        string password = tokens[2];
        double salary = stod(tokens[3]);

        return Employee(id, name, password, salary);
    }
    static Admin ParseToAdmin(const string &line)
    {
        vector<string> tokens = split(line, '&');

        int id = stoi(tokens[0]);
        string name = tokens[1];
        string password = tokens[2];
        double salary = stod(tokens[3]);

        return Admin(id, name, password, salary);
    }
};
