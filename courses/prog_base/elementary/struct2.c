#include <stdio.h>
#include <math.h>

struct coord{
	int x1,x2,x3,x4,y1,y2,y3,y4;
	double len1,len2,len3,len4;
};

struct coord1{
	int x1,x2,x3,x4,y1,y2,y3,y4;
	double len1,len2,len3,len4;
};



int main(void){
	struct coord xy;
	struct coord1 xy1;
	double f;
	puts("vvedite koordinatu to4ok pryamokytnika:");
	puts("x1");
	scanf("%i" ,&xy.x1);
		puts("y1");
	scanf("%i" ,&xy.y1);
		puts("x2");
	scanf("%i" ,&xy.x2);
		puts("y2");
	scanf("%i" ,&xy.y2);
		puts("x3");
	scanf("%i" ,&xy.x3);
		puts("y3");
	scanf("%i" ,&xy.y3);
		puts("x4");
	scanf("%i" ,&xy.x4);
		puts("y4");
	scanf("%i" ,&xy.y4);
	xy1.x1 = xy.x1;
	xy1.y1 = xy.y1;
	xy1.x2 = xy.x2;
	xy1.y2 = xy.y2;
	xy1.x3 = xy.x3;
	xy1.y3 = xy.y3;
	xy1.x4 = xy.x4;
	xy1.y4 = xy.y4;
	
	xy.len1 = sqrt((xy.x2 - xy.x1)^2 + (xy.y2 -xy.y1 )^2);
		xy.len2 = sqrt((xy.x3 - xy.x2)^2 + (xy.y3 -xy.y2 )^2);
			xy.len3 = sqrt((xy.x4 - xy.x3)^2 + (xy.y4 -xy.y3 )^2);
				xy.len4 = sqrt((xy.x1 - xy.x4)^2 + (xy.y1 -xy.y4 )^2);
				xy1.len1 = xy.len1;
				xy1.len2 = xy.len2;
				xy1.len3 = xy.len3;
				xy1.len4 = xy.len4;
				f = ((xy.x1-xy.x2)*(xy.x3-xy.x2) + (xy.y1-xy.y2)*(xy.y3-xy.y2));
		
				if(xy.len1 == xy.len3 && xy.len2 == xy.len4 && f == 0){
					
				printf("length12:%f\n" ,xy.len1);
				printf("length23:%f\n" ,xy.len2);
				printf("length34:%f\n" ,xy.len3);
				printf("length41:%f\n" ,xy.len4);
				}
				else 
					puts  ("It is not rectangle");
				
	return 0;
}
