#include <stdio.h>
#define WLEN 100
unsigned int fileseqlocm(char * l);

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
	printf("%d\n",fileseqlocm(name));
	return 0;

}

unsigned int fileseqlocm(char * l)
{
	double next,pre,x,cur;
	unsigned int count=0;
	FILE * f;
	f=fopen(l,"r");

	if(!f) 
	  return -1;

 	if(fscanf(f,"%lf",&x)==1) 
	  pre=x;

 	if(fscanf(f,"%lf",&x)==1) 
	  cur=x;
 	else
	  return 0;

 	//if(cur>pre) count++;

 	while(fscanf(f,"%lf",&x)==1)
 	{
 		next=x;
 		if((cur>=pre && cur>=next)) 
		  count++;
 		pre=cur;
 		cur=next;
 	}
 	
 	//if(cur>pre) count++;
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