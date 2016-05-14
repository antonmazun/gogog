#include "main.h"
#include <stdio.h>
// a sample exported function
int DLL_EXPORT check(word_t * self){

if(strlen(word_get(self , (word_count(self) - 1))) > 5 )
    return 1;
else return 0;

}


void DLL_EXPORT print(word_t * self, int check){


if(check)
{

    printf("%s"  , word_get(self , (word_count(self) - 1)));
}



}
extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
