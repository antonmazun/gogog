#include "ZeroWriter.h"
#include "threads.h"


DWORD ZeroWriter(LPVOID args) { // DWO
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


void zeroWriter_del(HANDLE * consumers){
    for (int i = 0; i < 2; i++)
        CloseHandle(consumers[i]);
}


HANDLE * zeroWriter_new(int * value){

HANDLE * consumers = malloc(sizeof(HANDLE) * 2);


        consumers[0] = newThread(ZeroWriter, &value);
        consumers[1] = newThread(ZeroWriter, &value);

return consumers;
}
z
