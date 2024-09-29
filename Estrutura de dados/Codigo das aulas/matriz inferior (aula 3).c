#include<stdio.h>
typedef struct 
{
	int n,*elementos;
}matriz;

void criar(int n, matriz *m)
{
	int aux;
	m->n=n;
	aux=(float)(n+1)*(n/2.0);
	m->elementos= (int*)calloc(aux,sizeof(int));
	if(!m->elementos)
	{
		printf("NAO FOI POSSIVEL ALOCAR MEMORIA!(14)");
	}
}
void iniciar(int n,matriz *m)
{
	int i,j,aux=0;
   
   for(i=0;i<n;i++)
   {
   		for(j=0;j<n;j++)
		{
		  if(i>=j)
		  {
		  	m->elementos[aux]=aux+1;	
		  	aux++;
		  }
		    	
		}
   }
	
}
void mostrar (int n,matriz *m)
{
	int i,j,aux1=0;
	
	for(i=0;i<n;i++)
	{
		printf("\n|");
		for(j=0;j<n;j++)
		{
			if(i>=j)
			{
				printf(" %02d ",m->elementos[aux1]);
				aux1++;
			}
			else
			{
				printf(" %02d ",0);
			}
		}
		printf("|");
	}
}
void consulta(int nl,int nc,matriz *m)
{
  int aux,i,j;
   
   if(nl>=nc)
   {
   	    aux=(float)(nc+nl*(nl-1)/2.0);
	 	printf("O VALOR DESEJADO EH %d",m->elementos[aux-1]);	
   }
   else
   {
   	 printf("O VALOR DESEJADO EH %d",0);
   }
  
  
}
int main()
{
	matriz m;
	int n=3,nc,nl;
	criar(n,&m);
	iniciar(n,&m);
	mostrar(n,&m);
	printf("\n QUAL LINHA DESEJA CONSULTAR? ");
    scanf("%d",&nl);
    printf("\n QUAL COLUNA DESEJA CONSULTAR? ");
    scanf("%d",&nc);
	consulta(nl+1,nc+1,&m);
}
