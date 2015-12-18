#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>


void zaminaregistra();
void chisla(char *a);
void zaminaregistra1();
int cifra();
int sum(void);
void poisk();
void poisk1();
void space();





int main(void) {

	int q;
	int i, N;
	char a[100]  , str[150];
	puts("vvedite stroky\n");
	gets(a);
	puts("\n");
	printf("%s\n" ,a);
	puts("vvedite ckolbko raz xotite vivesti stroky\n");
	scanf("%i" , &N);

		for(i = 0 ; i < N; i++){
		
		printf("%s\n" ,a);
	}
chisla(a);
zaminaregistra();
puts("\n");
zaminaregistra1();
puts("\n");
int v =  cifra();
printf("kilkict : %i" , v);
puts("\n");
int b = sum();
printf("suma = %i" ,b);
puts ("\n");
puts("poisk\n");
poisk();
poisk1();
puts ("\n");
space();
	return 0;
}


void zaminaregistra1(){
	int i;
	puts("vveditte stroky v verxnem registre:\n");
	char b[150];
	fflush(stdin);
	gets(b);
		for(i = 0 ; i < strlen(b); i++)
			if(toupper(b[i]) == b[i])
				b[i] = tolower(b[i]);
				
		printf("%s"  , b);
	
	
}

void zaminaregistra(){
	
	int i;
	puts("vveditte stroky v nizhnim registre:\n");
	char b[150];
	fflush(stdin);
	gets(b);
		for(i = 0 ; i < strlen(b); i++)
			if(tolower(b[i]) == b[i])
				b[i] = toupper(b[i]);
				
		printf("%s"  , b);

}


void chisla(char *a){
	
	a = getchar();
	if(isdigit(a)){
		printf("%c" , a );
	}
	
	
}

int cifra(){
	int count = 0 , i;
	char str[150];
	puts("vvedite stroky s ciframi:\n");
	fflush(stdin);
	gets(str);
	for (i = 0 ; i < strlen(str); i++)
		if (str[i] >= '0' && str[i] <= '9'){
		count++;
}
		return count;
	
}

int sum(void){
	
	char x[150];

	puts ("vvedite stroky dlya symu: ");
	fflush(stdin);
	gets(x);
	int i;
	int sum = 0 ;
	int j = 0 , res = 0;
	for( i = 0; i < strlen(x); i++){
		if(x[i] >=  48 && x[i] <= 58){
			j = x[i] - 48;
		sum += j;
		}
	}
		return sum;
}

void poisk(){
	
	char a[150]; 
	char b[2];

	
	puts("vvedite stroky");
		fflush(stdin);
		gets(a);
	puts("vvedite simvol");
		fflush(stdin);
		gets(b);
		int i;
		for(i = 0; i < strlen(a); i++)
			if((int) a[150] == (int)b[0]){
				
			puts("+");
			
			}
			else{
				puts ("-");
			}
}

void poisk1(){
	char str1[150];
	char str2[150];
	char *pstr1;
	char *pstr2;
	char *p;
	pstr1 = &str1;
	pstr2 = &str2;
	
	puts("vvedite 1 stroky:");
	fflush(stdin);
	gets(str1);
	puts("vvedite 2 stroky:");
	fflush(stdin);
	gets(str2);
	p = strstr(pstr1 , pstr2);
	if(p == NULL){
		printf("\n-\n");
		
	}
	else {
	
	puts("+");
}

int counter = 0;
while(1){
	if(p != NULL)
	counter++;
	break;
}
printf ("kol-vo number: %i"  , counter);
}

void space(){
	
	char text[150];
	char space[] = " ";
	char *a;
	puts ("vvedite stroky");
	gets(text);
	a = strtok(text , space);
	while(a != NULL){
		puts(a);
		a = strtok(NULL,space);
	}
}
