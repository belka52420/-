#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1234

int strlen_(const char *string);
char *strchr_(const char *string, int ch);

int main(int argc, char *argv[])
{
	char *s1;
	int z,n;
	if(argc!=3 || !(n=atoi(argv[2])))
	{
		printf("Usage %s string1 n", argv[0]);
		return 1;
	}
	s1=argv[1];
	if(strchr_(s1,n)!=NULL)
		printf("%s\n",strchr_(s1, n));
	else
		printf("0\n");
	return 0;
}

char *strchr_(const char *string, int ch)
{
	int l=strlen_(string),i, flag=-1;
	//char *k=string;
	for(i=0;i<=l;i++)
	{
		if(string[i]==ch)
		{
			flag=i;
		}
	}
	
	if(flag!=-1)
		return (char*)(string+flag);
	else
		return NULL;

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