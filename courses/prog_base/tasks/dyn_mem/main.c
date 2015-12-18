#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char * a = NULL;
	a = (char*)malloc(sizeof(char) * 100);
	if (NULL == a)
		return 1;
	int * p = NULL;
	p = (int*)malloc(sizeof(int));
	if (NULL == p)
		return 1;
	int * i = NULL;
	i = (int*)malloc(sizeof(int));
	if (NULL == i)
		return 1;
	*p = 0;
	puts("vvedite stroky:\n");
	gets(a);
	
	for (*i = 0; *i < strlen(a); (*i)++)
		if(a[*i] != ' ' && a[*i] != '\t'){
			*p = (int)a[*i];
			break;
		}
	for (*i = strlen(a) - 1; *i > 0; (*i)--)
		if(a[*i] != ' ' && a[*i] != '\t')
		{
			(*p) += (int)a[*i];
			break;
		}
	printf("suma pervogo i poslednego simvola = %i", *p);
	free(a);
	free(p);
	free(i);
	return 0;
}
