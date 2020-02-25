#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1234

int strlen_(const char *string);
char *strstr_(const char *string1, const char *string2);

int main(int argc, char *argv[])
{
	char *s1, *s2, *n;
	int z;
	if(argc!=3)
	{
		printf("Usage %s string1 string2", argv[0]);
		return 1;
	}
	s1=argv[1];
	s2=argv[2];
	n=strstr_(s1, s2);
	if(n!=NULL)
		printf("%s\n",n);
	else
		printf("0\n");
	
	return 0;
}

char *strstr_(const char *string1, const char *string2)
{
	int n1=strlen_(string1), n2=strlen_(string2),i ,j, flag=0;
	for(i=0; i<n1-n2+1; i++)
	{
		if(string1[i]==string2[0])
		{
			for(j=1; j<n2; j++)
			{
				if(string1[i+j]!=string2[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
				return (char*)(string1+i);
			else
				flag=0;
		}
		
	}

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