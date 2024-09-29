#include<stdio.h>
#define L 5
#define C 7
int main()
{
	int i,j,i1,j1,aux,linha,coluna,matriz[L][C];
	
	
	for(i=0;i<L;i++)
	{
		for(j=0;j<C;j++)
		{
		
			if(j==0)
			{
				linha=matriz[i][j];
			}		
				
			if(linha>matriz[i][j])
			{
				linha=matriz[i][j];
			}
			
		if(j==0)
			{
				coluna=matriz[j][i];
			}		
				
			if(coluna<matriz[j][i])
			{
				coluna=matriz[j][i];
			}
		}
		
		if(linha==coluna)
		
		printf("CELA %d",linha);
	}
	
	
	
	
	
   
	
	
	
	
}
