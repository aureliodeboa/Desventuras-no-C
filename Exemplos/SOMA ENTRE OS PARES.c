#include<stdio.h>
int main()
{
	int i,j,m,n,valor;
	
	scanf("%d",&m);scanf("%d",&n);
	while(m<n)
	{   
	     valor=0;
		for(i=m;i<=n;i++)
		{
		  valor+=i;
		}
		printf("\n  VALOR DA SOMA DOS NUMEROS ENTE %d e %d = %d ",m,n,valor);
		scanf("%d",&m);scanf("%d",&n);
	}
	printf("\n \t PROGRAMA FINALIZADO");
	
}
