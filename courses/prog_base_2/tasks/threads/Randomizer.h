#ifndef RANDOMIZER_H_INCLUDED
#define RANDOMIZER_H_INCLUDED
#ifndef WIN_IS_DEF
#define WIN_IS_DEF
#include <windows.h>
#endif
#ifndef HMUTEX_DEF
#define HMUTEX_DEF
  HANDLE hMutex;
#endif // RANDOMIZER_H_INCLUDED
DWORD Randomizer(LPVOID args);
void randomizer_del(HANDLE * consumers);

HANDLE * randomizer_new(int * value);

#endif // RANDOMIZER_H_INCLUDED
