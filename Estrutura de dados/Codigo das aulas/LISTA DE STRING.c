#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct nodo
{
	char inf;
	struct nodo *prox;
	
}NODO;

typedef struct 
{
	int inf;
	NODO *prox;
}NODONC;

typedef NODONC *LISTA;

void criar(LISTA *pl)
{
	*pl=(LISTA)malloc(sizeof(NODONC));
  	(*pl)->inf=0;
  	(*pl)->prox=NULL;
	
}
void ins(LISTA l,char v, int k)
 {
 	NODO *novo; 
 	
 	if(k<1||k>l->inf+1)
 	{
 		printf("POSICAO INVALIDA");
 		exit(1);
	}
	else
	{
		novo=(NODO*)malloc(sizeof(NODO));
		if(!novo)
		{
			printf("ERRO NO MALLOC");exit(2);
		}
		else{
			novo->inf=v;
		
			
			if(k==1)
			{
			
				novo->prox=l->prox;
				l->prox=novo;
				l->inf++;
				
			}
			else
			{
				NODO *aux;
				
				for(aux=l->prox;k>2;aux=aux->prox,k--);
				novo->prox=aux->prox;
				aux->prox=novo;
				l->inf++;
			}
				
			
		}
	}
 	
 	
 }

LISTA XAMA(LISTA l,char *string)
{
	int i,aux;
	for(i=0;string[i]!='\0';i++)
	{
		ins(l,string[i],i+1);
	}
    return  l;
}
void imprimir(LISTA l)
 {
 	int i;
 	NODO *aux;
 	printf("\n==============LISTA===============");
 	for(aux=l->prox,i=0;i<l->inf;aux=aux->prox,i++)
 	{
 		printf("\n [%c]  \n",aux->inf);
 		
	 }
 	
 }
int main()
{
	char string[]="aurelio jose ribeiro da silva";
	LISTA l;
	criar(&l);
	
	l=XAMA(l,string);
	
	imprimir(l);
	printf("%d",l->inf);	
}
