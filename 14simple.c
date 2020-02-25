//int printf(const char*, ...);
//int scanf(const char*,...);
#include<stdio.h> 
unsigned long int simam(unsigned long int n);
unsigned long int simple(unsigned long int n);
int check(unsigned long int n);

int main()
{
	unsigned long int n;
	unsigned long int q;
	scanf("%lu", &n);
	if(check(n)==0) return 0;
	q=simam(n);
	printf("%lu", q);
  return 0;
}

int check(unsigned long int n)
{
	if(n<0){ printf("ERROR");
	return 0;}
	else return 1;
}

unsigned long int simple(unsigned long int n)
{
	unsigned long int i;
	for(i=2;i<n;i++)
		{
			if(n%i==0)return 0;
		}
	return 1;
}
unsigned long int simam(unsigned long int n)
{
	unsigned long int i,sum=0;
	for(i=2;i<n;i++)
	{
		if(simple(i)==1)sum++;
	}
  	return sum;
}
