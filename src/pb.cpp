#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <string.h>
#include <time.h>
#include <iostream>

using namespace std;

void killProcessByName(const char *filename)
{
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof (pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);
    while (hRes)
    {
        if (strcmp(pEntry.szExeFile, filename) == 0)
        {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
                                          (DWORD) pEntry.th32ProcessID);
            if (hProcess != NULL)
            {
                TerminateProcess(hProcess, 9);
                CloseHandle(hProcess);
            }
        }
        hRes = Process32Next(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);
}

void RegisterStartupProgram(char* programName, char* executablePath)
{
  HKEY hKey;

  LONG lnRes = RegOpenKeyEx(HKEY_CURRENT_USER,
                            "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
                            0 , KEY_WRITE,
                            &hKey);
  if(ERROR_SUCCESS == lnRes)
  {
    RegSetValueEx(hKey,
                  programName,
                  0,
                  REG_SZ,
                  (unsigned char*) executablePath,
                  strlen(executablePath));
  }

  RegCloseKey(hKey);
}


int main(int argc, char** argv)
{
  if(argc < 3)
  {
    cout << "Missing parameter(s)" << endl;

    return 1;
  }
  HMODULE hModule = GetModuleHandle(NULL);

  if(hModule != NULL)
  {
    char programPath[MAX_PATH];

    GetModuleFileName(hModule, programPath, (sizeof(programPath)));

    strcat(programPath, " ");
    strcat(programPath, argv[1]);

    for(int index = 2; index < argc; index++)
    {
      strcat(programPath, " ");
      strcat(programPath, argv[index]);
    }

    RegisterStartupProgram(argv[1], programPath);
  }

  while(true)
  {
    for(int index = 2; index < argc; index++)
    {
      cout << argv[index] << endl;

      killProcessByName(argv[index]);
    }

    Sleep(500);
  }
}
