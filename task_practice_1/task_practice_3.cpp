// task_practice_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author Reznik D.O. student of group 222z (online)

#include <iostream>
using namespace std;

int main()
{
    int value;
    cout << "Please write an integer even value for calculate even factorial" << endl;
    cin >> value;
    double even_factorial = 1;

    for (int i = value; i > 0; i -= 2) {
        even_factorial *= i;
    }

    cout << "Even factorial " << value << " equal " << even_factorial << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu