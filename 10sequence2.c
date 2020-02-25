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
    long unsigned int a=2,b=9,x;
    int i=1;
    for(i;i<n;i++)
    {
        x=5*b-6*a+pew(4,i);
        a=b;
        b=x;

    }
    return b;
  //if(n==0) return 2;
  //if(n==1) return 9;
  //else return 5*sequence(n-1)-6*sequence(n-2)+pew(4,n-1);
}

long unsigned int pew(long unsigned int n,int m)
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