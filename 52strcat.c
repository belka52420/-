#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1234

char *strcpy_(char *string1, const char *string2);
int strlen_(const char *string);
char *strcat_(char *string1, const char *string2);

int main(int argc, char *argv[])
{
	char *s1, *s2;
	int z;
	if(argc!=3)
	{
		printf("Usage %s string1 string2", argv[0]);
		return 1;
	}
	s2=argv[2];
	z=strlen_(s2)+strlen_(argv[1])+1;
	//printf("%c\n", *(argv[2]+5));
	s1=(char *)malloc(z*sizeof(char));
	strcpy_(s1, argv[1]);
	strcat_(s1,s2);
	printf("%s\n", s1);
	return 0;
}

char *strcat_(char *string1, const char *string2)
{
	int key1=strlen_(string1),key2=strlen_(string2),i;
	for(i=0;i<=key2;i++)
	{
		string1[key1+i]=string2[i];
	}

	return string1;

}

int strlen_(const char *string)
{
	int i=0;
	while(1)
	{
		if(*(string+i)=='\0')
			break;
		i++;

	}
	 return i;
}

char *strcpy_(char *string1, const char *string2)
{
	int i;
	for(i=0; string2[i]; i++)
	{
		string1[i]=string2[i];
		
	}
	return string1;
}