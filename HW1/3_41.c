#include <stdio.h>
#include <math.h>
int main(void)
{
double eps; double a=0.0;
double b; double almost_pi; long double pi;
b = sqrt(0.5);
almost_pi = b;
scanf("%lf", &eps);
while (fabs(b-a)>eps)
    {
    a = b;
    b = sqrt(0.5 + (0.5*a));
    almost_pi *= b;
    };
pi = 2.0/almost_pi;
printf("%Lf\n", pi);
return 0;
}
