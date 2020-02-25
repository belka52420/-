#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_PRINT 40

int countenter(const char *name, double *a, int n);
void print_array( double *a,  int n);
int read_array( const char *name, double *a,int n);

int main(int argc, char *argv[])
{
	double *a;
	int n;
	float t;
	char *name, *name2;
	int result;

	if(argc!=4 || !(n= atoi(argv[1])))
	{
		printf("Usage: %s n name1 name2\n", argv[0]);
		return 1;
	}

	a=(double*)malloc(n*sizeof(double));

	if(!a)
	{
		printf("Not enough memory!\n");
		return 2;
	}

	name = argv[2];
	name2 = argv[3];
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

	printf("%d\n",countenter(name2, a, n));
	
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

int countenter(const char *name, double *a, int n)
{
	FILE *f;
	int i=0, counter=0;
	double x;
	if(!(f=fopen(name,"r")))
		return -1;

	while(fscanf(f,"%lf", &x)==1)
	{
		if(i==n)
		{
			counter++;
			i=0;
		}

		if(a[i]<=x && a[i]>=x)
		{
			i++;
			continue;
		}

		if(a[i]<x || a[i]>x)
		{
			i=0;
		}
	
	}

	if(i==n)
	{
		counter++;
		i=0;
	}

	if(!feof(f))
	{
		fclose(f);
		return -2;
	}

	if(fclose(f) != 0) 
 		{
 			printf("Cannot close file \n");
 			return 0;
 		}

	return counter;
}