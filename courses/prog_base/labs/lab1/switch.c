#include <math.h>
int exec(int op, int a, int b)

{

	int c;

	if (op < 0)
	{
		c = a;
		a = b;
		b = c;
		op = abs(op);
	}
		switch (op){

		case 0:
				  return -a;
				  break;
		case 1:
				  return a + b;
				  break;
		case 2:
				   return a - b;
				   break;   
		case 3:
			return a * b;
				   break;
		case 4:
			if (b != 0)
				return a / b;
			else
				return 0;
			break;
		case 5:
			return abs(a);
			break;
		case 6:
			return _Pow_int(a, b);
			break;
		case 7:
		case 13:
		case 77:
			if (b != 0)
				return a%b;
			else
				return 0;
			break;
		case 8:
			return __max(a, b);
			break;
		case 9:
			return __min(a, b);
			break;
		case 10:
	
			switch (abs(b) % 8){
			case 0:
				return abs(a)*sizeof(char);
				break;
			case 1:
				return abs(a) * sizeof (signed char);
				break;
			case 2:
				return abs(a) * sizeof (short);
				break;
			case 3:
				return abs(a) * sizeof (unsigned int);
				break;
			case 4:
				return abs(a) * sizeof (long);
				break;
			case 5:
				return abs(a) * sizeof (unsigned long long);
				break;
			case 6:
				return abs(a) * sizeof (float);
				break;
			case 7:
				return abs(a) * sizeof (double);
				break;
				
			}
		case 11 :
			if (a != 0)
				return 2 * M_PI * cosf(2 * a*b) / a;
			else
			return 0;
			break;

		default:
		
				   if (op < 100)
					   return (op % abs(a + 1)) + (op % abs(b + 1));
				   else
					   return -1;
		
			
		}


}
