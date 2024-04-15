#pragma once

#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Helper
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
    template <typename T>
    static void saveObject(string &fileName, T &object)
    {
        ofstream file(fileName, ios::app);
        if (file.is_open())
        {
            file << object.serialize() << "\n";
            file.close();
        }
    }

    template <typename T>
    static void getObjects(string &fileName)
    {
        ifstream file(fileName);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                T object;
                object.deserialize(line);
            }
            file.close();
        }
    }

    static void clearFile(string &fileName)
    {
        ofstream file(fileName);
        if (file.is_open())
        {
            file.close();
        }
    }
};