#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Client.h>
#include <Employee.h>

using namespace std;

class Helper
{
public:
    static void saveLast(string &fileName, int id)
    {
        ofstream file(fileName);
        if (file.is_open())
        {
            file << id << endl;
            file.close();
        }
    }
    static int getLast(string &fileName)
    {
        int lastID = 0;
        ifstream file(fileName);
        if (file.is_open())
        {
            file >> lastID;
            file.close();
        }
        return lastID;
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
                cout << object.display();
                cout << endl;
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