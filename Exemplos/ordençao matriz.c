#include<stdio.h>

int main()
{
	int i,j,l,c,aux,anterior,m[2][2]={4,3,2,1};
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			for(l=0;l<2;l++)
			{
				for(c=0;c<2;c++)
				{
					if(m[i][j]<m[l][c])
					{
						anterior=m[i][j];
						m[i][j]=m[l][c];
						m[l][c]=anterior;
					}
				}
			}
		}
	}
	for(i=0;i<2;i++)
	{   printf("\n");
		for(j=0;j<2;j++)
		{
			printf(" %d",m[i][j]);
			
			
		}
	}
	
	
	
}
