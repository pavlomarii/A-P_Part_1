#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxlen 255
char buffer[maxlen];

void writeFile();
int scanLine()
{
	FILE *f1=fopen("forLab.txt", "r");
	FILE *f2=fopen("forLab1.txt", "w");
	int lenth;
	while(fgets(buffer, maxlen, f1)!=NULL)
	{
		for(int i=0; i<255; i++)
		{
			if(buffer[i]=='\n' || buffer[i]=='\0')
			{
				lenth=i;
				break;
			}
			else if(i==254)
			{
				return 1;
			}
		}
		int amount = 0;
		int start1;
		int start = 0;
		int finish;
		int finish1;
		char compareable[20],compared[20];
		for(int j=0;j<lenth;j++) {
			if(!isalpha(buffer[j]) && (j-start)>1) 
			{
				finish=j;
				for(int k=start, l=0;k<finish;k++,l++)
				{
					compareable[l]=buffer[k];
				}
				start=finish;
				do
				{
					start++;
				} 
				while(!isalpha(buffer[start]) && start<lenth);
				if(start==lenth) 
				{
					break;
				}
				start1=start;
				for(int m=start1; m<lenth;m++) {
					if(!isalpha(buffer[m]) && (m-start1)>1) {
						finish1=m;
						for(int k=start1,l=0;k<finish1;k++,l++){
							compared[l]=buffer[k];
						}
						if(strcmp(compareable,compared)==0) 
						{
							amount++;
						}
						memset(&compared[0],0,sizeof(compared));
						start1=finish1;
						do
						{
							start1++;
						} 
						while(!isalpha(buffer[start1]) && start1<lenth);
						if(start1==lenth) 
						{
							break;
						}
					}			
				}
				memset(&compareable[0],0,sizeof(compareable));
			}
			memset(&compareable[0],0,sizeof(compareable));
		}
		if(amount==0) 
		{
			fputs(buffer,f2);	
		}

		amount=0;
	}
	fclose(f1);
	fclose(f2);
	int counter=0;
	f2 = fopen("forLab1.txt", "r");
	if(fgets(buffer, maxlen, f2)!=NULL)
	{
		for(int i=0; buffer[i]!='\0'; i++)
		{
			if(toupper(buffer[i])=='A'||toupper(buffer[i])=='U'||
				toupper(buffer[i])=='E'||toupper(buffer[i])=='O'||
				toupper(buffer[i])=='I')
			{
				counter++;
			}
		}
	}
	printf("Amount of HOLOSNI bukvy: %d\n\n", counter);
	fclose(f2);
	return 0;
}

int main()
{
	int n;
	writeFile();
	scanLine();
	printf("\nThe data was successfully written to file 2");
	printf("\nEnter number of file (1 or 2):");
	do
	{
	    scanf("%d", &n);
    }
    while(n<1||n>2);
	if(n==1)
	{
	    FILE *f1 = fopen("forLab.txt", "r");
	    while(fgets(buffer, maxlen, f1)!=NULL)
	    {
	        printf("%s", buffer);
	    }
	    fclose(f1);
	}
	else 
	{
	    FILE *f2 = fopen("forLab1.txt", "r");
	    while(fgets(buffer, maxlen, f2)!=NULL)
	    {
	        printf("%s", buffer);
	    }
	    fclose(f2);
	}
	getchar();
	getchar();
	return 0;
}

void writeFile()
{
	FILE *file1 = fopen("forLab.txt", "w");
	printf("\nEnter strings you want to write in file:\n");
	for(int i=0; i<10; i++)
	{
		fgets(buffer, maxlen, stdin);
		if(buffer[strlen(buffer)-1]!='\n')
		{
			buffer[strlen(buffer)]='\n';
			buffer[strlen(buffer)+1]='\0';	
		}
		fputs(buffer, file1);
	} 
	fclose(file1);
	printf("\nThe data was wrote successfully!\n\nPrinting your strings:\n");
	file1=fopen("forLab.txt", "r");
	while(fgets(buffer, maxlen, file1)!=NULL)
	{
		printf("%s", buffer);
	}
	fclose(file1);
}
