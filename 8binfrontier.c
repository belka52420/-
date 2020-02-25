//int printf(const char*, ...);
//int scanf(const char*,...);
#include<stdio.h> 
int check(double n);
//double binpew(int n); 
double pew(double n,int m);
int binfrontier(double n);
int revbinfrontier (double n);
float revpew(float n, int m);

int main(void)
{
  int q;
  double n;
  scanf("%lf", &n);
  if(check(n)==0) return 0;
  if(n>=1.0)q=binfrontier(n);
  else q=revbinfrontier(n);
  printf(" %d", q);
  return 0;
}

int check(double n)
{
	if(n<0){ printf("ERROR");
	return 0;}
	else return 1;
}

double pew(double n,int m)
{
  int i;
  double k;
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
/*float revpew(float n, int m)
{
	float k;
	int i;

	for (i=0;i<=m;i++)
	{
		n=n/k;
	}
	return n;
}*/

 /*double binpew(int n)
{
  int i;
  double k;
  i=1.0;
  k=i<<n;
  return k;
}*/

int binfrontier(double n)
{
  int i,k;
  double l;

  for(i=340;i>=0;i--)
  {
    l=pew(2,i);
    if((n-l)>=0)
    {
      k=i;
      //printf("\n %d ", l);
      break;
    }
  }

  return k;
}

int revbinfrontier( double n)
{
	double i,k;
	double l;
 
  for(i=0;i<340;i++)
  {
    l=1./pew(2,i);
    if((n-l)>=0)
    {
      k=i;
      //printf("\n %f ", l);
      break;
    }
  }
  //printf("\n %lf ", k);
  return -k;
}