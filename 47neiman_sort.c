#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_PRINT 30


void merge(double *a, int n, double *b, int m, double *c);
int read_array(const char *name,double *a, int n);
void print_array(double *a, int n);
void neiman_sort(double *a, double *b, int n);


int main(int argc, char * argv[])
{
	int n, m, key, result;
	double *a, *b, *c, x,t;
	char *name1;
	
	if(argc!=3 || !(n=atoi(argv[1])))
	{
		printf("Usage: %s name1 n ", argv[0]);
		return 1;
	}

	b=(double*)malloc(n*sizeof(double));
	a=(double*)malloc(n*sizeof(double));

	if(!a)
	{
		printf("Not enough memory");
		return 2;
	}

	name1=argv[2];


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

	t=clock();

	neiman_sort(a, b, n);

	t=clock()-t;

	print_array(a,n);
	printf("Fclosed=%.2lf\n", t/CLOCKS_PER_SEC);

	free(a);
	free(b);

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

void neiman_sort(double *a, double *b, int n)
{
	double *c, *a_orig;
	a_orig=a;
	int key2=n, i, j,z;
	for(i=1;i<=n;i*=2) 
	{
		if(key2%2==0)
		{
			for(j=0;j<key2/2;j++)
			{
				

				if((2*j*i+2*i)>=n-1)
				{
					merge(a+2*j*i, i, a+2*j*i+i, n-2*j*i-i, b+2*j*i);
					break;
				}

				merge(a+2*j*i, i, a+2*j*i+i, i,b+2*j*i);
			}
			key2=key2/2;
		}
		else
		{

			for(j=0;j<=(key2/2+1);j++)
			{

				if(j==key2/2)
				{
					for(z=2*j*i;z<n;z++)
					{
						b[z]=a[z];
					}
					break;
				}

				merge(a+2*j*i, i, a+2*j*i+i, i,b+2*j*i);


			}

			key2=key2/2+1;
		}
		c=a;
		a=b;
		b=c;


	}
	
	if(b==a_orig)
	{
		for(i=0;i<n;i++)
		{
			b[i]=a[i];
		}
	}

}

