#include<stdio.h>
#include<stdlib.h>

typedef struct nodo 
{
	int inf;
	struct nodo *next;
}NODO;

typedef NODO *LISTA_ENC_CIRCULAR;

void criar(LISTA_ENC_CIRCULAR *pl)
{
	*pl=NULL;
}
int eh_vazia(LISTA_ENC_CIRCULAR l)
{
	return(l==NULL);
}
int tam(LISTA_ENC_CIRCULAR l)
{
	NODO *aux;
	int i;
	if(l)
	{
		for(aux=l->next,i=1;aux!=l;aux=aux->next,i++);
		/*for(i=1,aux=l->next;aux!=l;i++)
		{
			aux=aux->next;
		}*/
		return i;
	}
	else
	{
		return 0;
	}
}
void ins(LISTA_ENC_CIRCULAR *pl,int v,int k)
{
   int tamanho=tam(*pl);
	if(k<1||k>tam(*pl)+1)
	{
		printf("POSICAO INVALIDA!!");exit(1);
	}
	else
	{
		NODO *novo;
		novo=(NODO*)malloc(sizeof(NODO));
		novo->inf=v;
		if(novo)
		{
			if(*pl==NULL)
			{
				novo->next=novo;
				*pl=novo;
			}
			else
			{
				NODO *aux=*pl;
				if(k==tamanho+1)
				{ 
				    	*pl=novo;
				}
				else
				{
					for(;k>1;aux=aux->next,k--);
				}
					novo->next=aux->next;
					aux->next=novo;
			}
		}
		else
		{
			printf("NAO FOI POSSIVEL ARMAZENAR COM MALLOC");exit(2);
		}
	}
}
int recup (LISTA_ENC_CIRCULAR l,int k)
{
	if(k<1||k>tam(l))
	{
		printf("POSICAO I N V A L I D A !!");exit(2);
	}
	else
	{
		if(tam(l))
		{
			 int i;
			for(i=1,l=l->next;i<k;l=l->next,i++);
			return l->inf;
			
		}
		else
		{
			printf("LISTA VAZIA");exit(3);
		}
	}
}
void ret(LISTA_ENC_CIRCULAR *pl,int k)
{
	int tamanho=tam(*pl);
    if(k<1||k>tamanho)
    {
    	printf("POSICACAO INVALIDA");
	}
	else
	{
		int i;NODO *aux,*aux2;
		if(tamanho==1)
		{
			free(*pl);
			*pl=NULL;
			
		}
		else
		{
			
			for(i=1,aux=*pl;i<k;aux=aux->next,i++);
				aux2=aux->next;
				aux->next=aux2->next;
			
			if(k==tamanho)
			{
		
			    *pl=aux;
			    
			}

		}
	}

}

void destruir(LISTA_ENC_CIRCULAR l)
{ 
  	
	if(l)
	{
			LISTA_ENC_CIRCULAR aux;
		for(aux=l->next;aux!=l;aux=aux->next)
		{
			free(aux);
		}
	}
}
void imprimir(LISTA_ENC_CIRCULAR l)
 {
 	int i;
 	LISTA_ENC_CIRCULAR aux;
 	printf("\n======================================\n");
 	for(i=1,aux=l->next;i<=tam(l);aux=aux->next,i++)
 	{
 		printf("\n LISTA=%d  \n",aux->inf);
 		
	 }
	 
}
 	
int main()
{
	LISTA_ENC_CIRCULAR l,l1;
	criar(&l);
	criar(&l1);
	ins(&l1,1,1);
	ins(&l,0,1);
	ins(&l,1,2);
	ins(&l,2,3);
	ins(&l,3,4);
	imprimir(l);
	ret(&l,4);
	destruir(l);
    imprimir(l1);
	return 0;
}
