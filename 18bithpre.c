#include <stdio.h>
#define WLEN 100
unsigned int fileseqbtp(char * l);

int main(int argc, char * argv[])
{
	char * name;
	if(argc!=2)
	{
	  printf("Usage: %s filename\n", argv[0]);
	  return 1;
	}
	name = argv[1];
	
	//scanf("%s", name);
	printf("%d\n",fileseqbtp(name));
	return 0;

}

unsigned int fileseqbtp(char * l)
{
	double next,pre,x;
	unsigned int count=0;
	FILE * f;
	f=fopen(l,"r");

	if(!f) return -1;

 	if(feof(f)!=0)
 	{
 		fclose(f);
 		return -2;
 	}

 	if(fscanf(f,"%lf",&x)==1)
	  pre=x;
 	while(fscanf(f,"%lf",&x)==1)
 	{
 		next=x;
 		if(next>pre) count++;
 		pre=next;
 	}
 	
	if(!feof(f))
 	{
 		fclose(f);
 		return -2;
 	}
 	
 	if(fclose(f) != 0) 
 		{
 			printf("ошибка при закрытии файла \n");
 			return 0;
 		}

 	return count;
}