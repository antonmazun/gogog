#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <limits.h>

int main(void) {
	srand(time(NULL));
	int MIN  = 80;
	int MAX = 100;
	int n;
	
	long long sum = 0;
	int i ,j ,q,w,e,y;
	puts("vvedite razmeru masiva:");
	scanf("%i",&n);
	double mas[n][n][n][n];
	for( i = 0; i < n; i++)
	for( j = 0; j < n; j++)
	for (q = 0; q < n; q++)
	for (w = 0; w < n; w++)
	
	
	mas[i][j][q][w] =(double)rand()/RAND_MAX * (MAX - MIN) + MIN;
		for( i = 0; i < n; i++)
	for( j = 0; j < n; j++)
	for (q = 0; q < n; q++)
	for (w = 0; w < n; w++)
	
	printf("%5.2lf " , mas[i][j][q][w] );
	
	
	int arr[n][n][n][n][n][n];
		for( i = 0; i < n; i++)
	for( j = 0; j < n; j++)
	for (q = 0; q < n; q++)
	for (w = 0; w < n; w++)
	for ( e = 0; e < n; e++)
	for( y = 0; y < n; y++ )
	arr[i][j][q][w][e][y] = rand()%10-5;
			for( i = 0; i < n; i++)
	for( j = 0; j < n; j++)
	for (q = 0; q < n; q++)
	for (w = 0; w < n; w++)
	for (e = 0; e < n; e++)
	for (y = 0; y < n; y++)
	sum += arr[i][j][q][w][e][y];
	printf( "\n\n%lld" , sum);
	sum = 0LL;
	for( i = 0; i < n*n*n*n*n*n; i++)
		sum += *(*****arr + i);
	printf( "\n\n%lld" , sum);
	int mas1[n][n][n][n][n];
	for( j = 0; j < n; j++)
	for (q = 0; q < n; q++)
	for (w = 0; w < n; w++)
	for (e = 0; e < n; e++)
	for (y = 0; y < n; y++)
	mas1[j][q][w][e][y]= rand()%5;
	int x[5];
	int max = mas1[0][0][0][0][0];
	for( j = 0; j < n; j++)
	for (q = 0; q < n; q++)
	for (w = 0; w < n; w++)
	for (e = 0; e < n; e++)
	for (y = 0; y < n; y++)
	if ( max < mas1[j][q][w][e][y])
	{
	
	max = mas1[j][q][w][e][y];
	x[0] = j;
	x[1] = q;
	x[2] = w;
	x[3] = e;
	x[4] = y;
}
	printf("\n%i" ,max);
	printf ("\n%i %i %i %i %i",x[0], x[1],x[2],x[3],x[4]);
	 	return 0;
}


