#pragma once
#include <iostream>
#include <string>
#include "exceptions.h"
#include "person.h"
#include "client.h"
#include "admin.h"

using namespace std;

class Validation
{
public:
    static bool nameValid(const string &name)
    {
        return (name.length() >= 5 && name.length() <= 20 && isalpha(name));
    }
    static bool passValid(const string &pass)
    {
        return (pass.length() >= 8 && pass.length() <= 20);
    }
    static bool minBlance(double blance)
    {
        return (blance >= 1500);
    }
    static bool minSalary(double salary)
    {
        return (salary >= 5000);
    }

private:
    static bool isalpha(const string &str)
    {

        for (char c : str)
        {
            if (!::isalpha(c))
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{

    return 0;
}
