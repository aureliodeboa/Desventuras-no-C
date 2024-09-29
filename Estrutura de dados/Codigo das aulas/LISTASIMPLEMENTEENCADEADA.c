#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int inf;
    struct node *next;
}NODO;
typedef struct{
    NODO *first;
    NODO *last;
}descritor;

typedef descritor *List;

void criar(List *pl)
{
	*pl=(List)malloc(sizeof(descritor));
	if(*pl)
	{
		(*pl)->first=NULL;
		(*pl)->last=NULL;
	}
	else
	{
		printf("ERRO NO MALLOC");exit(1);
	}
}
int tam(List l)
{
	if(!eh_vazia(l))
	{
		int i=1;NODO *aux;
		
		for(aux=l->first;aux!=l->last;aux=aux->next, i++);
		return(i);	
	}
	else
	{
		return(0);	
	}
}
int eh_vazia(List l)
{
	return(l->first==NULL);
	
}
void inserir(List l,int v,int k)
{
	if(k<1||k>tam(l)+1)
	{
		printf("POSICAO INVALIDA");exit(32);
	}
	else
	{
		NODO *aux,*novo;
		novo=(NODO*)malloc(sizeof(NODO));
		
		if(novo)
		{
			novo->inf=v;
			if(eh_vazia(l))
			{
				novo->next=l->first;
				l->first=novo;
				l->last=novo;
				
			}
			else
			{
				if(k==1)
				{
					novo->next=l->first;
					l->first=novo;
					
				}
				else
				{
					int i=k;
					for(aux=l->first;k>2;k--,aux=aux->next);
					novo->next=aux->next;
					aux->next=novo;
					if(i==(tam(l))+1)
					{
						l->last=novo;
					}
				}
			}
			
		}
		else
		{
			printf("ERRO NO MALLOCR");exit(21);
		}
		
	}
}
void imprimir(List l)
{
	NODO *aux;
	int i=tam(l);
	for(aux=l->first;i;aux=aux->next,i--)
	{
		printf("\n LISTA= %d",aux->inf);
	}
}
int main()
{
	List l;
	criar(&l);
	inserir(l,1,1);
	inserir(l,2,2);
	inserir(l,3,1);
	//inserir(l,1,1);
	imprimir(l);
	printf("\nÈ tam %d",tam(l));
}
