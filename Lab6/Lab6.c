#include <stdio.h>
#include <string.h>

char String[255];

int Words[255];

int Number;

int main(void)
{
	int i, j, Temp;
	int Flag; 

	printf("\nEnter your text: ");
	gets(String);

	for (Number = 0, Flag = 1, i = 0; String[i]; i++)
	{
		if (String[i] == ' ')
		{
			String[i] = 0;
			Flag = 1;
		}
		
		else if (Flag)
		{
			Words[Number++] = i;
			Flag = 0;
		}
	}

	for (j = Number - 1; j > 0; j--)
		for (i = 0; i < j; i++)
			if (strcmp(&String[Words[i]], &String[Words[i + 1]]) > 0)
			{
				Temp = Words[i];
				Words[i] = Words[i + 1];
				Words[i + 1] = Temp;
			}

	
	for (i = 0; i < Number; i++)
		printf("%s ", &String[Words[i]]);
	getchar();
	getchar();
} 