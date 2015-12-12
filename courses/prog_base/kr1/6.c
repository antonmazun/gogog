#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void f(char * a ,char *b);

int main() {

	char a[150];
	
	puts( "vvedite stroky 1:\n");
	gets (a);
	fflush(stdin);
	char b[150];
		puts( "vvedite stroky 2:\n");
		gets(b);
			f( a ,b);
	return 0;
}


void f(char * a ,char *b){

char c[3];
int i;

	
	for ( i = 0 ; i < strlen(a) - 2 ; i++){
	
	c[0] =a[i];
	c[1] = a[i+1];
	c[2] = a[i +2];
	if(	strcmp(b,c) >= 0){
	
	puts(c);
	
		break;
}			
}

}
