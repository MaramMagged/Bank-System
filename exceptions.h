
// tbh this whole file isn't needed, you can define custom Exception classes but this currently isn't very useful

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include "validation.h"

using namespace std;
class myExceptions
{
public:
    static void Exception(const string &name)
    {
        if (name.length() < 5 || name.length() > 20 || !isalpha(name))
        {
            throw invalid_argument(name);
        }
    }

    static void passwordException(const string &name)
    {
        if (name.length() < 5 || name.length() > 20)
        {
            throw invalid_argument(name);
        }
    }
    static void salaryException(double salary)
    {
        if (salary < 5000)
        {
            throw invalid_argument(to_string(salary));
        }
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
