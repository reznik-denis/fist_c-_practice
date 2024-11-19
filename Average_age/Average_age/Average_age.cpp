#include <windows.h>
#include <iostream>
using namespace std;

int main() {
    STARTUPINFOA si = { 0 };
    PROCESS_INFORMATION pi = { 0 };
    si.cb = sizeof(STARTUPINFOA);

    const char* childProgram = "child_process.exe";

    if (!CreateProcessA(
        nullptr,               
        const_cast<char*>(childProgram),
        nullptr,                  
        nullptr,                   
        FALSE,                     
        0,                         
        nullptr,                   
        nullptr,                   
        &si,
        &pi
    )) {
        cout << "Error: Failed to create a new process! Error code: "
            << GetLastError() << endl;
        return 1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    cout << "Finished" << endl;
    return 0;
}
