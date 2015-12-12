#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//void Fillrand(int mas[] , int N);
void minarray( int N,int mas[]);
void minIndex(int N , int mas[]);

int main() {
	int i ,N;
	
	srand(time(NULL));
	puts("please enter size of array:\n");
	scanf("%i" , &N);
	int mas[N];
	for( i =0 ; i < N; i++)	{
	
			mas[i] = rand()%1999-1000 ;
			printf("%i\t" ,mas[i] );
			}
			
			puts("\n");
			minarray( N, mas);
	return 0;
}

void minarray( int N, int mas[]){
	int min = 0 , i;
	min = mas[0];
	for(i = 0 ; i < N; i++){
	
	if(min > mas[i])
		
		min = mas[i];
		
			
	}
	printf (" minelement :%i\n" , min);
	puts("Indexu negativnux elementiv:\n");
minIndex( N , mas);
}
void minIndex(int N , int mas[]){
	
	int i;
	
    for (i=0;i<N;i++)
        if (mas[i]<0){
          printf("%i ", i);
           }
       }
