#include <stdio.h>
#include <string.h>
#include <math.h>
char * process(char * resultStr, const char * text[], int linesNum, const char * extraStr)
{
	const char * textLines;
	int i, j, flag, wordNumber = 0;
	for (i = 0; i < linesNum; i++)
	{
		textLines = text[i];
		wordNumber = 0;
		flag = 1;
		for (j = -1; j == -1 || j < strlen(textLines) && flag == 1; j++)
		{
			if (j == -1 || textLines[j] == 32 )
			{
				wordNumber++;
				if ((textLines[j + 1] != 'e' && textLines[j + 1] != 'u' && textLines[j + 1] != 'i' && textLines[j + 1] != 'o' && textLines[j + 1] != 'a' && textLines[j + 1] != 'E' && textLines[j + 1] != 'U' && textLines[j + 1] != 'I' && textLines[j + 1] != 'O' && textLines[j + 1] != 'A') && ((textLines[j + 1] <= 122 && textLines[j + 1] > 97) || (textLines[j + 1] > 65 && textLines[j + 1] <= 90)))
					flag = flag;
				else 
					flag = 0;
			}
		}
		j = 0;
		while (j <= (log10((double) wordNumber) - 1))
		{
			j++;
		}
		if (flag == 1)
		{
			i = linesNum;
			resultStr[j + 1] = ' ';
			resultStr[j + 2] = '\0';
			while (j >= 0)
			{
				resultStr[j] = wordNumber % 10 + 48;
				wordNumber /= 10;
				j--;
			}
			for (j = -1; j == -1 || j < strlen(extraStr) && flag == 1; j++)
			{	
				if (j == -1 || extraStr[j] == ' ')
				{
					if (extraStr[j + 1] == 'e' || extraStr[j + 1] == 'u' || extraStr[j + 1] == 'i' || extraStr[j + 1] == 'o' || extraStr[j + 1] == 'a' || extraStr[j + 1] == 'E' || extraStr[j + 1] == 'U' || extraStr[j + 1] == 'I' || extraStr[j + 1] == 'O' || extraStr[j + 1] == 'A') 
						flag = flag;
					else 
						flag = 0;
				}
			}
			if (flag == 1)
				strcat(resultStr, extraStr);
			else 
				strcat(resultStr, "NULL");
			
		}
	}
	return resultStr;
}
