#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_PRINT 30

int bins(double *a, int n, double x);
int read_array(const char *name,double *a, int n);
void print_array(double *a, int n);


int main(int argc, char * argv[])
{
	int n, key, result;
	double *a;
	char *name;
	double x,t;
	
	if(argc!=3 || !(n=atoi(argv[1])))
	{
		printf("Usage: %s name n", argv[0]);
		return 1;
	}

	a=(double*)malloc(n*sizeof(double));

	if(!a)
	{
		printf("Not enough memory");
		return 2;
	}

	name=argv[2];
	result=read_array(argv[2], a, n);

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

	scanf("%lf", &x);

	t=clock();

	key = bins(a, n, x);

	t=clock()-t;

	printf("i = %d\nFclosed=%.2lf\n", key, t/CLOCKS_PER_SEC);

	free(a);

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
		printf("mas[%d] = %lf", i, a[i]);
	}
}

int bins(double *a, int n, double x)
{
	int minFr=0, maxFr=n, mid;

	while(minFr!=maxFr)
	{
		mid=(minFr+maxFr)/2;
		if(x<a[mid])
			maxFr=mid;
		else
			minFr=mid+1;
	}

	return maxFr-1;

}