#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 1<<29
#define LEN 1234

double test(size_t(*strlen_)( const char*, const char*), const char* s1, const char *s2);
int strlen_(const char *string);
size_t strcspn_(const char *string1, const char *string2);

int main(int argc, char *argv[])
{
	char *s1, *s2;
	double t_my, t_std;
	//int z,n;
	if(argc!=3)
	{
		printf("Usage %s string1 string2", argv[0]);
		return 1;
	}
	s1=argv[1];
	s2=argv[2];
	t_std=test(strcspn,s1,s2);
	printf("Time std:%lf\n",t_std/CLOCKS_PER_SEC );	
	t_my=test(strcspn_,s1, s2);
	printf("Time my:%lf\n",t_my/CLOCKS_PER_SEC );
	//n=strcspn_(s1, s2);
	//printf("%d\n", n);
	return 0;
}

int strcspn_(const char *string1, const char *string2)
{
	int n1=strlen_(string1), n2=strlen_(string2),i ,j;
	for(i=0; i<n1; i++)
	{
		for(j=0; j<n2; j++)
		{
			if(string1[i]==string2[j])
				return i;
		}
	}

	return i;
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

double test(size_t(*strlen_)( const char*, const char*), const char* s1, const char *s2)
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