#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void main() {
    cout << "Child started" << endl;

    int array[] = { 10, 23, 234, 67, 34, 126, -23, 45, 23, 67, 23, -67 };
    int length_array = size(array);
    double sum = 0;

    for (int i = 0; i < length_array; i++)
    {
        sum += array[i];
    }

    int average = sum / length_array;

    cout << "Average: " << average << endl;
    cout << "Child finished" << endl;
}