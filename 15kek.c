#include<stdio.h>

unsigned int karetka(unsigned int n,unsigned int k,unsigned int m);

int main(void)
{
	unsigned int n,m,p;
	unsigned int k;
	scanf("%u %u %u",&n, &k, &m);
	p=karetka(n,k,m);
	printf("%u",p);
	return 0;	
}


unsigned int karetka(unsigned int n,unsigned int k,unsigned int m)
{
	int l,r,q;
	l=binpew(m+1)-binpew(m-k+1);
	r=n&l;
	q=r>>(m-k+1);
	return q;
}