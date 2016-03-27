#include "Randomizer.h"
#include "threads.h"
DWORD Randomizer(LPVOID args) {
int * self = (int *)args;
while (TRUE) {
WaitForSingleObject(hMutex, INFINITE);
 *self = rand() % 21 - 10;
ReleaseMutex(hMutex);
Sleep(20);
}
}


void randomizer_del(HANDLE * consumers){
   for (int i = 0; i < 5; i++)
        CloseHandle(consumers[i]);
}

HANDLE * randomizer_new(int * value){   //Указатель типа *void

    HANDLE * consumers = malloc(sizeof(HANDLE) * 5);

        consumers[0] = newThread(Randomizer, &value);
        consumers[1] = newThread(Randomizer, &value);
        consumers[2] = newThread(Randomizer, &value);
        consumers[3] = newThread(Randomizer, &value);
        consumers[4] = newThread(Randomizer, &value);
    return consumers;
}



