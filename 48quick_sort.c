#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_PRINT 30

void q_sort(double *a, int n);
int x_between(double *a, int n, double x);
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

	q_sort(a,n);

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

int x_between(double *a, int n, double x)
{
	int i,j;
	double c;
	for(i=0;i<n;i++)
		{
			if(a[i]>=x)
				break;
		}

		for(j=n-1;j>=0;j--)
		{
			if(a[j]<=x)
				break;
		}

	while(i<j)
	{
		//printf("\nds\n");
		c=a[i];
		a[i]=a[j];
		a[j]=c;
		i++;
		j--;

		for(i=i;i<n;i++)
		{
			if(a[i]>=x)
				break;
		}

		for(j=j;j>=0;j--)
		{
			if(a[j]<=x)
				break;
		}
	}
	return i;
}

void q_sort(double *a, int n)
{
	double x;
	int fr, len1, len2;

	while(n>1)
	{
		x=a[n/2];
		fr=x_between(a, n, x);
		len1=fr;
		len2=n-fr;
		if(len1<len2)
		{
			q_sort(a,len1);
			n=len2;
			a=a+len1;
			
		}
		else
		{
			q_sort(a+len1, len2);
			n=len1;
		}
 	}
}

		


			







	



	//x=a[n/2];
	//fr=x_between(a, n, x);
	//len1=fr;
	//len2=n-fr;
	//printf("%d\n", n);
		//if(fr==n) fr=n-1; // я хз как корректно исправить этот косяк, похож на костыль, тк программа between
		// при сравнении 2х упорядоченных элементов выдает 2 а не 1 и это плехо, как такое решить более корректно?????????