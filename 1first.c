int printf(const char*, ...);
int scanf(const char*,...);
int check(int n);
int binarysh(int n);
int bitc(int n);
int printbit(int n, int len);
int pew(int n, int m);
int binpew(int n);
int main(void)
{
	int n,q,l;
	scanf("%d", &n);
	l=bitc(n);
	
	printbit(n,l);
	if(check(n)==0) return 0;
	q=binarysh(n);
	printbit(q,l);
	printf("\n%d\n",q);
	return 0;
}


int binpew(int n)
{
  int i;
  double k;
  i=1.0;
  k=i<<n;
  return k;
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


int check(int n)
{
	if(n<0){ printf("ERROR");
	return 0;}
	else return 1;
}

int pew(int n,int m)
{
  int i,k;
  k=n;
  n=1;
  if(m>0){
  for (i=1;i<=m;i++)
  {
    n=n*k;
  }
  }
  return n;
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

int binarysh(int n)
{
  int i,m,k,l,z=n,j=0;
  m=0;
  do
  {
    j++;
    z>>=1;
  }
  while(z);
  for(i=j;i>=0;i--)
  {
    l=binpew(i);
    if((n-l)>=0)
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
      m+=binpew(k-i);
    }
  }
  return m;
}