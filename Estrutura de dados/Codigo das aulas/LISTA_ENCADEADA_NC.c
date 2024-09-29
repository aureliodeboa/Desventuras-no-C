#include<stdio.h>
#include<stdlib.h>

typedef struct nodo
{
	int inf;
	struct nodo *next;
}NODO;
typedef NODO *LISTA_ENC_NC;

void criar(LISTA_ENC_NC *pl)
{ 	
   *pl=(NODO*)malloc(sizeof(NODO));
	if(!*pl)
	{
		printf("ERRO DE MEMORIA");exit(5);
	}
	
     (*pl)->inf=0;
     (*pl)->next=NULL;
}
void imprimir(LISTA_ENC_NC l)
 {
 
 	LISTA_ENC_NC aux;
 	printf("=============================================");
 	for(aux=l->next;aux!=NULL;aux=aux->next)
 	{
 		printf("\n LISTA=%d  \n",aux->inf);
 		
	 }
 	
 }
int vazia(LISTA_ENC_NC l)
{
  return (l->inf==0);
}
int tam(LISTA_ENC_NC l)
{
	return(l->inf);
}
void ins(LISTA_ENC_NC l,int v,int k)
{
	NODO *aux, *novo;
	if(k<1||k>l->inf+1)
	{
		printf("POSIÇAO INVALIDA "); exit(1);
	}
	else
	{ 	
	    novo=(NODO*) malloc(sizeof(NODO));
	   if(!novo)
		{
			printf("NAO FOI POSSIVEL ALOCAR ");exit(2);
		}
			
		else
		{
			
			novo->inf=v;
			for(aux=l;k>1;aux=aux->next,k--);
			
		    novo->next=aux->next;
		    aux->next=novo; 
		    l->inf++;
			
		}
	}
	
}
int recup(LISTA_ENC_NC l,int k)
{
	NODO *aux;
	int i=1;
	if(k<1|k>l->inf)
	{
		printf("POSICAO INVALIDA");exit(3);
	}
	else
	{
		for(aux=l->next;i!=k;aux=aux->next,i++);
		return aux->inf;
	}	
}
void ret(LISTA_ENC_NC l,int k)
{
    NODO *aux,*aux2;;
    int i=1;
    if(k<1||k>l->inf)
    {
    	printf("POSICAO INVALIDA");exit(3);
	}
	else
	{
		for(aux=l;i<k-1;aux=aux->next,i++);
		
		aux2=aux->next;
		aux->next=aux2->next;
		free(aux2);
		l->inf--;
	}
}
void destruir(LISTA_ENC_NC l)
{
	//NODO *aux;
	while(l)
	{
		free(l);
		l=l->next;
	}
}
int main()
{
	LISTA_ENC_NC l;
	criar(&l);
	ins(l,1,1);
	ins(l,2,2);
	ins(l,3,3);
	ins(l,4,4);
	imprimir(l);
	ret(l,1);
	imprimir(l);
	printf("%d",l->inf);
	destruir(l);
	//printf("%d",l->inf);
}

