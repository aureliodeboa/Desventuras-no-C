#include<stdio.h>
typedef struct 
{
	int nl,nc;
	int *elementos;
}matriz;

void criar_matriz(int nl,int nc,matriz *m1)
{
	int num_ELE,i,j,aux=0;
	num_ELE=nl;
	
	m1->elementos= (int*)malloc(num_ELE*sizeof(int));
	if(!m1->elementos)
	{
		printf("NAO FOI POSSIVEL ALOCAR MEMORIA PARA MATRIZ (23)");
		exit(1);
	}

}

iniciar_matriz(int nl,int nc,matriz *m1)
{
	int i,j,aux=0;
		
	
	
		for(j=0;j<nc;j++)
		{   
			{
	 		scanf("%d",&(m1->elementos[aux]));
	 		aux++;
	 		}
	    }
  
}
imprimir(int nl,int nc, matriz *m1)
{
   int aux=0,i,j;
	
	for(i=0;i<nl;i++)
	{ 
		printf("|");
			for(j=0;j<nc;j++)
			{
			   if(i==j)
			   {
			   	printf(" %d ",m1->elementos[aux]);
			   	aux++;
			   }
			   else
			   {
			   	printf(" %d ",0);
			   }
			}
	   printf("|");		
	}
	
}    

consulta_matriz(int nl,int nc, matriz *m1)
{
	int i,j,aux,i1,j2;
	
	printf("Qual linha? \n");
	scanf("%d",&i);
	printf("Qual coluna ? \n");
	scanf("%d",&j);
	
	if(i==j)
	{
		printf("\n %d",m1->elementos[i] );
	}
	else
	{
		printf("%d",0);
	}
	
			
}
int main()
{
	int nl,nc;
	matriz m;
	printf("tamanho da matriz ?");
	scanf("%d",&nc);
	nl=nc;
	m.nc=nc;
	m.nl=nl;
	criar_matriz( nl, nc,&m);
	 iniciar_matriz( nl, nc,&m);
	 imprimir( nl, nc,&m);
	 printf("\n _____________________________________________________\n ");
	 consulta_matriz( nl, nc,&m);

	
}
