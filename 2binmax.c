//int printf(const char*, ...);
//int scanf(const char*,...);
#include<stdio.h> 
int check(int n);
int pew(int n, int m);
int bitc(int n);
int printbit(int n, int len);
int binarymax(int n);
int binpew(int n);

int main(void)
{
  int n,q,l;
  scanf("%d", &n);
  l=bitc(n);
  printbit(n,l);
  if(check(n)==0) return 0;
  q=binarymax(n);
  printf(" %d", q);
  return 0;
}

int printbit(int n, int len)
{
  int i=0;
  for(i=len; i>0; i--)
  {
    printf("%d", ((n>>(i-1))&1));
  }
  printf("\n");
  return 1;
}

int bitc(int n)
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

int check(int n)
{
	if(n<0){ printf("ERROR");
	return 0;}
	else return 1;
}

int binpew(int n)
{

  return 1<<n;
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

int binarymax(int n)
{
  int i,k,pre,sum,max;
  //m=0;
  sum=0;
  max=0;
  for(i=20;i>=0;i--)
  {     
      if((n-binpew(i))>=0)
      {
        k=i;
        //printf("\n %d ", l);
        break;
      }
  }
  pre=k+1;
  for(i=k;i>=0;i--)
  {
    if((n-=binpew(i))>=0)
    {
      //n-=binpew(i);
      if((pre-i)==1)
      {
      	//printf("%d \n",i);
        sum++;
        
        //pre=i;
      } 
      else
      {
        if(sum>=max)
        {
          max=sum;
          //pre=i;
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