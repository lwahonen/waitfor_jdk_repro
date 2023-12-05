#include <iostream>
#include <windows.h>

#pragma comment( lib, "user32" )

int wmain( int argc, wchar_t *argv[ ], wchar_t *envp[ ] )
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(argv[1],   // No module name (use command line)
        NULL,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi)           // Pointer to PROCESS_INFORMATION structure
        )
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return 0;
    }
    int returnValue=WaitForInputIdle(pi.hProcess, 30 * 1000);
    printf("Input idle reached (%d)", returnValue);
    return 0;
}
