#include <iostream>
#include <unistd.h> // Для fork, exec
using namespace std;

int main()
{
    pid_t c_pid = fork();

    if (c_pid == -1)
    {
        cerr << "fork" << endl;
        exit(EXIT_FAILURE);
    }
    else if (c_pid > 0)
    {
        // wait(nullptr);
        cout << "printed from parent process " << getpid() << endl;
    }
    else
    {
        cout << "printed from child process " << getpid() << endl;
    }

    return 0;
}
