#include <iostream>
#include <windows.h>

int main()
{
    // Структура для інформації про процес
    STARTUPINFO si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(STARTUPINFO);

    // Ім'я команди, яку потрібно виконати (наприклад, "cmd.exe /C dir")
    const char *command = "cmd.exe /C dir";

    // Створення нового процесу
    if (!CreateProcess(
            nullptr,        // Немає конкретного шляху до програми
            (LPSTR)command, // Команда для виконання
            nullptr,        // Атрибути безпеки процесу
            nullptr,        // Атрибути безпеки потоку
            FALSE,          // Спадкування дескрипторів
            0,              // Параметри створення
            nullptr,        // Середовище
            nullptr,        // Робоча директорія
            &si,            // Вказівник на структуру STARTUPINFO
            &pi             // Вказівник на структуру PROCESS_INFORMATION
            ))
    {
        std::cout << "Error: Failed to create a new process! Error code: "
                  << GetLastError() << std::endl;
        return 1;
    }

    std::cout << "Parent process: PID = " << GetCurrentProcessId() << std::endl;
    std::cout << "Child process created with PID = " << pi.dwProcessId << std::endl;

    // Очікуємо завершення дочірнього процесу
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Отримуємо код завершення дочірнього процесу
    DWORD exitCode;
    if (GetExitCodeProcess(pi.hProcess, &exitCode))
    {
        std::cout << "Child process exited with code: " << exitCode << std::endl;
    }
    else
    {
        std::cout << "Error: Failed to get the exit code of the child process!" << std::endl;
    }

    // Закриваємо дескриптори процесу та потоку
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
