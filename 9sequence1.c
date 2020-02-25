//int printf(const char*, ...);
//int scanf(const char*,...);
#include<stdio.h> 
long unsigned int sequence(int n);
long unsigned int pew(long unsigned int n, int m);
int check(int n);

int main(void)
{
	int n;
	long unsigned int q;
	scanf("%d", &n);
	if(check(n)==0) return 0;
	q=sequence(n);
	printf("%lu", q);
	return 0;
}

int check(int n)
{
	if(n<0){ printf("ERROR");
	return 0;}
	else return 1;
}

long unsigned int sequence(int n)
{
	int i=1;
	long unsigned int x=1;
	for(i;i<=n;i++)
	{
		x=3*x+4*pew(2,i);
	}
	return x;
	//if(n==0) return 1;
	//else return 3*sequence(n-1)+4*pew(2,n);
}

long unsigned int pew(long unsigned int n,int m)
{
  int i;
  unsigned int k; 
  k=n;
  n=1;
  if(m>0)
  {
    for (i=1;i<=m;i++)
    {
      n=n*k;
    }
  }
  return n;
}