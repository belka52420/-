#include <stdio.h>
#include <string.h>
#include "f.h"
#define LEN 1234
#define ERROR_OPEN_A -1
#define ERROR_OPEN_B -2
#define ERROR_READ_A -3
#define ERROR_WRITE_B -4
#define SUCCESS 0

int main(int argc, char *argv[])
{
	int result;
	char *a;
	char *b;
	char *s;
	char *t;
	if (argc!=5)
	{
		printf("usage: %s a.txt b.txt string1 string2\n", argv[0]);
		return 1;
	}
	a = argv[1];
	b = argv[2];
	s = argv[3];
	t = argv[4];
	result = f(a,b,s,t);
	if(result < 0)
	{
		switch(result)
		{
			case ERROR_OPEN_A:
			printf("cannot open a");
			case ERROR_OPEN_B:
			printf("cannot open b");
			case ERROR_READ_A:
			printf("cannot read a");
			case ERROR_WRITE_B:
			printf("cannot write b");
			default:
			printf("unknown ERROR");
		}
		return 2;
	}
	printf("Result = %d\n", result);
	return 0;
}