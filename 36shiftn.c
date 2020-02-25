#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_PRINT 40

int NOD( int n,  int m);
void rightshiftn(double *a, int n,  int k);
void print_array( double *a, int n);
int read_array( const char *name, double *a, int n);

int main(int argc, char *argv[])
{
	double *a;
	int n,k;
	float t;
	char *name;
	int result;

	if(argc!=4 || !(n= atoi(argv[1])) || !(k= atoi(argv[3])))
	{
		printf("Usage: %s n name k\n", argv[0]);
		return 1;
	}

	a=(double*)malloc(n*sizeof(double));

	if(!a)
	{
		printf("Not enough memory!\n");
		return 2;
	}

	name = argv[2];
	result=read_array(name, a, n);

	if(result<0)
	{
		switch(result)
		{
			case -1:
			printf("Cannot open file!\n");
			break;

			case -2:
			printf("Read ERROR!\n");
			break;
		}

		free(a);
		return 3;
	}

	print_array(a,n);
	t=clock();
	if(k<n)
		rightshiftn(a, n, k);
	if(k>n && k%n!=0)
		rightshiftn(a, n, k%n);

		
	
	t=clock()-t;
	printf("Result:\n\n");
	print_array(a,n);
	free(a);
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

int NOD(int n, int m)
{
	int i=(n>m? m:n);
	for(i=(n>m? m:n);i>0; i--)
	{
		if(n%i==0 && m%i==0)
			break;
	}
	return i;
}

void rightshiftn(double *a, int n, int k)
{
	int nod=NOD(n,k), i;
	int j, d=0;
	double buf;
	for(i=0; i<nod; i++)
	{
		buf=a[i];
		j=i;
		while(1)
		{
			d=j-k;
			if(d<0)
				d+=n;
			if(d==i)
				break;
			a[j]=a[d];
			j=d;
		}
		a[j]=buf;

	}

}