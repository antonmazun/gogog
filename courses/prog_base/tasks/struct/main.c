#include <stdio.h>
#include <stdlib.h>



struct soc {
	
	char text[100];
	char tema[100];
	int kom;
	
};


int count(int size, struct soc val[size]);
void change(struct soc * pVar, const char * newValue);
void print(struct soc * pVar);




int main(void) {
	
	struct soc val[100];
	
	
	int i,b;
	for(i = 0; i < 2; i++){
	
	fflush(stdin);
	printf("enter text :");
	gets(val[i].text);
	fflush(stdin);
	printf("enter tema\n");
	gets(val[i].tema);
		fflush(stdin);
		printf ("vvedit kilkist komentiv\n");
		scanf("%i", &val[i].kom);
		
}	
	fflush(stdin);
	int a;
	char newName[100];
	printf("vvedit nomer texty:\n");
	scanf("%i", &a);
	printf("\n");
	fflush(stdin);
	printf("novoe nazvanie texta:\n");
	gets(newName);
	change(&val[a], newName);
	printf("kilkist postiv de kilkist komentiv >10:\n %i\n", count(2, val));
	print(&val[a]);


return 0;
}

int count(int size, struct soc arr[size]){
	
	int i;
	int c = 0;
	for(i = 0; i < size; i++){
		
		if( arr[i].kom >= 10)
		c++;
	}
	return c;
}

void change(struct soc * pVar, const char * newValue){
	
	strcpy(pVar->text, newValue);
	
}

void print(struct soc * pVar){
	printf (" zaminenuy text:\n");
	puts(pVar->text);
	printf ("tema zaminenogo texta:\n");
	puts(pVar->tema);
	printf("kilkist  komentiv : %i\n" , pVar->kom);
	
}
