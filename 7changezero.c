//int printf(const char*, ...);
//int scanf(const char*,...);
#include<stdio.h> 
int check(int n);
int pew(int n, int m);
int cold_blood(int n);
int add_(int n);
int add(int n);
int binpew(int n);

int main()
{
  int n,q,l;
  scanf("%d", &n);
  if(check(n)==0) return 0;
  l=add_(n);
  q=cold_blood(l);
  printf(" %d", add(q));
  return 0;
}

int check(int n)
{
	if(n<0){ printf("ERROR");
	return 0;}
	else return 1;
}

int add_(int n)
{
  int i,m,k,l;
  m=0;
  for(i=20;i>=0;i--)
  {
    l=binpew(i);
    if((n-l)>=0)
    {
      k=i;
      //printf("\n %d ", l);
      break;
    }
  }
  m=binpew(k+1)-1;
  for(i=k;i>=0;i--)
  {
    if((n-binpew(i))>=0)
    {
      n-=binpew(i);
      m-=binpew(i);
    }
  }
  //printf("%d", m);
  m+=binpew(k+1);
  return m;
}

int add(int n)
{
  int i,m,k,l;
  m=0;
  for(i=20;i>=0;i--)
  {
    l=binpew(i);
    if((n-l)>=0)
    {
      k=i;
      //printf("\n %d ", l);
      break;
    }
  }
  m=binpew(k+1)-1;
  for(i=k;i>=0;i--)
  {
    if((n-binpew(i))>=0)
    {
      n-=binpew(i);
      m-=binpew(i);
    }
  }
  //printf("%d", m);
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

int binpew(int n)
{
  int i;
  double k;
  i=1.0;
  k=i<<n;
  return k;
}


int cold_blood(int n)
{
  int i,m,k,l,pre=0,mid=0,now=0, dif=0;
  m=0;
  l=n;
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
      pre=mid;
      mid=now;
      now=i;
      //printf("%d %d %d %d\n", pre,mid,now, l);
      if(((pre-1)==mid) && ((now+1)==mid)) dif+=binpew(mid);
    }
  }
  return l-dif;
}