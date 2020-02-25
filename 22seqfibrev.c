#include <stdio.h>
#define WLEN 100
int fileseqfibrev(char * l);

int main(void)
{
	char name[WLEN];
	scanf("%s", name);
	printf("%d\n",fileseqfibrev(name));
	return 0;

}

int fileseqfibrev(char * l)
{
	long int next,pre,x,cur;
	int flag=4;
	FILE * f;
	f=fopen(l,"r");

	if(!f) return -1;

 	if(feof(f)!=0)
 	{
 		fclose(f);
 		return -2;
 	}

 	if(fscanf(f,"%ld",&x)) pre=x;
 	
 	if(fscanf(f,"%ld",&x)) cur=x;

 	while(fscanf(f,"%ld", &x)==1)
 	{
 		next=x;
 		if(pre!=(next+cur)) return 0;
 		pre=cur;
 		cur=next;
 	}

 	if((pre!=1) || (cur!=1))
 	{
 		return 0;
 	}
 	
 	if(fclose(f) != 0) 
 		{
 			printf("ошибка при закрытии файла \n");
 			return 0;
 		}

 	return 1;
}