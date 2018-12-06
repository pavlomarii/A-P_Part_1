#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char name[50];
	char author[50];
	int year;
	int pages;
} Book;

int readMyFile(int size, Book array[])
{
	FILE *f;
	f = fopen("forLab.txt", "w");
	if(f==NULL)
	{
		fprintf(stderr, "\nError open file\n");
		return 1; 
	}
	for(int i=0; i<size; i++)
	{
		printf("Enter name of %d book: ", i+1);
		scanf("%s", &array[i].name);
		printf("Enter name of %d book author: ", i+1);
		scanf("%s", &array[i].author);
		printf("Enter year of %d book: ", i+1);
		scanf("%d", &array[i].year);
		printf("Enter amount of pages of %d book: ", i+1);
		scanf("%d", &array[i].pages);
		fwrite(&array[i], sizeof(Book), 1, f);
		if(fwrite != 0)
			printf("Data is successfully recorded\n");
		else
		{
			printf("Error writing file!\n");
			return 1;	
		}
	}
	fclose (f);
	return 0;
}

void showMyFile(int size, Book array[])
{
	FILE *f;
	int i=0;
	f = fopen("forLab.txt", "r");
	while(!feof(f)&&i<size)
	{
		fread(&array[i], sizeof(Book), 1, f);
		i++;
	}
	printf("Result list:\n");
	for(i=0; i<size; i++)
	{
		printf("%i)Name: %s\n  Author: %s\n  Year: %d\n  Pages: %d\n",
			i+1,array[i].name,array[i].author,array[i].year,array[i].pages);
	}
	fclose(f);	
}

int addition_and_rewrite(int size, Book array[],char name[40]) 
{
    FILE *f;
    int i=0,breakpoint=-1, newsize=0;
    f = fopen("forLab.txt","w");
    while(!feof(f)&&i<size) 
    {
    	fread(&array[i], sizeof(Book),1,f);
    	i++;
    }
    for(i=3;i<size;i++)
    {
    	if(fwrite == 0)
        	return 1;
    	if(strcmp(array[i].name, name)==0) 
    	{
      		breakpoint=i;
      		break;
    	}
    	fwrite(&array[i], sizeof(Book),1, f);
    	newsize++;
    }
    if(breakpoint!=-1) 
    {
    	printf("Enter name of added book: ");
    	scanf("%s", &array[size].name);
        printf("Enter author of added book: ");
    	scanf("%s", &array[size].author);
        printf("Enter year of added book: ");
        scanf("%d", &array[size].year);
    	printf("Enter amount of pages of added book: ");
    	scanf("%d", &array[size].pages);
    	fwrite(&array[size], sizeof(Book),1,f);
    	newsize++;
    	for(i=breakpoint;i<size;i++) 
    	{
      		fwrite(&array[i], sizeof(Book),1,f);
      		newsize++;
    	}
  	}
  	fclose(f);
  	return newsize;
}

int main(void)
{
	int size, modsize;
	char name[40];
	
	printf("Enter amount of books: ");
	scanf("%d", &size);
	
	Book array[size+1];
	
	readMyFile(size, array);
	showMyFile(size, array);

	printf("Enter name of book, before which to add a new book: ");
	scanf("%s", &name);
	strcpy(array[size].name, name);

	modsize = addition_and_rewrite(size, array, name);
	showMyFile(modsize, array);
	
	getchar();
	getchar();
}

