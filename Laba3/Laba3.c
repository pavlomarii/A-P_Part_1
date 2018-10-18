#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double PI = 355.0 / 113.0;

int main()
{
	float 	a = 0.1;
	float 	b = 0.8;
	float	e = 0.0001;
	int 	n = 10;
    for(float x=a; x<=b; x+=(b-a)/10)
	{
		float Y, SN = 0, SE = 0;
		Y = 0.5-((PI/4)*fabs(sin(x)));
		for(int j=1; j<=n; j++)
		{
			SN += (cos(2*j*x)/(4*(pow(j,2))-1));
		}
		int count = 1;
		do
		{
			SE += (cos(2*count*x)/(4*(pow(count,2))-1));
			count++;
		}
		while( fabs((cos(2*count*x)/(4*(pow(count,2))-1))) >= e );
		printf("X=%f\tSumN=%f\tSumE=%f\t %d\t Y=%f\n", x, SN, SE,count-1, Y);
 	}
	return 0;
}