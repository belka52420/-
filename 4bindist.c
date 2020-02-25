//int printf(const char*, ...);
//int scanf(const char*,...);
#include<stdio.h> 
int check(int n);
int pew(int n, int m);
int binarydist(int n);
int binpew(int n);

int main()
{
  int n,q;
  scanf("%d", &n);
  if(check(n)==0) return 0;
  q=binarydist(n);
  printf(" %d", q);
  return 0;
}

int check(int n)
{
	if(n<0){ printf("ERROR");
	return 0;}
	else return 1;
}

int binpew(int n)
{
  int i;
  double k;
  i=1.0;
  k=i<<n;
  return k;
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

int binarydist(int n)
{
  int i,k,l;
  for(i=20;i>=0;i--)
  {
    if((n-binpew(i))>=0)
    {
      k=i;
      //printf("\n %d ", l);
      break;
    }
  }
  for(i=k;i>=0;i--)
  {
    if((n-binpew(i))>=0)
    {
      n-=binpew(i);
      l=i;
    }
  }
  return k-l-1;
}