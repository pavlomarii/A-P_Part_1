#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n;
	printf("\nStart the programm...\n\nEnter amount of string: ");
	scanf("%d", &n);
	char **mas;
	char buffer[255];
	mas=(char**)malloc(n*sizeof(char*));
	
	if(mas==NULL)
	{
		printf("Error when array creating!");
		return 0;
	}
	
	for(int i=0; i<=n; i++)
	{
		fgets(buffer, 256, stdin);
		if(buffer[strlen(buffer)-1]=='\n')
		{
			buffer[strlen(buffer)-1]='\0';
		}
		mas[i]=(char*)malloc(strlen(buffer)*sizeof(char));
		strcpy(mas[i], buffer);
	}
	printf("\n\n");
	for (int i = 0; i <= n; i++)
	{
		if(i==0)
			continue;
		printf("Your string #%d is: %s", i, mas[i]);
		printf("\n");
	}

	printf("\n\nStrings after program execution:\n");
	for(int i=0; i<=n; i++)
	{
		if(mas[i][0]=='a' || mas[i][0]=='A')
		{
			continue;
		}
		printf("%s\n", mas[i]);
	}
	free(mas);
	printf("\n\nEnd of the programm\n\n");
	getchar();
	return 0;
}