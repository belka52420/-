//int printf(const char*, ...);
//int scanf(const char*,...);
#include<stdio.h> 
double sum(int n);
int check(int n);

int main(void)
{
	int n;
	double q;
	scanf("%d", &n);
  if(check(n)==0) return 0;
	q=sum(n);
	printf("%.50lf", q);
  return 0;
}

int check(int n)
{
  if(n<0){ printf("ERROR");
  return 0;}
  else return 1;
}

/*int f(int n)
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
}*/

double sum(int n)
{
  double i,k=1;
  double s=0;
  for(i=1;i<=n;i++)
  {
    k=k/i;
    s+=k;
    //printf("%lf ", s);
  }
  return s;
  //if(n==1) return 1;
  //else return 1.0/(double)(f(n))+sum(n-1);
}
