#include "General.h"

void main(void)
{
	char ** check = malloc(sizeof(char*) * 5);
	char ** help = check;
	string aaa[5];
	for (int i = 0; i < 5; i++)
	{
		scanf("%s", &aaa[i]);
		*check = aaa[i];
		check++ ;
	}
	alphabeticOrder(help,5);

	for (int i = 0; i < 5; i++)
	{
		puts(aaa[i]);
	}

	free(check);
}