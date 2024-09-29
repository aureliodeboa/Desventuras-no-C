#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int nc;
	int nl;
	int *elementos;
}matriz;

void criar_matriz(int nl,int nc,matriz *m1)
{
	int num_ELE,i,j,aux=0;
	m1->nc=nc;
	m1->nl=nl;
	
	num_ELE=(nl*nc);
	
	m1->elementos= (int*)malloc(num_ELE*sizeof(int));
	if(!m1->elementos)
	{
		printf("NAO FOI POSSIVEL ALOCAR MEMORIA PARA MATRIZ (23)");
		exit(1);
	}
}
void inicar_matriz(int nl,int nc, matriz *m1)
{  
  int i,j,aux=0;
 
  	for(i=0;i<nl;i++)
	{
		for(j=0;j<nc;j++)
		{
			printf("MATRIZ[%d][%d]: ",i+1,j+1);
	 		scanf("%d",&(m1->elementos[aux]));
	 		aux++;
	    }
    }
 	
	
}
void mostrar_matriz(matriz *m1)
{
	int aux=0,i,j;
	
	for(i=0;i<m1->nl;i++)
	{ 
		printf("\n|");
			for(j=0;j<m1->nc;j++)
			{
				printf(" %02d ",m1->elementos[aux]);
				aux++;
			}
	   printf("|");		
	}
 printf("\n ");
	
}    
void somar_matriz(matriz *m1,matriz *m2,matriz *m3)
{
	int i,j,aux=0;
	 
	if((m1->nc==m2->nc)&&(m1->nl==m2->nl))
	{
		i=m1->nl;j=m2->nc;
		criar_matriz( i,j,m3);
        	for(i=0;i<m1->nl;i++)
        	{
        		for(j=0;j<m1->nc;j++)
        		{
        			m3->elementos[aux]=(m1->elementos[aux]+m2->elementos[aux]);
        			aux++;
        			
				}
			}
	 printf("\n SOMA DAS MATRIZES \n");
	 mostrar_matriz(m3);
	 
			
	}
	
	
	
}
void sub_matriz(matriz *m1,matriz *m2, matriz *m3)
{
  int i,j,aux=0;
	 
	if((m1->nc==m2->nc)&&(m1->nl==m2->nl))
	{
		i=m1->nl;j=m2->nc;
		criar_matriz( i,j,m3);
        	for(i=0;i<m1->nl;i++)
        	{
        		for(j=0;j<m1->nc;j++)
        		{
        			m3->elementos[aux]=(m1->elementos[aux]-m2->elementos[aux]);
        			aux++;
        			
				}
			}
	 printf("\n SUB M1-M2  MATRIZES \n ");
	 mostrar_matriz(m3);
}
}
void mult_matriz(matriz *m1,matriz *m2,matriz *m3)
{
	int i,j,i2,j2,aux1=0,aux2=0;
	
	if(m1->nc==m2->nl)
	{
		criar_matriz(m1->nl,m2->nc,m3);
		for(i=0;i<m3->nc;i++)
		{
			for(j=0;j<m3->nl;j++)
			{
				for(i2=0;i2<m1->nc;i2++)
				{
					for(j2=0;j2<m2->nl;j2++)
					{
						m3->elementos[aux1]=(m2->elementos[j2*])
					}
				}
			}
		}
	}
}
int main()
{
	int nc,nl;
	matriz m1,m2,m3;
	
	printf("LINHAS :  \n");
	scanf("%d",&nl);
	printf("COLUNAS : \n");
	scanf("%d",&nc);
	criar_matriz( nl,nc,&m1);
    inicar_matriz( nl,nc,&m1);
    
    printf("2 LINHAS :  \n");
    scanf("%d",&nl);
    printf("2 COLUNAS : \n");
    scanf("%d",&nc);
   	criar_matriz( nl,nc,&m2);
    inicar_matriz( nl,nc,&m2);
    somar_matriz(&m1, &m2 ,&m3);
    sub_matriz(&m1,&m2,&m3);

    
    
   

	
	
	
	
}
