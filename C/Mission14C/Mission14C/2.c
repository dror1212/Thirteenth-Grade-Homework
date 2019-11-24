#include "General.h"

void main2(void)
{
	string s;
	gets(s);
	char y = 't';
	char * x = &y;
	SearchLongestWord(s, &x);
	puts(x);
	free(x);
	_getch();
}