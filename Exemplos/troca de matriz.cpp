#include<stdio.h>
int main()
{
	int i,j,l,c1,c2,aux,matriz[4][4]={{2,1,0,3},{5,3,9,1},{1,2,1,2},{3,7,0,2}};
	
	for(i=0;i<4;i++)
	{   printf("\n ");
		for(j=0;j<4;j++)
		{
			 printf(" %d",matriz[i][j]);
		}
	}
	 printf("\n");
	scanf("%d",&c1);
	scanf("%d",&c2);
	
	
		for(i=0;i<4;i++)
		{
		  
		  	aux=matriz[i][c1];
		  	matriz[i][c1]=matriz[i][c2];
		  	matriz[i][c2]=aux;
		  
		}
		
		for(i=0;i<4;i++)
	{   printf("\n ");
		for(j=0;j<4;j++)
		{
			 printf(" %d",matriz[i][j]);
		}
	}
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{  	
			if(i==j)
			{
				if(i==0)
				{
					aux=matriz[i][j];
					matriz[i][j]=matriz[i][j+3];
					matriz[i][j+3]=aux;
				}
				if(i==1)
				{
					aux=matriz[i][j];
					matriz[i][j]=matriz[i][j+1];
					matriz[i][j+1]=aux;
				}
				if(i==2)
				{
					aux=matriz[i][j];
					matriz[i][j]=matriz[i][j-1];
					matriz[i][j-1]=aux;
				}
				if(i==3)
				{
					aux=matriz[i][j];
					matriz[i][j]=matriz[i][j-3];
					matriz[i][j-3]=aux;
				}
			   
			}
			
		}
	}
	 printf("\n DIAGONAL PRINCIPAL COM SECUNDARIA");
			for(i=0;i<4;i++)
	{   printf("\n ");
		for(j=0;j<4;j++)
		{
			 printf(" %d",matriz[i][j]);
		}
	}
		
	
}

