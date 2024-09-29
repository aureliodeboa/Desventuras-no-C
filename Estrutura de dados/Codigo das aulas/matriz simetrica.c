#include<stdio.h>
typedef struct 
{
	int n;
	char *elementos;
}matriz;

void criar(int ord, matriz *m)
{
	int aux;
	m->n=ord;
	aux=(int)((ord+1)*(ord/2.0));
	m->elementos= (char*)malloc(aux*sizeof(char));
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
		  if(i<=j)
		  {	
		  	printf("\n DIGITE O CARACTER[%d][%d] ",i,j);
		  	setbuf (stdin, NULL); 
		  	scanf("%c",&(m->elementos[aux]));
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
		printf("|");
		for(j=0;j<n;j++)
		{
			if(i<=j)
			{
				printf(" %c ",m->elementos[fm(i,j)]);
			}
			else
			{
				printf(" %c ",m->elementos[fm(j,i)]);
			}
		}
		printf("|\n");
	}
}

void consulta(int nl,int nc,matriz *m)
{
  
  if(nl<=nc)
  {
  	printf("O CARACTER DESEJADO EH %c ",m->elementos[fm(nl,nc)]);
  }
  else
  {
  	printf("O CARACTER DESEJADO EH %c ",m->elementos[fm(nc,nl)]);
  }
}

int fm(int i,int j)
{
   return (i + (j+1)*j/2);

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
	consulta(nl,nc   ,&m);
}
