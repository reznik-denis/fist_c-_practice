#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int sp_task_1()
{
    int N;

    cout << "Enter size of array" << endl;
    cin >> N;
    cout << endl;

    int* array = new (nothrow) int[N];
    if (array == nullptr)
    {
        cerr << "Memory allocation error" << endl;
        return 1;
    }

    srand(time(nullptr));
    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 100;
    }

    for (int i = 0; i < N; i++)
    {
        cout << array[i] << "\t";
    }

    delete[] array;

    return 0;
}