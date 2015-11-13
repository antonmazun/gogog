#include <stdio.h>
#include <windows.h>
int main(void)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const long SLEEP_MILLISECONDS = 10; 
	COORD pos;  
    pos.X = 0; 
    pos.Y = 0; 
	int i, j;
	int num = 0;
	int f = 1;
    pos.X = 0;
	pos.Y = 0;
	int k =  FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
	SetConsoleTextAttribute(hConsole, k);
	for (i = 0; i < 24; i++)
		for (j = 0; j < 80; j++)
		{
			pos.X = j; 
			pos.Y = i;
			SetConsoleCursorPosition(hConsole, pos);
		printf(" ");
		}
	i = 12;
	j = 12;
    while(i < 24 && j < 80) {
		num++;
		num = -num;
		for (j = 24 - i; j < 56 + i; j++)
		{
			switch (i % 3){
				case 0: k = BACKGROUND_RED; break;
				case 1: k = BACKGROUND_RED | BACKGROUND_GREEN; break;
				case 2: k = BACKGROUND_RED | BACKGROUND_BLUE; break;
			}
			SetConsoleTextAttribute(hConsole, k);
			pos.X = j;
			pos.Y = i;
			SetConsoleCursorPosition(hConsole, pos);
			printf(" ");
			Sleep(SLEEP_MILLISECONDS); 
		}
		f = i;
		for (i = f; i > f + num ; i--)
		{
			switch (i % 3){
				case 0: k = BACKGROUND_RED; break;
				case 1: k = BACKGROUND_RED | BACKGROUND_GREEN; break;
				case 2: k = BACKGROUND_RED | BACKGROUND_BLUE; break;
			}
			SetConsoleTextAttribute(hConsole, k);
			pos.X = j;
			pos.Y = i;
			SetConsoleCursorPosition(hConsole, pos);
			printf(" ");
			Sleep(SLEEP_MILLISECONDS); 
		}
		for (j = 79 - i; j > i; j--)
		{
			switch (i % 3){
				case 0: k = BACKGROUND_RED; break;
				case 1: k = BACKGROUND_RED | BACKGROUND_GREEN; break;
				case 2: k = BACKGROUND_RED | BACKGROUND_BLUE; break;
			}
			SetConsoleTextAttribute(hConsole, k);
			pos.X = j;
			pos.Y = i;
			SetConsoleCursorPosition(hConsole, pos);
			printf(" ");
			Sleep(SLEEP_MILLISECONDS); 
		}
		num = -num;
		num++;
		f = i;
		for (i = f; i < f + num ; i++)
		{
			switch (i % 3){
				case 0: k = BACKGROUND_RED; break;
				case 1: k = BACKGROUND_RED | BACKGROUND_GREEN; break;
				case 2: k = BACKGROUND_RED | BACKGROUND_BLUE; break;
			}
			SetConsoleTextAttribute(hConsole, k);
			pos.X = j;
			pos.Y = i;
			SetConsoleCursorPosition(hConsole, pos);
			printf(" ");
			Sleep(SLEEP_MILLISECONDS); 
		}
    }
	k = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
	SetConsoleTextAttribute(hConsole, k);
	return EXIT_SUCCESS;
}
