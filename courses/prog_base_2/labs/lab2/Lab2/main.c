#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "libstatic.h"
word_t * senToWords(char * str);

typedef int (*cmp_f)(word_t * words); // �������� �� �������
typedef void (*react_f)(word_t * words);

typedef struct dynamic_s {
    HANDLE hLib;
    cmp_f cmp;
    react_f react;
} dynamic_t;





dynamic_t * dynamic_init(const char * dllName) {
    dynamic_t * dyn = malloc(sizeof(struct dynamic_s));
    dyn->hLib = LoadLibrary(dllName);// ��������� �������� �� ����
    dyn->cmp = NULL;// �������� ���������� �� �������
    dyn->react = NULL;//�������� ���������� �� �������
    if (NULL != dyn->hLib) {
        dyn->cmp = (cmp_f)GetProcAddress(dyn->hLib, "check");// ��������� ������� �� �������
        dyn->react = (react_f)GetProcAddress(dyn->hLib, "print");
        return dyn;
    } else {
        return NULL;
    }
}

void dynamic_clean(dynamic_t * dyn) {//������ ������ ���������
    FreeLibrary(dyn->hLib);
    free(dyn);
}



const char * userChoice() {
    int dllNum = 0;
    while (dllNum < 1 || dllNum > 2) {// �������� �� ������ ���� (�� ���� ��������)
        printf("Choose DLL to load:\n1. Lab2DLL1\n2. Lab2DLL2\n> ");
        scanf("%i", &dllNum);
        if (dllNum == 1) {
            return "Lab2DLL1.dll";
        } else if (dllNum == 2) {
            return "Lab2Dll2.dll";
        }
    }
    return NULL;
}




word_t * senToWords(char * str)
{
     char ** words = NULL;
     int wordscount = 1;
    if (strlen(str) == 0)
    {
        printf("string is empty\n");
        return NULL;
    }

    int flag = 0;// ������ ����� �� ����
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ' && flag)
        {
            flag = 0;// �������� �� ������(����� ���� ������(��� �� �������� ���� ������ �� ����� ))
            wordscount++;
        }
        if (str[i] != ' ')
            flag = 1;//�� ��� �����
        if (str[i] == ' ' && str[i + 1] == '\0')// ���� ������� ������  ��� �����
            wordscount--;//�������� �����
    }
    printf("%i\n", wordscount);


    words = malloc(sizeof(char *) * (wordscount + 1));// ������ �� ����� ���
    char * word;
  //  puts(str);
    const char tmpstr[2] = {' ', '\0'};

    word = strtok(str, tmpstr);//������� �������� ������ �� ��������
// printf("%i\n", wordscount);


    for (int i = 0; i < wordscount; i++)
    {
        words[i] = malloc(sizeof(char) * strlen(word));
        strcpy(words[i], word);
       // puts(words[i]);
        word = NULL;
        if (i != wordscount - 1 )// ���� �� ������ �����
        {
        word = strtok(NULL, " ");// ����� ��� ������ �� �����������
        while(strlen(word) == 0)
            word = strtok(NULL, " ");
            if( word == NULL)
                break;
        }

    }

    words[wordscount] = NULL;
    if (words[0] == NULL)
        exit(1);
    word_t * self = word_new();
   //puts("dsasfd");
    for(int  i = 0 ; i < wordscount; i++)
{
    word_add(self , words[i]);

}
//puts("dafsdf");

    return self;
}



int main(){

const char * dllName = userChoice();
    dynamic_t * dll = dynamic_init(dllName);
    if (NULL == dll) {
        printf("Can't load dynamic!\n");
        return 1;
    }
    if (NULL == dll->cmp) {
        printf("Can't get compare function!\n");
        return 1;
    }
    if (NULL == dll->react) {
        printf("Can't get reaction function!\n");
        return 1;
    }
     printf("Dynamic loaded!\n");
     fflush(stdin);

    char str[100];
    gets(str);
    word_t * words = senToWords(str);
    puts("Done");
   //printf("Dynamic loaded!\n");
    /*for (int i = 0; words[i] != NULL; i++)
        puts(words[i]);*/
    if (words != NULL)
    if (dll->cmp(words))
        dll->react(words);

    return 0;
}


