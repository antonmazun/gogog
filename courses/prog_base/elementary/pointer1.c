#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int x = 5;
	int *p;
	int **pp;
	p = &x;
	pp = &p;
	**pp = 10;
	printf("%i " , **pp);
	int mas[] = {1,2,3,4,5};
	int *p1[5];
	int i;
	for( i = 0; i < 5 ; i++){
	
		p1[i] = &(mas[i]);
	

	printf ("%i" , *p1[i]);
}
puts ("\n");
	int arr[] = {2,4,5,6};
	int *o[4];
	int **o1;
	 
	 for (i = 0; i < 4; i++)
	 
	 o[i] = &(arr[i]);
	 o1 =&o[0];
	 
	 for(i = 0; i<4;i++)
	 printf ("%i ", *(o1[i] ));
	 
	 puts("\n");
	 char *str [5] = {"aadsfg", "qwe","rtjhgfdghjhgyu" ,"xcv","hjkljkk"};
	 char **b = str;
 	puts(*str);
	puts(*(str+1));
	puts(*(str+2));
	puts(*(str+3));
	puts(*(str+4));
	puts("\n");
	for(i = 0; i  < 5;i++)
	printf ("%i \n" , strlen(*(str+i)));
	
	int max = 0;
	int index = 0;
	for(i = 0; i < 5; i++)
	if( max < strlen(*(str+i))){
	
	max = strlen(*(str+i));
	
	index = i;
		
}
	puts(*(str+index));
	 	return 0;
}
