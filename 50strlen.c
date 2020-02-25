#include <stdio.h>
#include <string.h>
#include <time.h>
//#define LEN 1234
#define N 1<<24

double test(size_t (*strlen_)(const char*),const char* s);

size_t strlen_(const char *string);

int main(int argc, char *argv[])
{
	
	char *s;
	double t_std, t_my;
	if(argc!=2)
	{
		printf("Usage %s string", argv[0]);
		return 1;
	}
	s=argv[1];

	t_std=test(strlen,s);
	printf("Time std:%lf\n",t_std/CLOCKS_PER_SEC );	
	t_my=test(strlen_,s);

	printf("Time my:%lf\n",t_my/CLOCKS_PER_SEC );
	return 0;
}

size_t strlen_(const char *string)
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

double test(size_t (*strlen_)(const char*),const char* s) 
{ 
int i,len; 
double t; 

t=clock(); 

for(i=0;i<N;i++) 
{ 
len=(*strlen_)(s); 
} 

t=clock()-t; 
printf("len_res=%d\n",len); 
return t; 
}