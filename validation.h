#pragma once

#include <iostream>
#include <string>

using namespace std;

class Validation
{
public:
    static bool nameValid(const string &name)
    {
        return (name.length() >= 5 && name.length() <= 20 && stringIsAlphabetic(name));
    }
    static bool passValid(const string &pass)
    {
        return (pass.length() >= 8 && pass.length() <= 20);
    }
    static bool minBalance(double balance)
    {
        return (balance >= 1500);
    }
    static bool minSalary(double salary)
    {
        return (salary >= 5000);
    }

private:
    static bool stringIsAlphabetic(string str)
    {
        for (auto c : str)
        {
            if (!isalpha(c) && !isspace(c))
                return false;
        }
        return true;
    }
};
