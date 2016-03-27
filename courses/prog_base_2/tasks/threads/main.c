#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>



#include "Randomizer.h"
#include "ZeroWriter.h"

 //Указатель типа *void


int main(void) {

srand(time(NULL));
int value = 0;

hMutex = CreateMutex(
NULL, // default security attributes
FALSE, // initially not owned
NULL);
// create new threads
HANDLE * raz = randomizer_new(&value);
HANDLE * dwa = zeroWriter_new(&value);

while (!kbhit());
CloseHandle(hMutex);
randomizer_del(raz);
zeroWriter_del(dwa);

    getch();
    system("cls");

return 0;
}


