#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "select.h"
struct book_s{

char genre[50];
char name[50];
char author[50];

};


book_t * book_new(){
book_t * pbook;
pbook = malloc(sizeof(struct book_s));
return pbook;
}

void change_book(book_t * pbook){

    printf("Please select the genre of the book:\nComedy\nFantasy\nDetective\nAdventures\nTragety\nDrama\n");
    gets(pbook->genre);
    fflush(stdin);
    system("cls");
    if(strcmp(pbook->genre ,"Comedy") == 0)

        puts("Please select author\nOlga Gromyko\nDouglas Adams\n");
    gets(pbook->author);
     fflush(stdin);
    system("cls");
    if(strcmp(pbook->author , "Olga Gromyko") == 0)
    puts("Please select the name of book\n");
        puts("Title: Witch\n");
    gets(pbook->name);
    fflush(stdin);
//system("cls");
}

void save(struct book_s *pbook){

FILE * fp;
fp = fopen("data for book.txt" , "w");
fprintf(fp , "Genre: %s\nAuthor: %s\nName: %s\n" , pbook -> genre , pbook ->author , pbook -> name);

}
