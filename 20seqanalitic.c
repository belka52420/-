#include <stdio.h>
#define WLEN 100
int fileseqan(char * l);

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
	printf("%d\n",fileseqan(name));
	return 0;

}

int fileseqan(char * l)
{
	double next,pre,x,cur;
	int flag=4;
	FILE * f;
	f=fopen(l,"r");

	if(!f) return -1;


 	if(fscanf(f,"%lf",&x)==1) pre=x;

 	if(fscanf(f,"%lf",&x)==1) cur=x;
 

 	while(fscanf(f,"%lf",&x)==1)
 	{
 		next=x;
 		if(cur>pre && cur<next && flag!=2 && flag!=3 && flag!=0)
 		{
 			flag=1;
 		}

 		if(cur<pre && cur>next && flag!=1 && flag!=3 && flag!=0)
 		{
 			flag=2;
 		} 
 		if((cur>=pre && cur<=pre) && (cur>=next && cur<=next)&& flag!=1 && flag!=2 && flag!=0)
 		{
 			flag=3;
 		} 				
 		if((cur>pre && cur>next) || (cur<pre && cur<next) || ((cur>=pre && cur<=pre) && cur<next) || (cur<pre && (cur>=next && cur<=next)) || ((cur>=pre && cur<=pre) && cur>next) || (cur>pre && (cur>=next && cur<=next)))
 		{
 			flag=0;
 			break;
 		}
 		pre=cur;
 		cur=next;
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

 	return flag;
}