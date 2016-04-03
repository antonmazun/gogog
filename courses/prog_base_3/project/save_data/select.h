#ifndef CHANGE_H_INCLUDED
#define CHANGE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct book_s  book_t;
void change_book(book_t * pbook);
book_t * book_new();
void save(struct book_s *pbook);

#endif // CHANGE_H_INCLUDED
