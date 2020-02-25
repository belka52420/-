#include <stdio.h>

int seqa(char * l);

int main(int argc, char * argv[])
{
	char * name;
	
	
	if(argc!=2)
	{
	  printf("Usage: %s filename\n", argv[0]);
	  return 1;
	}
	name = argv[1];

	//srkvot(name, &d);
	//scanf("%s", name);
	printf("%d\n",seqa(name));
	return 0;

}
int seqa(char * l)
{
	
	double y,x,d,b;
	int count=0,countAr=0,countGeo=0,countRav=0;
	int flag=5;
	FILE * f;
	f=fopen(l,"r");

	if(!f) return -1;
	
 	if(feof(f)!=0)
 	{
 		fclose(f);
 		return -2;
 	}
	if(fscanf(f,"%lf",&x)==1)
	  count++;
	if(fscanf(f,"%lf",&y)==1)
	  count++;
	if(x<0 || x>0)
	d=y/x;
	b=y-x;
	if(x<=y && x>=y)
	{
	  flag=3;
	  countRav++;
	}
	x=y;
	
	while(fscanf(f,"%lf",&y)==1)
	{
	  count++;
	  if((flag!=2) && (flag!=3) && (flag!=0) && ((y-x)<=b) && ((y-x)>=b))
	  {
	    flag=1;
	    countAr++;
	    x=y;
	  }
	  if(x<0 || x>0){
	  if(flag!=1 && flag!=3 && flag!=0 && (y/x)<=d && (y/x)>=d)
	  {
	    flag=2;
	    countGeo++;
	    x=y;
	  }
	  }
	  if(flag==3 && y<=x && x<=y)
	  {
	    flag=3;
	    countRav++;
	    x=y;
	  }
	  
	}
 	if(fclose(f) != 0) 
	{
		printf("ошибка при закрытии файла \n");
 		return 0;
 	}
	if(flag==0) return 0;
	if(count<=2)
	{
	  if(countRav==0)
	    return 4;
	  else return 3;
	}
	if((count-countAr)!=2 && (count-countRav)!=1 && (count-countGeo)!=2)
	{
	  return 0;
	}
	
	//printf("%lf \n", (sumsq*count-sum*sum)/(count*count));

 	return flag;
}