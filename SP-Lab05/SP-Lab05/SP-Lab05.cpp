// SP-Lab05.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

extern "C" long long multiply(long long a, long long b); // Повертає 64-бітне число

int main() {
    long long a, b;
    cout << "Please enter a value a and b for multiply" << endl;
    cin >> a >> b;

    long long result = multiply(a, b); // Виклик асемблерної функції
    std::cout << "The product of " << a << " and " << b << " is: " << result << std::endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
