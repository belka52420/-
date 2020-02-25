#include <stdio.h>
#include <string.h>
#include "f.h"
#define LEN 1234
#define ERROR_OPEN_A -1
#define ERROR_OPEN_B -2
#define ERROR_READ_A -3
#define ERROR_WRITE_B -4
#define SUCCESS 0

int f(const char *a, const char *b, const char *s, const char *t)
{
	FILE *in, *out;
	char buf[LEN];
	int instr[256];
	int counter=0,i,j=0,len,len2,flag=0;
	len = strlen(t);
	len2 = strlen(s);
	if(!(in=fopen(a,"r")))
		return ERROR_OPEN_A;
	if(!(out=fopen(b,"w")))
	{
		fclose(in);
		return ERROR_OPEN_B;
	}
	for(i=0;i<256;i++)
	{
		instr[i] = 0;
	}
	for(i=0;i<len2;i++)
	{
		instr[s[i]] = 1;
	}
	while(fgets(buf, LEN, in))
	{
		for(i=0;buf[i];i++)
		{
			if(buf[i]=='\n')
			{
				buf[i] = 0;
				fprintf(out,"\n");
				break;
			}
			if(instr[buf[i]]==1)
			{
				for(j=0;j<len2;j++)
				{
					if(buf[i]==s[j])
					{
						if(j<len)
						{
							fprintf(out,"%c",t[j]);

						}
						counter++;
						
					}
				}
			}
			else
			{
				fprintf(out,"%c",buf[i]);
			}
		}
	}
	return counter;
}