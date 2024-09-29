#include <stdio.h>
#define m 4
#define n 3
int main()
{
	int matriz[m][n]={{1,2,3},
					  {4,5,6},
					  {7,8,9},
					  {0,1,2}	
					 },
		l,c,somal[m],somac[n];
	
	
	   for (l=0;l<m;l++)
	   { somac[l]=0;
	     somal[l]=0;
		for(c=0;c<n;c++)
	   	{
	   	  	somal[l]+=matriz[l][c];	
	   	  	somac[l]+=matriz[c][l];
		}
	   }
	
  	/*for(c=0;c<n;c++)
  	{
  	  somac[c]=0;
  		for(l=0;l<m;l++)
  		{
  			somac[c]+=matriz[l][c];
		}
  	}*/
	
	
	for(l=0;l<m;l++)
	{
		printf("\n SOMA DA LINHA %d = %d",l,somal[l]);
	}
	 printf("\n==========================================================================================================");	
	for(c=0;c<n;c++)
	{
		printf("\n SOMA DA COLUNA %d = %d",c,somac[c]);
	}
	
	
}
