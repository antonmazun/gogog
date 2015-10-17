#include "stdafx.h"

#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
 /* double long2double(long long);

int main()
{
	long long a;
	double b;
	scanf_s("%lli", &a);
	b = long2double(a);
	if (b * 100000 < 1)
		printf("%0.325lf", b);
	else
		printf("%0.50lf", b);
	system("pause");
	return 0;
}
*/

double long2double(long long a)
{
	short bit[64];
	short i;
	int c;
	double d = 0;
	if (a >= 0)
	{
		bit[63] = 0;
	}
	else
	if (a<0)
	{
		bit[63] = 1;

	}
	for (i = 0; i <= 62; i++)
	{
		if (a == 0)
			bit[i] = 0;
		else
		if (a >= 0)
		{

			bit[i] = a % 2;
			if (a % 2 == 1)
				a = (a - 1) / 2;
			else
				a = a / 2;
		}
		else
		{

			bit[i] = abs(a % 2);
			if (a % 2 == -1)
				a = (a - 1) / 2;
			else
				a = a / 2;
		}
	}
	c = bit[52];
	for (i = 53; i <= 62; i++)
	{
		c = bit[i] * _Pow_int(2, i - 52) + c;
	}
	for (i = 51; i >= 0; i--)
	{
		d = d + bit[i] * powf(2.0, i - 52);
	}
	if (c == 0 && d == 0)
	{
		if (bit[63] == 0)
			return 0;
		else
			return -0.0;
	}
	if (c == 2047 && d != 0)
	{
		if (bit[63] == 0)
			return NAN;
		else
			return -NAN;
	}
	else
	if (c == 2047 && d == 0)
	{
		if (bit[63] == 0)
			return INFINITY;
		else
			return -INFINITY;
	}
	else
	if (c == 0)
	{

		return d*pow(2.0, -1022);
		if (bit[63] == 0)
			return d*pow(2.0, -1022);
		else
			return -d*pow(2.0, -1022);
	}
	else
	if (c != 0)
	{
		c = c - 1023;
		if (bit[63] == 0)
			return (1.0 + d)*pow(2.0, c);
		else
			return -(1.0 + d)*pow(2.0, c);
	}
}
