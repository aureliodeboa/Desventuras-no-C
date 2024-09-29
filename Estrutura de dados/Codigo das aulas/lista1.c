#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct 
{
	int n;
	int val[MAX];
}LISTA;
void criar(LISTA *l)
{
	l->n=0;
}
int vazia(LISTA *l)
{
	if(l->n==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int tam(LISTA *l)
{
	return l->n;
}
int inserir(LISTA *l, int v, int k)
{ 	
	int i;
	if(l->n==MAX)
	{
		printf("EXTOURO NA LISTA \n");exit(1);
	}
	else
	{
		if(k<1||k>l->n+1)
		{
			printf("POSICAO INVALIDA \n");exit(2);
		}
		for(i=l->n;i>=k;i--)
		{
			l->val[i]=l->val[i-1];
		}
		l->val[k-1]=v;
		l->n++;
	}
}
int consultar(int k, LISTA *l)
{
	if(k>l->n||k<1)
	{
		printf("NAO PERTENCE A LISTA ERRO");
		exit(3);
	}
	else
	{
		return(l->val[k-1]);
	}
	
}
void retirar( int k, LISTA *l)
{
	int i;
	if(k<1||k>l->n)
	{
		printf("RETIRADA INVALIDA");
		exit(4);
	}
	else
	{  //l->n--;
		for(i=k-1;i<l->n;i++)
		{
			l->val[i]=l->val[i+1];
		}
		l->n--;
	}
}
void mostrar(LISTA *l)
{
	int i;
	for(i=0;i<tam(l);i++)
	{
		printf("\n %d \n",l->val[i]);
	}
}
int pertence(int v,LISTA *l)
{
	int i;
	for(i=0;i<l->n;i++)
	{
		if(l->val[i]==v)
		{
			return 1;
		}
	}
	return 0;
}
int ordenada(LISTA *l)
{
	int i,aux=0;
	for(i=0;i<tam(l)-1;i++)
	{
		if(l->val[i]<l->val[i+1])
		{
			aux++;
		}
	}
	if(aux==i)
	{
		return (1);
	}
	else
	{
		return(0);
	}
}
void gera(LISTA *l,int m,int n)
{
	if(m>n)
	{
		printf("INTERVALO INVALIDO");
	}
	else
	{
		if(m==n) //CRITERIO DE PARADA
		{
			criar(l);
			inserir(l,m,1); 
		}
		else
		{
			gera(l,m+1,n); //CHAMA A MESMA FUNÇAO +1 ATE O CRITERIO DE PARADA M==N
			inserir(l,m,1); //SO RODA NA RETOMADA DE CONTEXTO
		}
	}
}
int main()
{
	LISTA l;
	//criar(&l);
	//inserir(&l,1,1);
	//inserir(&l,2,2);
	//inserir(&l,3,3);
	//inserir(&l,4,4);
	//mostrar(&l);
	//retirar(3,&l);
	//printf("============================================");
	//mostrar(&l);
	//printf("O VALOR DO 3 ITEM EH %d",consultar(3,&l));
	//printf("O VALOR 4 PERTENCE ? %d",pertence(4,&l));
	//printf("EH ORDENADA %d",ordenada(&l));
	gera(&l,1,10);
	mostrar(&l);
}
