// task_practice_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author Reznik D.O. student of group 222z (online)

#include <iostream>
using namespace std;

int main()
{
    int value;
    int digit;
    cout << "Please write an integer value, as example xxx" << endl;
    cin >> value;
    digit = value % 10;
    int position = 3;
    value /= 10;

    for (int i = 2; i > 0; i--) {
        int new_digit = value % 10;
        if (new_digit < digit) {
            digit = new_digit;
            position = i;
        }
        value /= 10;
    }

    cout << "Position " << position << ". Digit value " << digit << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu