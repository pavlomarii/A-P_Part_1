#include <stdio.h> 

int findGCD(int num1, int num2) 
{
    if (num2 == 0) 
    {
        return num1;
    }
    if (num1 % num2 == 0) 
    {
        return num2;
    }
    return findGCD(num2, num1 % num2);
}

int nok(int k, int n, ...)
{
	int *p=&n;
    int LCM = *p;
	*p++;
    for(int i=1; i<k; i++, *p++)
    {
    	if(LCM==0||*p==0)
    	{
    		LCM = 0;
    		break;
    	}
    	LCM = LCM / findGCD(LCM, *p);
    	LCM = (LCM)*(*p);
	}
	return LCM;
}

int main(void)
{
	int n1,n2,n3,n4,n5,n6;
	printf("Enter 6 integer: ");
	scanf("%d %d %d %d %d %d", &n1, &n2, &n3, &n4, &n5, &n6);
	printf("\n\nLCM of three numbers is: %d", nok(3, n1, n2, n3));
	printf("\nLCM of five numbers is: %d", nok(5, n1, n2, n3, n4, n5));
	printf("\nLCM of six numbers is: %d", nok(6, n1, n2, n3, n4, n5, n6));
	scanf("%d", &n1);
	return 0;
}