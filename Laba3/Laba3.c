#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double PI = 355.0 / 113.0;

float first(int n, float x);
float second(float x);

int main()
{
	float 	a = 0.1;
	float 	b = 0.8;
	float	e = 0.0001;
	int 	n = 10;


	for(float x=a; x<=b; x+=(b-a)/10)
	{
		float Y, SN = 0, SE = 0;
		
		Y = second(x);
		
		for(int j=1; j<=n; j++)
		{
			SN += first(j, x);
		}
	
		int count = 0;
		float inc = 0;
		
		do
		{
			inc = first(++count, x);
			SE += inc;
		}
		while( fabs(inc)>=e );
		
		printf("X=%.5f\tSumN=%.5f\tSumE=%.5f\tY=%.5f\n", x, SN, SE, Y);
 	}
	
	return 0;
}

float first(int n, float x)
{
	return (cos(2*x*n))/(4*(pow(x,2))-1);
}

float second(float x)
{
 return 0.5-(PI/4)*fabs(sin(x));
}