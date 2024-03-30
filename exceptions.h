
#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include "validation.h"
#include "person.h"
#include "client.h"
#include "admin.h"

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

int main()
{

    return 0;
}
