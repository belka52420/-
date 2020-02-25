#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_PRINT 30

void second_heap_sort(double *a, int n);
void heap_sort(double *a, int n);
void heap_lininsort(double *a, int n);
int read_array(const char *name,double *a, int n);
void print_array(double *a, int n);



int main(int argc, char * argv[])
{
	int n, result;
	double *a;
	char *name;
	double t;
	
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
	result=read_array(name, a, n);

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

	heap_sort(a,n);

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
	int m=(n>MAX_PRINT? MAX_PRINT:n);
	for(i=0;i<m;i++)
	{
		
		printf("mas[%d] = %lf\n", i, a[i]);
	}
}

void heap_lininsort(double *a, int n)
{
	int i,j,k, t=-1;
	double c;
	
	for(i=1;i<n;i++)
	{
		for(j=(i-1)/2;j>=0;j=(j-1)/2)
		{
			//printf("%d",j);
			if(a[i]>a[j])
			{
				t=j;
			}
			else
			{
				
				break;
			}
			
			if(j==0) break;
		}
		if(t!=-1)
			{
				c=a[i];
				for(k=i;k>t;k=(k-1)/2)
				{
					a[k]=a[(k-1)/2];
				}
				a[t]=c;		
			}
		t=-1;
	}
}

void second_heap_sort(double *a, int n)
{
	int k=0,t;
	double z=a[0];
	
	while((2*k+1)<n)
	{
	  if((2*k+2)<n)
	  {
		if(a[2*k+1]>a[2*k+2])
		{
		  k=2*k+1;
		}
		else
		{
		  k=2*k+2;
		}
	  }
	  else
	  {
	    t=2*k+1;
	    k=2*k+1;
	  }
	  
	  if(z>a[k])
	  {
	    t=(k-1)/2;
	    break;
	  }
	  else
	  {
	    a[(k-1)/2]=a[k];
	    t=k;
	  }
	 
	}
	a[t]=z;
return;
}

void heap_sort(double *a, int n)
{
	int i;
	double c;
	heap_lininsort(a,n);
	for(i=n-1;i>1;i--)
	{
		c=a[i];
		a[i]=a[0];
		a[0]=c;
		
		
		second_heap_sort(a,i);
	}
	c=a[i];
	a[i]=a[0];
	a[0]=c;
}