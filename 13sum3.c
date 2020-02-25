//int printf(const char*, ...);
//int scanf(const char*,...);
#include<stdio.h> 
double sum(int n);
int f(int n);
int pew(int n, int m);
int check(int n);

int main()
{
	int n;
	double q;
	scanf("%d", &n);
  if(check(n)==0) return 0;
	q=sum(n);
	printf("%.40lf", q);
  return 0;
}

int check(int n)
{
  if(n<0){ printf("ERROR");
  return 0;}
  else return 1;
}

int f(int n)
{
  int i,m=1;
  if (n==0 || n==1)
  {
    return 1;
  }
  for(i=1;i<=n;i++)
  {
    m=m*i;
  }
  //printf("%d",m);
  return m;
}

int pew(int n,int m)
{
  int i,k;
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

double sum(int n)
{
  double i,k=1;
  double s=0;
  for(i=1;i<=n;i++)
  {
    k=(k*2)/i;
    s+=k;
  }
  return s;
  //if(n==1) return 2;
  //else return (double)pew(2,n)/(double)fuck(n)+sum(n-1);
}