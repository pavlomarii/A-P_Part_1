#include <stdio.h>
#include <math.h>

long factorial(int);

int main()
{
	float n, e, fact, numerator, r, suma = 0;
	printf("n = ");
	scanf("%f", &n);
	do
	{
	    r = 3*n-3;
		fact = factorial(r);
		numerator = pow(n,3);
		e = numerator/fact;
		if (e < 0.0001)
		{
			break;
		}
		printf("n[%i] = %.4f\n",(int)n, e);
		suma = suma + e;
		n++;
	}
	while (e > 0.0001);
	printf("Suma = %.4f\n", suma);
	return 0;
}

long factorial(int n)
{
	int c;
	long result = 1;
	
	for (c = 1; c <= n; c++)
		result = result * c;
	return result;
}	