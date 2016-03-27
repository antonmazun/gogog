#include <stdio.h>
#include <stdlib.h>
#include "Randomizer.h"
#include "ZeroWriter.h"

HANDLE hMutex; //Указатель типа *void

HANDLE newThread(LPTHREAD_START_ROUTINE routine, int * ctx) {
return CreateThread(
NULL, // default security attributes
0, // default stack size
(LPTHREAD_START_ROUTINE) routine, // thread function
(LPVOID)ctx, // thread function arguments
0, // default creation flags
NULL); // receive thread identifier
}

int main(void) {

srand(time(NULL));
int value = 0;

hMutex = CreateMutex(
NULL, // default security attributes
FALSE, // initially not owned
NULL);
// create new threads
HANDLE consumers[] = {
newThread(ZeroWriter, &value),
newThread(ZeroWriter, &value),

};
HANDLE producers[] = {

    newThread(Randomizer, &value),
    newThread(Randomizer, &value),
    newThread(Randomizer, &value),
    newThread(Randomizer, &value),
    newThread(Randomizer, &value),

};

int i;

while (!kbhit()) {

Sleep(10);
}
    for (i = 0; i < 5; i++) {
    CloseHandle(producers[i]);
}
    for ( i = 0; i < 5; i++) {
        CloseHandle(consumers[i]);
}
    CloseHandle(hMutex);
    getch();
    system("cls");

return 0;
}


