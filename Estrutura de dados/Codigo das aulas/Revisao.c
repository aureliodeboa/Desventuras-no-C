#include<stdio.h>
#define nl 7
#define nc 4

int main()
{
	int i,j;
	float matriz[nl][nc];
	
	for(i=0;i<nl;i++)
	{
		for(j=0;j<nc;j++)
		{
			printf("MATRIZ[%d][%d]= ",i+1,j+1);
			scanf("%f",&matriz[i][j]);
			
		}
	}
	system("cls");
	
	
	for(i=0;i<nl;i++)
	{   printf("\n|");
		for(j=0;j<nc;j++)
		{
			printf("%10.2f",matriz[i][j]);
			
		}
		printf("|");
	}
    
    
    
}
