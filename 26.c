#include <stdio.h>

int seqa(char * l, double y);

int main(int argc, char * argv[])
{
	char * name;
	double x;
	
	if(argc!=2)
	{
	  printf("Usage: %s filename\n", argv[0]);
	  return 1;
	}
	name = argv[1];
	scanf("%lf", &x);
	//srkvot(name, &d);
	//scanf("%s", name);
	printf("%d\n",seqa(name, x));
	return 0;

}
int seqa(char * l, double y)
{
	
	double x;
	int count=0;
	int flag=0;
	FILE * f;
	f=fopen(l,"r");

	if(!f) return -1;
	


	while(fscanf(f,"%lf",&x)==1)
	{
		count++;
		if(x<=y && x>=y)
		{
		  flag=1;
		  break;// оддебажить без брейка
		  
		}
	}
	
	if(!feof(f))
 	{
 		fclose(f);
		//printf("-2\n");
 		return -2;
 	}
 	if (count==0)
	{
	  fclose(f);
	  printf("empty\n");
	  return -2;
	}
	//printf("%lf \n", (sumsq*count-sum*sum)/(count*count));
 	if(fclose(f) != 0) 
 		{
 			printf("ошибка при закрытии файла \n");
 			return 0;
 		}
	if(flag==0) return 0;
 	return count;
}