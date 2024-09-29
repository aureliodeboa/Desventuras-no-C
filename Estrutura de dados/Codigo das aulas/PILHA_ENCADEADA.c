#include<stdio.h>
#include<stdlib.h>
typedef struct nodo
{
	int inf;
	struct nodo *next;
	
}NODE;
typedef NODE *PILHA_ENC;
 
void create(PILHA_ENC *pp)
{
	(*pp)=NULL;
}
int is_empty(PILHA_ENC p)
{
	return(p==NULL);
}
void push(PILHA_ENC *pp,int v)
{
	NODE *novo;
	novo=(PILHA_ENC)malloc(sizeof(NODE));
	
	if(!novo)
	{
		printf("ERRO NO MALLOC \n");exit(1);
	}
	else
	{
		novo->inf=v;
		novo->next=*pp;
		*pp=novo;
		
	}
}
int top(PILHA_ENC p)
{
	if(!p)
	{
		printf("LISTA VAZIA");exit(2);
	}
	return(p->inf);
}
void pop(PILHA_ENC *pp)
{
	if(!pp)
	{
		printf("LISTA VAZIA");exit(3);
	}
	else
	{
		NODE *aux=*pp;
		(*pp)=(*pp)->next;
		free(aux);
	}
}
int top_pop(PILHA_ENC *pp)
{
		if(!pp)
	{
		printf("LISTA VAZIA");exit(4);
	}
	else
	{
		NODE *aux=*pp;
		int i=(*pp)->inf;
		*pp=(*pp)->next;
		free(aux);
		return(i);
	}
}
void destroy(PILHA_ENC p)
{
	NODE *aux;
	while(p)
	{
		aux=p;
		p=p->next;
		free(aux);
	}
}
void imprimir(PILHA_ENC p)
{
	int i;
	PILHA_ENC aux=p;
	for(i=0;aux;aux=aux->next)
	{
		printf("PILHA=%d \n",aux->inf);
	}
	
	
}
void gera_pilha(PILHA_ENC *p, int m, int n)
{
		if(m>n)
	{
		printf("INTERVALO INVALIDO");exit(6);
	}
	else
	{
		if(m==n)
		{
			create(p);
			push(p,m);
		}
		else
		{
			gera_pilha(p,m,n-1);
			push(p,n);
			
		
		
		}
	}
}
int main()
{
	PILHA_ENC  p;
	/*create(&p);
	push(&p,1);
	push(&p,2);
	push(&p,3);
	push(&p,4); */
	gera_pilha(&p,1,10);
	imprimir(p);
	printf("\n TOP = %d \n",top(p));
	
}
