#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct
{
	int N;
	int elem[max];
}LISTA;

void cria(LISTA *l)
{
   l->N=0;
}
int vazia(LISTA *l)
{
	return(l->N==0);
}
int tamanho(LISTA *l)
{
	return(l->N);
}
void inserir(LISTA *l,int k,int valor)
{   
  int i;
	if(l->N==max)
	{
		printf("ERRO,ESTOURO NA LISTA");
		exit(1);
	}
	else
	{
		if(k<1|| k>l->N+1)
		{
			printf("ERRO,POSICAO INVALIDA PARA INSERÇAO");
			exit(2);
		}
		
		for(i=l->N;i>=k;i--) //FAZER DIFERENTE ISSO AQUI
		{
			l->elem[i]=l->elem[i-1];			
		}
		l->elem[k-1]=valor;
		l->N++;
	}
}
int consulta( LISTA *l, int k)
{
	if(k>l->N || k<1)
	{
		printf("ERROO,CONSULTA INVALIDA");
		exit(3);
	}
	else
	{
		return(l->elem[k-1]);
	}
}
void retirar(LISTA *l,int k)
{
	int i;
	if(k<1|| k>l->N)
	{
		printf("ERRO,VALOR INEXISTENTE NA LISTA");
	}
	else
	{
		
		for(i=k-1;i<l->N;i++)
		{
			l->elem[i]=l->elem[i+1];
		}
		
		l->N--;
	}
}
int pertence (LISTA *l, int valor)
{  
	int i;
		
		for(i=0;i<l->N;i++)
		{
			if(l->elem[i]==valor)
			{
				return(1);
			}
		}
		return(0);
}
void listar(LISTA *l)
{
 	int i;
 	   printf("\n LISTA: \n");
 		for(i=0;i<l->N;i++)
 		{
 			printf("%d \n",l->elem[i]);
		 }
}
int main()
{
	int i=1,k,valor;
	LISTA *l;
	l=(LISTA *)malloc(1*sizeof(LISTA));
	cria(l);
	while (i)
	{
		printf("\n inserir: 1 \n retirar: 2 \n listar: 3 \n consulta: 4 \n ordem: 5\n");
		scanf("%d",&i);
		
	    system("cls");
		switch(i)
		{
			case 1: printf("K ? \n");
					scanf("%d",&k);
					printf("valor ? \n");
					scanf("%d",&valor);
					inserir(l,k,valor);
					break;
					
			case 2: printf("K ? \n");
					scanf("%d",&k);
					retirar(l,k);
					break;
			
			case 3: listar(l);
					break;	
			
			case 4: printf("k?");
				    scanf("%d",&k);	
				    printf("%d",consulta(l,k));
					break;
					
					
			case 5: break;			
		}
	
	
	}
	
	
}

