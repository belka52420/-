#include <stdio.h>
#define WLEN 100
unsigned int fileseq(const char * l);

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
	printf("%d\n",fileseq(name));
	return 0;

}


unsigned int fileseq(const char * l)
 {
 	unsigned int count=0;
 	double x, pre;
 	FILE * f;
 	f=fopen(l, "r");
 	if(!f) 
	  return -1;
 	/*if(!feof(f))
 	{
 		fclose(f);
 		return -2;
 	}*/
	//if(feof(f)!=0)

 	if(fscanf(f,"%lf",&x)!=EOF) 
	{
		pre=x;
		count++;
	}
 	else	
 	{
 		fclose(f);
 		return -2;
 	}
 	
 	while(fscanf(f,"%lf",&x)==1)
 	{
 		if(pre<x) 
		  count++;
 		pre=x;
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