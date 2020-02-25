#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 1<<24
#define LEN 1234

double test(char * (*strlen_)( char*, const char*), char* s1, const char *s2);
int strlen_(const char *string);
char *strcpy_(char *string1, const char *string2);

int main(int argc, char *argv[])
{
	char *s1, *s2;
	int z;
	double t_std, t_my;
	if(argc!=2)
	{
		printf("Usage %s string", argv[0]);
		return 1;
	}
	s2=argv[1];
	z=strlen_(s2);
	s1=(char *)malloc(z*sizeof(char));
	t_std=test(strcpy,s1,s2);
	printf("Time std:%lf\n",t_std/CLOCKS_PER_SEC );	
	t_my=test(strcpy_,s1, s2);
	printf("Time my:%lf\n",t_my/CLOCKS_PER_SEC );
	free(s1);
	//strcpy_(s1,s2);
	//printf("%s\n", s1);
	return 0;
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

double test(char * (*strlen_)( char*, const char*), char* s1, const char *s2)
{ 
int i; 
double t; 

t=clock(); 

for(i=0;i<N;i++) 
{ 
	(*strlen_)(s1, s2); 
} 

t=clock()-t; 
printf("cpy_res=%s\n",s1); 
return t; 
}