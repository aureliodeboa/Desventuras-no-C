#include<stdio.h>
int main()
{
	int i,j,ve[10]={9,8,7,6,5,4,3,2,1,0},aux;
	
	for(i=0;i<10;i++)
	{
	//	scanf("%d",&ve[i]);
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{    
		
			if(ve[i]<ve[j])
			{
				aux=ve[i];
			    ve[i]=ve[j];
			    ve[j]=aux;
			    
			} 
		}
	}
	for(i=0;i<10;i++)
	{
		printf(" %d",ve[i]);
	}
}
