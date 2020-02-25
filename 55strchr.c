#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 1<<29
#define LEN 1234

double test(char*(*strlen_)( const char*, int ch), const char* s,int ch);
int strlen_(const char *string);
char *strchr_(const char *string, int ch);

int main(int argc, char *argv[])
{
	char *s1;
	int n;
	double t_std,t_my;
	if(argc!=3 || !(n=atoi(argv[2])))
	{
		printf("Usage %s string1 n", argv[0]);
		return 1;
	}
	s1=argv[1];
	t_std=test(strchr,s1,n);
	printf("Time std:%lf\n",t_std/CLOCKS_PER_SEC );	
	t_my=test(strchr_,s1, n);
	printf("Time my:%lf\n",t_my/CLOCKS_PER_SEC );
	/*if(strchr_(s1,n)!=NULL)
		printf("%s\n",strchr_(s1, n));
	else
		printf("0\n");*/
	return 0;
}
// переделать
char *strchr_(const char *string, int ch)
{
	int i, flag=0;
	//char *k=string;
	for(i=0;string[i];i++)
	{
		if(string[i]==ch)
		{
			flag=1;
			break;
		}
	}
	if(ch==0){return (char*)(string+i);}
	if(flag!=0)
		return (char*)(string+i);
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

double test(char*(*strlen_)( const char*, int ch), const char* s,int ch)
{ 
int i; 
double t;
char* key;


t=clock(); 

for(i=0;i<N;i++) 
{ 
	key=(*strlen_)(s, ch); 
} 

t=clock()-t; 
if(key!=NULL)
		printf("%s\n",key);
	else
		printf("0\n");
//printf("chr_res=%s\n",key); 
return t; 
}