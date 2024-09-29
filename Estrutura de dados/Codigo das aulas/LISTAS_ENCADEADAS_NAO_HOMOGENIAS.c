#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INTGR 1
#define FLT 2
#define STRING 3

/*typedef struct node
{
	char inf[100];
	struct node *next;
}NODE;
typedef struct 
{
	char nome[30];
	char id[9];
	char end[100];
	char earea[20];
	float cr;
}INF;
typedef struct nodo
{
	INF inf;
	struct nodo *next;
	
}NODO;*/
typedef union {
		int ival;
		float fval;
		char sval[20];
	}inf;
typedef struct nodo2
{
	int etype;
	inf elements;
	struct	nodo2 *prox;
	struct  nodo2 *ant;
}NODO2;
typedef NODO2 *LISTA;
void criar(LISTA *pl)
{
	
	*pl=NULL;
}
int tam(LISTA l)
{
	LISTA aux;int i;
	if(l)
	{
			for(aux=l->prox,i=1;aux!=l;i++,aux=aux->prox);
			return i;
	}
	return 0;
	
}
void ins (LISTA *pl,int k , inf v,int etype)// a referencia externa aponta para o ultimo *pl
{
	int t=tam(*pl),p=k;
	
	if(k<1||k>t+1)
	{
		printf("POSICAO INVALIDA");exit(1);
	}
	else
	{
		
		if(/*pertence(*pl,v,etype)*/0)
		{
			printf("O VALOR JA PERTENCE A LISTA");exit(1);	
		}
		else
		{
		  
			LISTA novo,aux;
			 novo=(LISTA)malloc(sizeof(NODO2));
			 if(novo)
			 {
			 	novo->etype=etype;
			 	novo->elements=v;
			 	
			 	if(*pl=NULL)
			 	{
			 		//*pl=novo->ant=novo->prox=novo;
					*pl=novo;
					 novo->ant=novo;
					 novo->prox=novo;	
				}
				else
				{
					
					if(k==1)
					{
						novo->prox=(*pl)->prox;
						novo->ant=*pl;
						novo->prox->ant=novo;
						(*pl)->prox=novo;
					}
					
				 	int p=k;
					if(k<=t/2)
					{
						for(aux=*pl;k>1;k--,aux=aux->prox);
					}
					else
					{
						for(aux=*pl;k<=t;k++,aux=aux->ant);
					}
					novo->ant=aux;
					novo->prox=aux->prox;
					aux->prox=novo;
					novo->prox->ant=novo;
					if(p==t+1)
					{
						*pl=novo;
					} 
				}
		 	
			 }
			 else
			 {
		 		printf("ERROW NO MALLOC");exit(2);
		 	}
		 
		}
	}
}
int pertence(LISTA l, inf v,int etype)
{
	if(!l)
	{
		return 0;
	}
	else
	{
		LISTA aux=l;
		do{
			if(aux->etype==etype&&((1==etype&&aux->elements.ival==v.ival)||
			(2==etype&&aux->elements.fval==v.fval)||
			(3==etype&&!strcmp(aux->elements.sval,v.sval))))
			{
				return 1;
			}
			aux=aux->prox;
		}while(aux!=l);
		return 0;
	}
	
}
void imprimir(LISTA l)
{
	LISTA aux=l->prox;
		do{
			printf("\nLista= %d",aux->elements.ival);
			aux=aux->prox;
		}while(aux!=l);
}
int main()
{
	LISTA l;
	 inf v;
	
	
	criar(&l);
	v.ival=1;
	ins(&l,1,v,1);
	v.ival=2;
	ins(&l,2,v,1);
	imprimir(l);
	
	return 0;
}
