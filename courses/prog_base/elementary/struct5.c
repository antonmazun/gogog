#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct coord {
	int x1,x2,x3,x4,y1,y2,y3,y4;
	double len1,len2;
};


struct coord1 {
	int x1,x2,x3,x4,y1,y2,y3,y4;
	double len1,len2;
};


int main(void) {
	struct coord *p=malloc(sizeof(struct coord));
	struct coord1 *p1=malloc(sizeof(struct coord1));
	//*(p)===p->
	puts("vvedite koordinatu to4ok pryamokytnika:");
	puts("x1");
	scanf("%i" ,&p->x1);
	puts("y1");
	scanf("%i" ,&p->y1);
	puts("x2");
	scanf("%i" ,&p->x2);
	puts("y2");
	scanf("%i" ,&p->y2);
	puts("x3");
	scanf("%i" ,&p->x3);
	puts("y3");
	scanf("%i" ,&p->y3);
	puts("x4");
	scanf("%i" ,&p->x4);
	puts("y4");
	scanf("%i" ,&p->y4);
	puts("vvedite koordinatu to4ok 2 pryamokytnika:");
	puts("x1");
	scanf("%i" ,&p1->x1);
	puts("y1");
	scanf("%i" ,&p1->y1);
	puts("x2");
	scanf("%i" ,&p1->x2);
	puts("y2");
	scanf("%i" ,&p1->y2);
	puts("x3");
	scanf("%i" ,&p1->x3);
	puts("y3");
	scanf("%i" ,&p1->y3);
	puts("x4");
	scanf("%i" ,&p1->x4);
	puts("y4");
	scanf("%i" ,&p1->y4);
	p->len1 = sqrt(fabs(pow((p->x3 - p->x1),2) + pow((p->y3 -p->y1 ),2)));
	
	p1->len2 = sqrt(fabs(pow((p1->x3 - p1->x1),2) + pow((p1->y3 -p1->y1 ),2)));


	if(p->len1 == p1->len2) {

		puts("equals");
	} else {
		puts("not equals");
	}


	return 0;

}
