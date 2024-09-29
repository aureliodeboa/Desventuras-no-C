#include<stdio.h>
int main()
{
	int l,c,maior,indl,indc,matriz[3][4]={{-2,1,0,3},{5,3,9,-1},{-1,2,1,-2}};
	for(l=0;l<3;l++)
	{
		for(c=0;c<4;c++)
		{
			if(l==0&&c==0)
			{
				maior=matriz[l][c];
			}
			if(maior<matriz[l][c])
			{
				maior=matriz[l][c];
				indc=c;
				indl=l;
			}
		}
	}
	printf("MAIOR VALOR  e %d LINHA %d e COLUNA %d",maior,indc+1,indl+1);
		
}
