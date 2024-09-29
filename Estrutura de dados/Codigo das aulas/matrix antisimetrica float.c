#include<stdio.h>
typedef struct
{
	int n;
	float *elementos;
}M;
void criar(int ord ,M *m )
{     
     int n=(int)((1+ord)*ord/2.0);
     m->n=ord;
	m->elementos=(float*)malloc(sizeof(float)*n);
	if(!m->elementos)
	{
		printf("ERRO");
		exit(1);
	}
	

}
void iniciar(M *m)
{
	int i,j,aux=0;
	for(i=0;i<m->n;i++)
	{
		for(j=0;j<m->n;j++)
		{
			if(i<=j)
			{
				printf("MATRIZ[%d][%d]= \n",i,j);
				//scanf("%f",&m->elementos[aux]);
				m->elementos[aux]=aux+1;
				aux++;
			}
			
		}
	}
}
void imprimir(M *m)	
{
	int i,j,aux=0;
	for(i=0;i<m->n;i++)
	{ 	printf("|");
		for(j=0;j<m->n;j++)
		{
			if(i<=j)
			{
			  printf(" %.1f ",m->elementos[fm(i,j)]);	
			}
			else
			{
			 printf("-%.1f ",m->elementos[fm(j,i)]);	
			}	
		}
		printf("|\n");	
	}	
}	

void consulta(int nl,int nc, M *m)
{
	if(nl<=nc)
	{
		printf("%f",m->elementos[fm(nl,nc)]);
	}
	else
	{
		printf("-%f",m->elementos[fm(nc,nl)]);
	}
}
int fm(int i,int j)
{
	return  (i+(j+1)*j/2.0);
}
int main()
{
	M m;
	criar(3,&m);
	iniciar(&m);
	imprimir(&m);
	consulta(2,1,&m);
}
