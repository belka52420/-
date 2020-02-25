//int printf(const char*, ...);
//int scanf(const char*,...);
#include<stdio.h> 
unsigned int binarymax(unsigned int n);
unsigned int add(unsigned int n);
unsigned int binpew(unsigned int n);
int bitc(unsigned int n);
int printbit(unsigned int n, unsigned int len);

int main()
{
  unsigned int n,q,l,len;
  scanf("%u", &n);
  len=bitc(n);
  printbit(n,len);
  l=add(n);
  q=binarymax(l);
  printbit(q,len);
  printf(" %u", q);
  return 0;
}

unsigned int binpew(unsigned int n)
{
  return 1<<n;
}


unsigned int add(unsigned int n)
{
  unsigned int i,m,k,l;
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
  printf("%d", m);
  return m;
}

int bitc(unsigned int n)
{
  int i=0;
    do
  {
    i++;
    n>>=1;
  }
  while(n);
  return i;
}

int printbit(unsigned int n, unsigned int len)
{
  int i=0;
  for(i=len; i>0; i--)
  {
    printf("%d", ((n>>(i-1))&1));
  }
  printf("\n");
  return 1;
}

unsigned int binarymax(unsigned int n)
{
  unsigned int m,k,pre,sum,max;
  int i;
  m=0;
  sum=0;
  max=0;
  for(i=bitc(n);i>=0;i--)
  {     
      if((n-binpew(i))>=0)
      {
        k=i;
        break;
      }
  }
  pre=k+1;
  for(i=k;i>=0;i--)
  {
    if((n-binpew(i))>=0)
    {
      n-=binpew(i);
      if((pre-i)==1)
      {
        sum++;
      } 
      else
      {
        if(sum>=max)
        {
          max=sum;
        }
        sum=1;
      }
      pre=i;
    }
  }
  if(sum>=max)
        {
          max=sum;
        }
  
  return max;
}