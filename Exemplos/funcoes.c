#include<stdio.h>
int fat(int a)
{
    int i,j=1;
	if(a==0)
    {return (1);}
	else{
		for(i=a;i>=1;i--)
		{
			j=j*i;
		}
         return(j);
	 	}

	
}


int main()
{
	int i;
	
scanf("%d",&i);
printf("%d",fat(i));
   	
}//
