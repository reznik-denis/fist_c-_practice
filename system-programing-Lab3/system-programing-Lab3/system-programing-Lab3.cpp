// system-programing-Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    string filename = "data.txt";
    string content;
    int count_lines = 0;
    int count_symbols = 0;

    ifstream inFile(filename);
    if (inFile.is_open())
    {
        while (getline(inFile, content))
        {
            count_lines += 1;
            count_symbols += content.length();
        }
        inFile.close();
    }
    else
    {
        cerr << "Failed to open file for reading!" << endl;
        return 1;
    }

    cout << "Count of lines: " << count_lines << endl;
    cout << "Count of symbols: " << count_symbols << endl;


    return 0;
}
