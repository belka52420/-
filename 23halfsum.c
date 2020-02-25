#include <stdio.h>
#define WLEN 100
int fileseqhalfsum(char * seq1, char * seq2);

int main(void)
{
	char name1[WLEN],name2[WLEN];
	scanf("%s", name1);
	scanf("%s", name2);
	printf("%d\n",fileseqhalfsum(name1,name2));
	return 0;

}

int fileseqhalfsum(char * seq1, char * seq2)
{
	double next,pre,x,cur,y,pre2,cur2;
	FILE * f1;
	FILE * f2;
	f1=fopen(seq1,"r");
	f2=fopen(seq2,"r");

	if(!f1 || !f2) return -1;



 	fscanf(f2,"%lf",&y);
 	if(fscanf(f2,"%lf",&y)) pre2=y;
 	if(fscanf(f1,"%lf",&x)) pre=x;
 	if(fscanf(f1,"%lf",&x)) cur=x;
 	
 	if(feof(f1)!=0 || feof(f2)!=0)
 	{
 		fclose(f1);
 		fclose(f2);
 		return -2;
 	}

 	while(fscanf(f2, "%lf", &y)==1)
 	{
 		if(fscanf(f1, "%lf", &x)==1)
 		{
 			cur2=y;
 			next=x;
	 		if(pre2!=((next+pre)/2)) return 0;
	 		pre=cur;
	 		cur=next;
	 		pre2=cur2;
 		}
 		else
 		{
 			printf("warning! file1<file2\n");
 			fclose(f1);
 			fclose(f2);
 			return 0;
 		}
 		
 	}

 	
 	if(fclose(f1) != 0 || fclose(f2) != 0) 
 		{
 			printf("ошибка при закрытии файла \n");
 			return 0;
 		}

 	return 1;
}