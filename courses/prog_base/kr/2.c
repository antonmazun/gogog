#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>
int  syma(int y , long x , double z , char a[]);


struct Team{
	int  bal1;
	long bal2;
	double bal3;
	char cvalification[150];
	
};
int main() {
	struct Team foot;
	int y;
	long x;
	double z;
	char a[150];
//	struct Team foot;
	puts("vvedite balu za 1 igry:\n");
	scanf("%i0\n" , &foot.bal1);
		puts("vvedite balu za 2 igry:\n");
			scanf("%f0\n" , &foot.bal2);
			puts("vvedite balu za 3 igry:\n");
				scanf("%d0\n" , &foot.bal3);
				printf("vveditb resyltat cfalification (proishlu ili ne proishlu):\n");
			scanf("%c0\n" , &foot.cvalification);
		
		double w = syma(&foot);
			printf(" syma baliv : %d" ,w);
			
	
	
	return 0;
}

int  syma(struct Team * foot){
	struct Team d;
	double sum = 0;
	if( strcmp(foot.cvalification , "proishlu") ==0) {
		sum += &foot.bal1 + &foot.bal2 + &foot.bal3;
	}
	
	return sum;
}
