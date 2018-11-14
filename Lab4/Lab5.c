#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void perestanovka_ryadkiv(int array, int size, int nomer_ryadka)
{
	int array2[size];
	for(int i=0; i<size; i++)
	{
		array2[i]=array[nomer_ryadka][i];
		array[nomer_ryadka][i]=array[nomer_ryadka-1][i];
		array[nomer_ryadka-1][i]=array2[i];
	}
}

void perestanovka_stovptsiv(int *array, int size, int nomer_stovptsia)
{
	int array2[size];
	for(int i=0; i<size; i++)
	{
		array2[i]=array[i][nomer_stovptsia];
		array[i][nomer_stovptsia]=array[i][nomer_stovptsia+1];
		array[i][nomer_stovptsia+1]=array2[i];
	}
}

int random_number()
{
	int result;
	result=(rand()%50);
	return result;
}

int main(void)
{
	//input size of array
	int size;
	printf("\nEnter size of array N x N: ");
	scanf("%d", &size);
	int size1 = size;
	int array[size][size];
	

	//input elements of array
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			array[i][j]=random_number();
		}
	}

	//printing array
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}

	int nomer_ryadka, nomer_stovptsia;
	int largest=0;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			if(largest<array[i][j])
			{
				largest=array[i][j];
				nomer_ryadka=i;
				nomer_stovptsia=j;
			}
		}
	}

	printf("\n\n%d\n", largest);
	

	/*do
	{

	}
	while(largest!=array[0][size-1])*/
	for(int i=nomer_ryadka; i>0; i--)
	{
		perestanovka_ryadkiv(array[0][0], size, i);
	}

	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}








	getchar();
	getchar();
	return 0;
}