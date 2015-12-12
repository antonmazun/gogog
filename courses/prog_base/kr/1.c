#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int myStrcmp( char * str1,  char *str2);

int main(void) {

	char str1[150];
	puts("vvedite stroky 1:\n");
	scanf("%s", &str1);
	char str2[150];
		puts("vveditecc stroky 2:\n");
		scanf("%s" , &str2);
int d =  myStrcmp(str1,str2);
	printf(" result:\t%i" ,d);
	return 0;
}


int myStrcmp( char * str1,  char *str2){
	

	int c;
	int x , y;

 	x = str1;
	y = str2;
 
 x = strlen(str1);
 y = strlen(str2);

	 
		c = x - y;
	 		return c;
}
