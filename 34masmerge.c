#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_PRINT 40

int merge(double *a, int n, double *b, int m, double *c);
void print_array( double *a, int n);
int read_array( const char *name, double *a, int n);

int main(int argc, char *argv[])
{
	double *a, *b, *c;
	int n, m, l;
	float t;
	char *name1, *name2;
	int result, result2;

	if(argc!=5 || !(n= atoi(argv[1])) || !(m= atoi(argv[3])))
	{
		printf("Usage: %s n name1 m name2 \n", argv[0]);
		return 1;
	}

	a=(double*)malloc(n*sizeof(double));
	b=(double*)malloc(m*sizeof(double));
	c=(double*)malloc((m+n)*sizeof(double));

	if(!a || !b || !c)
	{
		printf("Not enough memory!\n");
		return 2;
	}

	name1 = argv[2];
	name2 = argv[4];
	result=read_array(name1, a, n);
	result2=read_array(name2, b, m);
	if(result<0 || result2<0)
	{
		switch(result)
		{
			case -1:
			printf("Cannot open file1!\n");
			break;

			case -2:
			printf("Read ERROR!\n");
			break;

			default:
			break;
		}
		switch(result2)
		{
			case -1:
			printf("Cannot open file2!\n");
			break;

			case -2:
			printf("Read ERROR!\n");
			break;

			default:
			break;
		}

		free(a);
		free(b);
		return 3;
	}

	print_array(a,n);
	printf("\n\n");
	print_array(b,m);
	t=clock();

	l=merge(a,n,b,m,c);
	
	t=clock()-t;
	printf("Result:\n");
	print_array(c,l);
	free(a);
	free(b);
	free(c);
	printf("Fclosed=%.2f\n", t/CLOCKS_PER_SEC);
	return 0;
}


void print_array( double *a, int n)
{
	int m=(n>MAX_PRINT? MAX_PRINT:n);
	int i;
	for(i=0; i<m; i++)
	{
		printf("mas[%d]=%lf\n", i, a[i]);
	}
}


int read_array( const char *name, double *a, int n)
{
	FILE * f;
	int i;
	if(!(f=fopen(name,"r")))
		return -1;

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

int merge(double *a, int n, double *b, int m, double *c)
{
	int i,j=0,s=0;

	for(i=0;i<n+m;i++)
	{
		if(s+j==n+m)
			break;
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
		
		if(a[j]>b[s])
		{
			c[i]=b[s];
			
				s++;
			continue;
		}

		if(a[j]<b[s])
		{
			c[i]=a[j];

			j++;
			continue;
		}

		if(a[j]>=b[s] && a[j]<=b[s])
		{
			c[i]=b[s];
			s++;
			j++;
			continue;
		}

	}
	return i;

}