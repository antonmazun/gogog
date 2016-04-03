#include <stdio.h>
#include <stdlib.h>
#include "select.h"
int main()
{
   book_t * pbook;
   pbook = book_new();
   change_book(pbook);
    save(pbook);

    return 0;
}
