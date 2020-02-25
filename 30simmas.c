#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_PRINT 40

int simmas(double *a, int n);
void print_array( double *a, int n);
int read_array( const char *name, double *a, int n);

int main(int argc, char *argv[])
{
	double *a;
	int n;
	float t;
	char *name;
	int result;

	if(argc!=3 || !(n= atoi(argv[1])))
	{
		printf("Usage: %s n name \n", argv[0]);
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

			default:
			break;
		}

		free(a);
		return 3;
	}

	print_array(a,n);
	t=clock();

	printf("%d\n", simmas(a, n));
	t=clock()-t;
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

int simmas(double *a, int n)
{
	int i;
	for(i=0;i<n/2;i++)
	{
		if(a[i]<a[n-1-i] || a[i]>a[n-1-i])
			return 0;
	}
	return 1;
}
