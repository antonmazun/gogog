#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


typedef int (*LogCallback)(char a, char b, char c);
typedef void (*LogCallback1)(char * a, char * b, char * c);
void alert_func2 (char * a, char * b, char * c);
int check_func1 (char a, char b, char c);
void alert_func1 (char * a, char * b, char * c);
int check_func2 (char a, char b, char c);
void check(char * str, LogCallback checkCB, LogCallback1 alertCB);


int main(void)
{
    LogCallback check1 = check_func1;
    LogCallback check2 = check_func2;
    LogCallback1 alert1 = alert_func1;
    LogCallback1 alert2 = alert_func2;
    char str[100];
    gets(str);
    check(str, check1, alert1);
    check(str, check2, alert2);
    puts(str);


    return 0;
}

void check(char * str, LogCallback checkCB, LogCallback1 alertCB)
{
    for (int i = 2; i < strlen(str); i++)
    {
        if (checkCB(str[i - 2], str[i - 1], str[i]) == 1)
            alertCB((&str[i - 2]), (&str[i - 1]), &(str[i]));
    }
}

int check_func1 (char a, char b, char c)
{
    if (a == b && a == c)
        return 1;
    return 0;
}

int check_func2 (char a, char b, char c)
{
    if (a != b   && a == c + 2 || a !=1 && a == c - 2 )
        return 1;
    return 0;
}

void alert_func1 (char * a, char * b, char * c)
{
    *a = '9';
    *b = '9';
    *c = '9';
}

void alert_func2 (char * a, char * b, char * c)
{
    *a = 'U';
    *b = 'P';
    *c = 'S';
}
