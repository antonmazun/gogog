#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
void drawGraph1(HANDLE hConsole, int zoom, COORD pos, int OX, int OY);
void cleenScreen(HANDLE hConsole, COORD pos);
void drawGraph2(HANDLE hConsole, int zoom, COORD pos, int OX, int OY);
void drawCoordLines(HANDLE hConsole, int zoom, COORD pos, int OX, int OY);
int main (void)
{
	int zoom = 5;
	int exitValue = 0;
	int OX = 39;
	int OY = 13;
	int graph = 1;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	char ch;
	while(exitValue == 0)
	{
	
		cleenScreen(hConsole, pos);
		drawCoordLines(hConsole, zoom, pos, OX, OY);
		if (graph % 2 == 1)
			drawGraph1(hConsole, zoom, pos, OX, OY);
		else
			drawGraph2(hConsole, zoom, pos, OX, OY);
		printf("\nw - up, s - down, a - left\nd - right, + zoom in, - zoom out\nc - change graph, x - exit");
		ch = getch();
		switch (ch)
		{
			case 'c' : graph++; break;
			case 'd' : OX--; break;
			case 'a' : OX++; break;
			case 's' : OY--; break;
			case 'w' : OY++; break;
			case '+' : zoom++; break;
			case '-' : zoom--; break;
			case 'x' : exitValue = 1; break;
			default : break;
		}
	}
	int color = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
	SetConsoleTextAttribute(hConsole, color);
	
	pos.Y = 25;
	SetConsoleCursorPosition(hConsole, pos);
	puts(" ");
	
	return EXIT_SUCCESS;
}
void drawCoordLines(HANDLE hConsole, int zoom, COORD pos, int OX, int OY)
{
	if (OX > 79)
		OX = 79;
	if (OX < 0)
		OX = 0;
	if (OY > 24)
		OY = 24;
	if (OY < 0)
		OY = 0;
	pos.X = OX;
	if (zoom < 1)
		zoom = 1;
	int color = FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN;
	SetConsoleTextAttribute(hConsole, color);
	for (pos.Y = 0; pos.Y < 25; pos.Y++)
	{
		SetConsoleCursorPosition(hConsole, pos);
		if (pos.Y % zoom == OY % zoom)
			printf("+");
		else
			printf("|");
	}
	pos.Y = OY;
	for (pos.X = 0; pos.X < 80; pos.X++)
	{
		SetConsoleCursorPosition(hConsole, pos);
		if (pos.X % zoom == OX % zoom)
			printf("+");
		else
			printf("-");
	}
	/*pos.Y = 8;
	pos.X = 40;
	SetConsoleCursorPosition(hConsole, pos);
	printf("%i", (int)pow(2, -zoom));
	pos.Y = 14; 
	pos.X = 44;
	SetConsoleCursorPosition(hConsole, pos);
	printf("%i", (int)pow(2, -zoom));*/
}
void cleenScreen(HANDLE hConsole, COORD pos)
{
	int i, j;
	int color = FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN;
	SetConsoleTextAttribute(hConsole, color);
	
	for (i = 0; i < 25; i++)
		for (j = 0; j < 80; j++)
		{
			pos.X = j; 
			pos.Y = i;
			SetConsoleCursorPosition(hConsole, pos);
				putchar(' ');
		}
}
void drawGraph1(HANDLE hConsole, int zoom, COORD pos, int OX, int OY)
{
	
	int color = FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN;
	SetConsoleTextAttribute(hConsole, color);
	
	double k;
	if (zoom > 0) 
		k = (double)zoom;
	else 
		k = 1 / (1 - (double)zoom);
	for (pos.X = 0; pos.X < 80; pos.X++)
	{
		pos.Y = -round(k * 2 * sin(0.5  * ((pos.X - OX) / k ))) + OY ;
		if (pos.Y < 26 && pos.Y > -1)
		{
			SetConsoleCursorPosition(hConsole, pos);
			/*if ((pos.Y == 7 && pos.X == 40) || (pos.Y == 14 && pos.X == 44))
				printf("%i", (int)pow(2, zoom));
			else*/
				printf(" ");
		}
	}
	color = FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
	SetConsoleTextAttribute(hConsole, color);
	pos.X = 0;
	pos.Y = 0;
	SetConsoleCursorPosition(hConsole, pos);
	printf("F(x) = 2 * sin(0.5 * x)");
}
void drawGraph2(HANDLE hConsole, int zoom, COORD pos, int OX, int OY)
{
	
	
	int color = FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN;
	SetConsoleTextAttribute(hConsole, color);
	
	double k;
	if (zoom > 0) 
		k = (double)zoom;
	else 
		k = 1 / (1 - (double)zoom);
	for (pos.X = 0; pos.X < 80; pos.X++)
	{
		pos.Y = -round(k *  (1.3 * ((pos.X - OX) / k + 1) - 2)) + OY;
		if (pos.Y < 25 && pos.Y > -1)
		{
			SetConsoleCursorPosition(hConsole, pos);
			/*if ((pos.Y == 7 && pos.X == 40) || (pos.Y == 14 && pos.X == 44))
				printf("%i", (int)pow(2, zoom));
			else*/
				printf(" ");
		}
	}
	color = FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
	SetConsoleTextAttribute(hConsole, color);
	pos.X = 0;
	pos.Y = 0;
	SetConsoleCursorPosition(hConsole, pos);
	printf("F(x) = 1.3*(x + 1) - 2");
}
