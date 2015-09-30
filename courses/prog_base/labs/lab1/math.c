
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calc(double, double, double);

int main() {
    double xval = 0, yval = 0, zval = 0;
    double result;

    result = calc(xval, yval, zval);

    printf("%.12f", result);
    return 0;
}

double calc(double x, double y, double z) {
   double a;
  if (x==y || z%2==1 || sin(x) == 0 || x == 0)
{return NAN}
else

  {a = pow(x,y+1)/pow(x-y,1/z) + 2*y + z/x + sqrt(abs(cos(y)/sin(x))+1)};

   return a;
}
