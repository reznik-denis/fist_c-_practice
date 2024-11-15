// task_practice_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author Reznik D.O. student of group 222z (online)

#include <iostream>
using namespace std;

int task_1()
{
    auto inch = 2.54;
    float sm;
    cout << "Please write a distance in sm" << endl;
    cin >> sm;
    float inches = sm / inch;
    cout << "Distance is " << inches << " inches" << endl;
    float new_inches;
    cout << "Please write a distance in inches" << endl;
    cin >> new_inches;
    float new_sm = new_inches * inch;
    cout << "Distance is " << new_sm << " sm";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
