#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_PRINT 30

void merge(double *a, int n, double *b, int m, double *c);
int read_array(const char *name,double *a, int n);
void print_array(double *a, int n);


int main(int argc, char * argv[])
{
	int n, m, key, result;
	double *a, *b, *c, x,t;
	char *name1, *name2;
	
	if(argc!=5 || !(n=atoi(argv[1])) || !(m=atoi(argv[3])))
	{
		printf("Usage: %s name1 n name2 m", argv[0]);
		return 1;
	}

	c=(double*)malloc((m+n)*sizeof(double));
	b=(double*)malloc(m*sizeof(double));
	a=(double*)malloc(n*sizeof(double));

	if(!a)
	{
		printf("Not enough memory");
		return 2;
	}

	name1=argv[2];
	name2=argv[4];

	result=read_array(name1, a, n);

	if(result<0)
	{
		switch(result)
		{
			case -1:
			printf("Cannot open file");
			break;

			case -2:
			printf("read ERROR");
			break;

			default:
			break;
		}
		free(a);
		return 3;

	}

	result=read_array(name2, b, m);

	if(result<0)
	{
		switch(result)
		{
			case -1:
			printf("Cannot open file");
			break;

			case -2:
			printf("read ERROR");
			break;

			default:
			break;
		}
		free(a);
		return 3;

	}

	t=clock();

	merge(a, n, b, m, c);

	t=clock()-t;

	print_array(c,m+n);
	printf("Fclosed=%.2lf\n", t/CLOCKS_PER_SEC);

	free(a);
	free(b);
	free(c);

	return 0;
}

int read_array(const char *name,double *a, int n)
{
	FILE *f;
	int i;
	if(!(f=fopen(name,"r")))
	{
		return -1;
	}

	for(i=0;i<n;i++)
	{
		if(fscanf(f,"%lf",a+i)!=1)
		{
			fclose(f);
			return -2;
		}
	}

	fclose(f);
	return 0;
}

void print_array(double *a, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		int m=(n>MAX_PRINT? MAX_PRINT:n);
		printf("mas[%d] = %lf\n", i, a[i]);
	}
}

void merge(double *a, int n, double *b, int m, double *c)
{
	int i, j=0, s=0;

	for(i=0;i<n+m;i++)
	{
		if(s==m)
		{
			c[i]=a[j];
			j++;
			continue;
		}

		if(j==n)
		{
			c[i]=b[s];
			s++;
			continue;
		}

		if(a[j]<b[s])
		{
			c[i]=a[j];
			j++;
		}
		else
		{
			c[i]=b[s];
			s++;
		}
	}
}