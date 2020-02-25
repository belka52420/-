#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_PRINT 30

void lininsort(double *a, int n);
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
		printf("Usage: %s n name", argv[0]);
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

	

	t=clock();

	lininsort(a, n);

	t=clock()-t;

	print_array(a,n);
	printf("Fclosed=%.2lf\n", t/CLOCKS_PER_SEC);

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
		printf("mas[%d] = %lf\n", i, a[i]);
	}
}

void lininsort(double *a, int n)
{
	int i,j,k;
	double c;
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]<a[j])
			{
				c=a[i];
				for(k=i;k>j;k--)
				{
					a[k]=a[k-1];
				}
				a[j]=c;
			}
		}
	}
}


