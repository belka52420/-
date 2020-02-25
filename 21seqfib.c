#include <stdio.h>
#define WLEN 100
int fileseqfib(char * l);

int main(void)
{
	char name[WLEN];
	scanf("%s", name);
	printf("%d\n",fileseqfib(name));
	return 0;

}

int fileseqfib(char * l)
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
 	if(pre!=1) return 0;

 	if(fscanf(f,"%ld",&x)) cur=x;
 	if(cur!=1) return 0;

 	while(fscanf(f,"%ld", &x)==1)
 	{
 		next=x;
 		if(next!=(pre+cur)) return 0;
 		pre=cur;
 		cur=next;
 	}
 
 	if(fclose(f) != 0) 
 		{
 			printf("ошибка при закрытии файла \n");
 			return 0;
 		}

 	return 1;
}