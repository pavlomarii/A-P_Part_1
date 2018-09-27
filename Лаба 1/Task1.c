#include <stdio.h>
#include <math.h>

int main(void)
{
	double a = 1000, b = 0.0001, c;
	float d = 1000, e = 0.0001, f;
	c = (pow((a-b),3)-pow(a,3))/(pow(b,3)-3*a*(pow(b,2))-3*b*(pow(a,2)));
	f = (pow((d-e),3)-pow(d,3))/(pow(e,3)-3*d*(pow(e,2))-3*e*(pow(d,2)));
	printf("Double = %.10f\n", c);
	printf("Float = %.10f\n", f);
}