///puzirek
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PRINT 20

int array_read(char*name,double*a,int N);
void prn(double*a,int N);
void f(double*a,int N,double (*cmp)(double a, double b));

double comp1(double a,double b);
double comp2(double a,double b);

double comp1(double a,double b)
{
	return a-b;
}
double comp2(double a,double b)
{
	return b-a;
}

void f(double*a,int N,double (*cmp)(double a, double b))
{
	int i;
	double t;
	while(N>0)
	{
		for(i=0;i<N-1;i++)
		{
			//if(a[i]>a[i+1])
			if((*cmp)(a[i],a[i+1])>0)	
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}			
		}
		/*printf("\n");
		prn(a,N);*/
		N--;
	}
	return;
}

void prn(double*a,int N)
{
	int i,m=(N>MAX_PRINT?MAX_PRINT:N);
	
	for(i=0;i<m;i++)
	{
		printf("a[%d]=%lf\n",i,a[i]);
	}
	
	return;
}


int array_read(char*name,double*a,int N)
{
	FILE *fp;
	int i=0;
	double ch;
	
	fp=fopen(name,"r");
	if(!fp)return -1;
	
	while(fscanf(fp,"%lf",&a[i])==1)
	{
		i++;
		if(i==N)//esli perbor,to vihod
		{
			break;
		}
	}
	
	if(!feof(fp))
	{
		fclose(fp);
		return -3;
	}
	
	fclose(fp);
	
	if(i==0)return -5;
	
	if(i<N)return -4;
	
	return i;
}

int main(int argc,char*argv[])// 2-N,3-txt!!!! lyuboiporyadok
{
	int N;
	double*a;
	char *name;
	double t;
	
	if((argc!=3)||!(N=atoi(argv[1])))
	{
		printf("Usage:%s\n",argv[0]);
		return 1;
	}
	
	name=argv[2];
	
	a=(double*)malloc(N*sizeof(double));
	if(!a)
	{
		printf("not enough memory\n");
		return 1;
	}
	
	N=array_read(name,a,N);
	
	if(N>=0)
	{
		prn(a,N);
	
		
		t=clock();
		f(a,N,comp2);
		t=clock()-t;
		
		printf("\n");
		prn(a,N);
		
		printf("FCLOSED=%.2f\n",t/CLOCKS_PER_SEC);
	}
	else
	{
		switch(N)
		{
			case -1:
			printf("cannot open %s\n",name);
			break;
			
			/*case -2:
			printf("a[i]>a[i+1] in %s\n",name);
			break;*/
			
			case -3:
			printf("cannot read %s\n",name);
			break;
			
			case -4:
			printf("in file %s > N elements\n",name);
			break;
			
			case -5:
			printf("Empty file %s\n",name);
			break;
			
			default:
			printf("Uknown error %d in %s\n",N,name);
		}
	}
	
	
	free(a);
	return 0;
}