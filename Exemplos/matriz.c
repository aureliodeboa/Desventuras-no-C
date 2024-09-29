#include<stdio.h>
#include<stdlib.h>
#define l 4
#define c 3
int main()
{
	int i,j,m[l][c];
	
	for (i=0;i<l;i++){
		for(j=0;j<c;j++)
		{  	
		    printf("MATRIZ[%d][%d]",i,j);
		 m[i][j]=rand();
		}
	}
	
		for (i=0;i<l;i++){
			printf("\n");
		for(j=0;j<c;j++){
			
		
			printf(" %d",m[i][j]);
		
			
		}

}
}
