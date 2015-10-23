#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 

/*void fillRand(int mat [4][4]); 
void flipV(int mat [4][4]) ; 
void rotateCW270(int mat [4][4]) ; 
void transposMain( int mat[4][4]); 

int main () 
{ 
int a,b; 
int mat [4][4]; 
fillRand(mat); 
for (a=0;a<4;a++) 
{ 
for (b=0;b<4;b++) 
{ 
printf ("%i\t",mat[a][b]); 

} 
printf("\n"); 

} 
printf("\n"); 
rotateCW270(mat); 
for (a=0;a<4;a++) 
{ 
for (b=0;b<4;b++) 
{ 
printf ("%i\t",mat[a][b]); 

} 
printf("\n"); 

} 
printf ("\n"); 
flipV(mat); 
for (a=0;a<4;a++) 
{ 
for (b=0;b<4;b++) 
{ 
printf ("%i\t",mat[a][b]); 

} 
printf("\n"); 

} 
printf("\n"); 
transposMain(mat); 
for (a=0;a<4;a++) 
{ 
for (b=0;b<4;b++) 
{ 
printf ("%i\t",mat[a][b]); 

} 
printf("\n"); 

} 
system ("pause"); 
return(0); 
} 
*/
void fillRand(int mat [4][4]) 
{ 
int a,b; 
srand(time(NULL)); 
for (a = 0; a < 4; a++) 
{ 
for (b = 0; b < 4; b++) 
{ 
mat[a][b] =rand()%1999-999; 
} 
} 
} 

void rotateCW270(int mat [4][4]) 
{ 
int a ,b; 
int mat1[4][4] ; 
for ( a = 0; a < 4; a++) 
for (b = 0; b < 4; b++) 
mat1[a][b] = mat [b] [3 -a]; 
for ( a = 0; a < 4; a++) 
for (b = 0; b < 4; b++) 
mat[a][b] = mat1 [a] [b]; 
} 

void flipV(int mat [4][4]) 
{ 
int a ,b; 
int mat2[4][4] ; 
for (a = 0; a < 4; a++) 
for (b = 0; b < 4; b++) 
mat2 [a][b] = mat [3 - a][b]; 
for ( a = 0; a < 4; a++) 
for (b = 0; b < 4; b++) 
mat [a][b] = mat2[a][b]; 
} 
void transposMain( int mat[4][4]) 
{ 
int a ,b; 
int mat3[4][4]; 
for (a = 0; a < 4; a++) 
for (b = 0; b < 4; b++) 
mat3[a][b] = mat[b][a]; 
for ( a = 0; a < 4; a++) 
for (b = 0; b < 4; b++) 
mat[a][b] = mat3 [a][b]; 
}
