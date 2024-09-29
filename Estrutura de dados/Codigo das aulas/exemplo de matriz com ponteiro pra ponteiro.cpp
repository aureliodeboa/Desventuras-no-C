#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int nl,nc,**elementos;
}matriz;
void criar_matriz(int nl ,int nc, matriz *m )
{
	int i,j;
	m->elementos=(int**)malloc(nl*sizeof(int*));
	if(!m->elementos)
	{
		printf("ERRO AO ALOCAR");
		exit(1);
	}
	
		
		for(i=0;i<nl;i++)
		{
			m->elementos[i]=(int*)malloc(nc*sizeof(int));
			if(!m->elementos[i])
			{
			 	printf("ERRO AO ALOCAR MEMORIA");
			 	exit(2);
			}
		}
		
   m->nc=nc;
   m->nl=nl;
   		for(i=0;i<nl;i++)
   		{
   			for	(j=0;j<nc;j++)
   			{
   				m->elementos[i][j]=0;	
			}
   			
   		}	
	
}
void inicializar(matriz *m)
{
	int i,j;
	for(i=0;i<m->nl;i++)
   		{
   			for	(j=0;j<m->nc;j++)
   			{
   				printf("DIGITE MATRIZ[%d][%d]",i+1,j+1);
				scanf("%d",&(m->elementos[i][j]));	
			}
   			
   			
   		}
}
void imprimir(matriz *m)
{
	int i, j; 
	for(i=0;i<m->nl;i++)
	{	
		printf("\n|");
		for(j=0;j<m->nc;j++)
		{
			printf(" %d ",m->elementos[i][j]);
		}
		printf("|");
	}
}
void somar (matriz *m1, matriz *m2, matriz *m3)
{
	if (m1->nl==m2->nl && m1->nc==m2->nc)	
	 {
		int i, j;
		criar_matriz (m1->nl, m1->nc, m3); 
			for (i=0; i<m3->nl; i++)
			 for (j=0; j<m3->nc; j++)
			m3->elementos[i][j] = m1->elementos[i][j] + m2->elementos[i][j]; 
	}
	else 
	{
		printf ("A soma nao eh possivel!\n"); 
	} 
}
void subtrair(matriz *m1, matriz *m2, matriz *m3)
{
	if(m1->nl==m2->nl&&m1->nc==m2->nc)
	{
		int i,j;
		criar_matriz (m1->nl, m1->nc, m3); 
			for (i=0; i<m3->nl; i++)
			 for (j=0; j<m3->nc; j++)
			m3->elementos[i][j] = m1->elementos[i][j] - m2->elementos[i][j]; 
	}
	else
	{
		printf("NAO FOI POSSIVEL SOMAR AS MATRIZES");
	}
}
void multiplicar_matrizes (matriz *m1, matriz *m2, matriz *m3) 
{   
	if (m1->nc==m2->nl)
	 { int i, j, z;
	 
		criar_matriz (m1->nl, m2->nc, m3); 
	
		for (i=0; i<m1->nl; i++)
		{
        	for (j=0; j<m2->nc; j++) 
			{	 
			
	        	for (z=0; z<m2->nl; z++)
	             {
				  m3->elementos[i][j]+= m1->elementos[i][z] * m2->elementos[z][j]; 
                 }
                 
			} 
       }
   	}
    else 
	 { 
	       printf ("A multiplicacao nao eh possivel!\n");
     }
           
           
}
int main()
{
	matriz a,b,m3;
	criar_matriz( 2 ,2, &a );
	criar_matriz( 2 ,2, &b );
	inicializar(&a);
	inicializar (&b);
	multiplicar_matrizes(&a,&b,&m3);
	imprimir(&m3);
}
