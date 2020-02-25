#include <stdio.h>

double srkvot(char * l, double * d);

int main(int argc, char * argv[] )
{
	char * name;
	double d;
	if(argc!=2)
	{
	  printf("Usage: %s filename\n", argv[0]);
	  return 1;
	}
	name = argv[1];
	srkvot(name, &d);
	//scanf("%s", name);
	//printf("%lf\n",srkvot(name, d));
	return 0;

}
double srkvot(char * l, double * d)
{
	
	double count=0,sumsq=0,sum=0,x;
	FILE * f;
	f=fopen(l,"r");

	if(!f) 
	{ 
	  printf("cannot find file"); 
	  return -1;
	  
	}



	while(fscanf(f,"%lf",&x)==1)
	{
		count++;
		sumsq+=(x*x);
		sum+=x;
	}
	if(!feof(f))
 	{
 		fclose(f);
		printf("-2\n");
 		return -2;
 	}
 	if(count<=0 && count>=0) 
	{
	  printf("enter sequence\n");
	  return -1;
	}
	
	*d=(sumsq*count-sum*sum)/(count*count);
	
	//printf("%lf \n", (sumsq*count-sum*sum)/(count*count));
 	if(fclose(f) != 0) 
 		{
 			printf("ошибка при закрытии файла \n");
 			return 0;
 		}
	printf("%lf\n", *d);
 	return count;
}