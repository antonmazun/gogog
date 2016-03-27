#include "threads.h"

HANDLE newThread(LPTHREAD_START_ROUTINE routine, int * ctx) {
return CreateThread(
NULL, // default security attributes
0, // default stack size
(LPTHREAD_START_ROUTINE) routine, // thread function
(LPVOID)ctx, // thread function arguments
0, // default creation flags
NULL); // receive thread identifier
}
