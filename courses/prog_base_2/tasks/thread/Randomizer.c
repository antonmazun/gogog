
#include "Randomizer.h"

HANDLE hMutex;

DWORD Randomizer(LPVOID args) {
int * param = (int *)args;
while (TRUE) {
WaitForSingleObject(hMutex, INFINITE);
(*param) = rand() % 21 - 10;
ReleaseMutex(hMutex);
Sleep(1);
}
}






