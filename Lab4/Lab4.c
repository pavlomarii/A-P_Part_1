#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int size;
	int Array[250];
	
	//input size of array
	printf("\nEnter size of array: ");
	scanf("%d", &size);
	printf("\n");

	//input elements of array
	for (int i=0; i<size; i++)
	{
		printf("Array[%d]=", i);
		scanf("%d", &Array[i]);
	}
	
	//print an Array
	printf("\nArray is:{");
	for (int i=0; i<size; i++)
	{
		printf("%d ",Array[i]);
	}
	printf("\b}\n");
	
	//input K
	int K;
	printf("\nEnter your K: ");
	scanf("%d", &K);
	while (K<1||K>size)
	{
	    printf("It must equal to Array size: ");
	    scanf("%d", &K);
	}
	
	//Array from K to K-1
	printf("\nCircle from K to K-1:{");
	for (int i=K-1; i<size; i++)
	{
	    printf("%d ", Array[i]);
	}
	for (int i=0; i<K-1; i++)
	{
	    printf("%d ", Array[i]);
	}
	printf("\b}\n\n");
	
	//Adding elements
	Array[size]=Array[0];
	Array[size+1]=Array[size-1];
	size+=2;
	
	//Printing Array
	printf("Array after adding:{");
	for (int i=0; i<size;i++)
	    printf("%d ", Array[i]);
	printf("\b}\n");  
	
	//Deleting elments
	printf("\nArray after deleting:{");
	for (int i = 0; i < size; ++i)
	{
		if (Array[i]%2==1 || Array[i]%2==-1)
		{
			printf("%d ", Array[i]);
		}
	}
	printf("\b}\n");

	//Circle after deleting
	printf("\nCircle from K to K-1 after deleting:{");
	for (int i=K-1; i<size; i++)
	{
	    if (Array[i]%2==1 || Array[i]%2==-1)
	    	printf("%d ", Array[i]);
	}
	for (int i=0; i<K-1; i++)
	{
		if (Array[i]%2==1 || Array[i]%2==-1)
	    printf("%d ", Array[i]);
	}
	printf("\b}\n\n");

	scanf("%d", size);
	return 0;
}