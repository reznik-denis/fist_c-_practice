// SP-Lab04.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string device_data = "Initial device data";
vector<string> history;
int count_change = 0;

void read_device()
{
    cout << "Reading from device: " << device_data << endl;
}

void add_to_history(const string& data) 
{
    device_data = data;
    count_change += 1;
    ostringstream oss;
    oss << "Change " << count_change << ":" << device_data << ".";
    history.push_back(oss.str());
}

void write_device(const string& data)
{
    device_data = data;
    cout << "Data written to device: " << device_data << endl;
    add_to_history(device_data);
}

void read_history()
{
    cout << "History changes:" << endl;
    for (const auto& change : history) {
        cout << change << endl;
    }
}


int main()
{
    int choice;
    string input;
    ostringstream oss;
    oss << "Initial: " << device_data << ".";
    history.push_back(oss.str());

    while (true)
    {
        cout << "\nVirtual Device Menu:\n";
        cout << "1. Read from device\n";
        cout << "2. Write to device\n";
        cout << "3. Read history changes\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice)
        {
        case 1:
            read_device();
            break;
        case 2:
            cout << "Enter data to write to device: ";
            cin.ignore();
            getline(cin, input);
            write_device(input);
            break;
        case 3:
            read_history();
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

