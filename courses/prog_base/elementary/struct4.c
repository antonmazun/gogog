#include <stdio.h>
#include <math.h>

struct coord{
	int x1,x2,x3,x4,y1,y2,y3,y4;
	double len1,len2,len3,len4;
};




int main(void){
	struct coord xy[3];
	int i;
	double f;
	double pl , pl_m = 0;
	
	for(i = 0 ; i < 3; i++){
	
	puts("vvedite koordinatu to4ok pryamokytnika:");
	puts("x1");
	scanf("%i" ,&xy[i].x1);
		puts("y1");
	scanf("%i" ,&xy[i].y1);
		puts("x2");
	scanf("%i" ,&xy[i].x2);
		puts("y2");
	scanf("%i" ,&xy[i].y2);
		puts("x3");
	scanf("%i" ,&xy[i].x3);
		puts("y3");
	scanf("%i" ,&xy[i].y3);
		puts("x4");
	scanf("%i" ,&xy[i].x4);
		puts("y4");
	scanf("%i" ,&xy[i].y4);

 
	xy[i].len1 = sqrt(pow((xy[i].x2 - xy[i].x1),2) + pow((xy[i].y2 -xy[i].y1 ),2));
		xy[i].len2 = sqrt(pow((xy[i].x3 - xy[i].x2),2) + pow((xy[i].y3 -xy[i].y2 ),2));
			xy[i].len3 = sqrt(pow((xy[i].x4 - xy[i].x3),2) + pow((xy[i].y4 -xy[i].y3 ),2));
				xy[i].len4 = sqrt(pow((xy[i].x1 - xy[i].x4,2) + pow((xy[i].y1 -xy[i].y4 ),2));
			
				f = ((xy[i].x1-xy[i].x2)*(xy[i].x3-xy[i].x2) + (xy[i].y1-xy[i].y2)*(xy[i].y3-xy[i].y2));
	pl = xy[i].len1 * xy[i].len2;
				if(xy[i].len1 == xy[i].len3 && xy[i].len2 == xy[i].len4 && f == 0){
					
				printf("len1:%f\n" ,xy[i].len1);
				printf("len2:%f\n" ,xy[i].len2);
				printf("len3:%f\n" ,xy[i].len3);
				printf("len4:%f\n" ,xy[i].len4);
			if( pl > pl_m)
			pl_m = pl;
}
else 
puts ("It is not rectangle");
}	
printf("max plosha = %f" , pl_m);
return 0;
}
