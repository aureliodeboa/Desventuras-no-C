#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int nl,nc;
	int *elementos;
	
}MATRIX;
void criar (int nl, int nc,MATRIX *m)
{
    m->nc=nc;
    m->nl=nl;
	 
	  m->elementos=(int*)malloc(nl*sizeof(int));
	  if(!m)
	  {
	  	printf("ERRO");
	  	exit(1);
	  }
	  	
	
}
void iniciar(MATRIX *m)
{
	
	int i,j,aux=0;
	
	  		for(i=0;i<m->nl;i++)
			{
				for(j=0;j<m->nc;j++)
				{
					if(i==j)
					{
			 			//printf("MATRIZ[%d][%d]",i,j);
						//scanf("%d",&(m->elementos[aux]));
						m->elementos[aux]=aux+1;
						aux++;	
					}
					
						
					
				}		
			}
}
void imprimir(MATRIX *m)
{

	int i,j,aux=0;
	
	  		for(i=0;i<m->nl;i++)
			{ 	printf(" | ");
				for(j=0;j<m->nc;j++)
				{
					if(i!=j)
					{
			 			printf(" 0 ");
			 			
					}
					else
					{
					  printf(" %d ",m->elementos[aux]);
					  aux++;
					}
				}
				printf(" | \n");	
			}
			
			
}
void consultar(int nl, int nc, MATRIX *m)
{
	int i,j,aux=0;
	
	  		for(i=0;i<=nl;i++)
			{
				for(j=0;j<=nc;j++)
				{
					if(i!=j)
					{
						if((i==nl)&&(j==nc))
						{
							printf("O NUMERO EH 0");
						}
						
			 			
					}
					else
					{
						if((i==nl)&&(j==nc))
						{
							printf("MATRIZ[%d][%d]= %d",i+1,j+1,m->elementos[aux]);
						}
						aux++;	
					}
				}		
			}

}
int main()
{
	MATRIX m;
     int nc,nl;
     nc=10 ;nl=10;
	 m.nc=nc; m.nl=nl;
	criar(nl,nc,&m);
	iniciar(&m);
	printf("\n==========================================\n");
	imprimir(&m);
	consultar(2,2,&m);
}



