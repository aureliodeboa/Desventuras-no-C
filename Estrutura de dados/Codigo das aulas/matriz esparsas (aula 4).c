#include<stdio.h>
typedef struct
{
  int nl,nc,valor;
}elemento;
typedef struct 
{
	int n,l,c;
	elemento *v;
}matriz;
void criar(int n,int nl,int nc, matriz *m)
{
    m->c=nc;
 	m->l=nl;
 	m->n=n;
	
	m->v=(elemento*)malloc(n*sizeof(elemento));
	if(!m->v)
	{
		printf("NAO FOI POSSIVEL ALOCAR MEMORIA!(21)");
	}
 	}	
void iniciar(int n,matriz *m)
{
	int z1;
 
   	  for(z1=0;z1<n;z1++)
    {
     printf("\n numero da linha:");
   	 scanf("%d",&(m->v[z1].nl));
   	 printf("\n numero da coluna:");
   	 scanf("%d",&(m->v[z1].nc));
   	 printf("\n VALOR: ");
   	 scanf("%d",&(m->v[z1].valor));	
    	
	}
}

void mostrar (matriz *m)
{
	int i,j,aux1=0;
	
	for(i=0;i<m->l;i++)
	{
		printf("\n|");
		for(j=0;j<m->c;j++)
		{
		  if((m->v[aux1].nl==i)&&(m->v[aux1].nc==j))
		  {
		  	printf(" %d ",m->v[aux1].valor);
		  	aux1++;
		  }
		  else
		  {
		  	printf(" %d ",0);
		  }
		  
		}
		printf("|");
	}
}
void consulta(int nl,int nc,matriz *m)
{
   	int i,j;
	
	 
		  if((m->v[fm(nl,nc)].nl==nl)&&(m->v[fm(nl,nc)].nc==nc))
		  {
		  	 printf("\n O VALOR DESEJADO EH %d",m->v[fm(nl,nc)].valor);
		  }
		  else
		  {
		   printf("\n O VALOR DESEJADO EH %d",0);
		  }
}

int fm(int i,int j)
{
	return (i+(j+1)*j/2);
}
int main()
{
	matriz m;
	int n=3,nc=3,nl=3;
	criar(n,nl,nc,&m);
	iniciar(n,&m);
	mostrar(&m);
	printf("\n QUAL LINHA DESEJA CONSULTAR? ");
    scanf("%d",&nl);
    printf("\n QUAL COLUNA DESEJA CONSULTAR? ");
    scanf("%d",&nc);
	consulta(nl,nc,&m);
}
