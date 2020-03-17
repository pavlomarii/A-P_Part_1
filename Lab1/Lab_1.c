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

	int n, m;
	float x1;
	printf("n = ");
	scanf("%i", &n);
	printf("m = ");
	scanf("%i", &m);
	x1 = n++ *m;
	printf("1) %.1f\n", x1);
	if (n++ < m)
		printf("2) True\n");
	else
		printf("2) False\n");
	float m1 = m;
	if (m-- > m1)
		printf("3) True");
	else
		printf("3) False\n");
}
