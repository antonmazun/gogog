#ifndef THREADS_H_INCLUDED
#define THREADS_H_INCLUDED
#include <windows.h>


HANDLE newThread(LPTHREAD_START_ROUTINE routine, int * ctx);

#endif // THREADS_H_INCLUDED
