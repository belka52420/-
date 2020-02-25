#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 1<<29
#define LEN 1234

double test(int(*strlen_)( const char*, const char*), const char* s1, const char *s2);
int strlen_(const char *string);
int strcmp_(const char *string1, const char *string2);

int main(int argc, char *argv[])
{
	char *s1, *s2;
	//int z;
	double t_std, t_my;
	if(argc!=3)
	{
		printf("Usage %s string1 string2", argv[0]);
		return 1;
	}
	s2=argv[2];
	s1=argv[1];
	t_std=test(strcmp,s1,s2);
	printf("Time std:%lf\n",t_std/CLOCKS_PER_SEC );	
	t_my=test(strcmp_,s1, s2);
	printf("Time my:%lf\n",t_my/CLOCKS_PER_SEC );
	/*if(strcmp_(s1,s2)==1)
		printf("string1 > string2\n");
	if(strcmp_(s1,s2)==-1)
		printf("string1 < string2\n");
	if(strcmp_(s1,s2)==0)
		printf("string1 = string2\n");*/
	return 0;
}

int strcmp_(const char *string1, const char *string2)
{
	int num1=strlen_(string1), num2=strlen_(string2),i;
	if(num1<=num2)
	{
		for(i=0;i<num1; i++)
		{
			if(string1[i]<string2[i])
			{
				return -1;
			}
			if(string1[i]>string2[i])
			{
				return 1;
			}

		}
		if(num1!=num2)
			return -1;
		else
			return 0;
	}
	else
	{
		for(i=0;i<num2; i++)
		{
			if(string1[i]<string2[i])
			{
				return -1;
			}
			if(string1[i]>string2[i])
			{
				return 1;
			}

		}

		return -1;
	}

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

double test(int(*strlen_)( const char*, const char*), const char* s1, const char *s2)
{ 
int i, key; 
double t;


t=clock(); 

for(i=0;i<N;i++) 
{ 
	key=(*strlen_)(s1, s2); 
} 

t=clock()-t; 
printf("cmp_res=%d\n",key); 
return t; 
}