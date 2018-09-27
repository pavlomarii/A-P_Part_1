#include <stdio.h>

int main(void)
{
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