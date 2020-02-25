//int printf(const char*, ...);
//int scanf(const char*,...);
#include<stdio.h> 
double sum(int n);
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

double sum(int n)
{
  int i;
  double k=1;
  double s=0;
  for(i=1;i<=n;i++)
  {
    if((i%2)==0) s+=1.0/(i)double;
    else s-=1.0/(i)double;
    
    //printf("%lf ", s);
  }
  return s;
  //if(n==1) return 1;
  //else return 1.0/(double)(f(n))+sum(n-1);
}