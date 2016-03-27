#include "ZeroWriter.h"

HANDLE hMutex;

DWORD ZeroWriter(LPVOID args) {
while (1){
// Windows handle type
// unnamed mutex
int * param = (int *)args;

WaitForSingleObject(hMutex, INFINITE); // Request ownership of mutex
if(*param == 0){
       // system("cls");

        printf("%i", *param);
        Sleep(10);
//fflush(stdout);
    }
    ReleaseMutex(hMutex);
        }
}
