#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    STARTUPINFO si = { 0 };
    PROCESS_INFORMATION pi = { 0 };
    si.cb = sizeof(STARTUPINFO);

    const wchar_t* command = L"D:\\C\\fist_c-_practice\\average.exe";

    if (!CreateProcess(
        nullptr,
        const_cast<LPWSTR>(command),
        nullptr,
        nullptr,
        FALSE,
        0,
        nullptr,
        nullptr,
        &si,
        &pi
    ))
    {
        cout << "Error: Failed to create a new process! Error code: "
            << GetLastError() << std::endl;
        return 1;
    }

    cout << "Parent started" << GetCurrentProcessId() << endl;
    cout << "Child started" << pi.dwProcessId << endl;

    WaitForSingleObject(pi.hProcess, INFINITE);

    DWORD exitCode;
    if (GetExitCodeProcess(pi.hProcess, &exitCode))
    {
        cout << "Child finished" << endl;
    }
    else
    {
        cout << "Error: Failed to get the exit code of the child process!" << endl;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    cout << "Finished" << endl;

    return 0;
}