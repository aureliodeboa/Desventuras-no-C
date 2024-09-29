#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int nl,nc,numero;
}elemento;
typedef struct
{
	int numele,NL,NC;
	elemento *ELE;
}MATRIX;

void criar(int NL,int NC ,int numele,MATRIX *m)
{   m->NC=NC;
	m->NL=NL;
	m->numele=numele;
	m->ELE=(int*)malloc(numele*sizeof(int));
	if(!m->ELE)
	{
		printf("ERROO");
	}
}

void iniciar(MATRIX *m)
{
	int i;
	for(i=0;i<m->numele;i++)
	{
		printf("\n LINHA= ");
		scanf("%d",&(m->ELE[i].nl));
		printf("\n COLUNA= ");
		scanf("%d",&(m->ELE[i].nc));
		printf("\n MATRIX[%d][%d]= ",m->ELE[i].nl,m->ELE[i].nc);
		scanf("%d",&(m->ELE[i].numero));
	}
}
void imprimir (MATRIX *m)
{
	int i,j,aux=0;
	for(i=0;i<m->NL;i++)
	{
		printf("|");
		for(j=0;j<m->NC;j++)
		{
			if((m->ELE[aux].nl==i)&&(m->ELE[aux].nc==j))
			{
				printf("%d",m->ELE[aux].numero);
				aux++;
			}
			else
			{
				printf("0");
			}
		}
		printf("|\n");
	}
}
int consultar(int nl,int nc,MATRIX *m)
{
	int i,j;
	for(i=0;i<m->numele;i++)
	{   
	 
		if((m->ELE[i].nl==nl)&&(m->ELE[i].nc==nc))
			{
			  printf(" O VALOR DESEJADO  EH %d",m->ELE[i].numero);
 				return 1;			
			}
	
			
			
	}
	printf(" O VALOR EH 0");
	return 0;
	
	
	
	
}

int main()
{
	MATRIX m;
	criar(3,3,3,&m);
	iniciar(&m);
	imprimir(&m);
	consultar (0,0,&m);
}
