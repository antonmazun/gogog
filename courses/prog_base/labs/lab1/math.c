#import <math.h>


double calc(double x, double y, double z) {
   double a;
  if (x==y || z%2==1 || sin(x) == 0 || x == 0)
{return NAN}
else

  {a = pow(x,y+1)/pow(x-y,1/z) + 2*y + z/x + sqrt(abs(cos(y)/sin(x))+1)};

   return a;
}
