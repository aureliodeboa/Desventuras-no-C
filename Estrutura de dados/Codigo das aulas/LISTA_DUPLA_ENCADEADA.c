#include<stdio.h>
#include<stdlib.h>

typedef struct nodo
{
	int inf;
	struct nodo *ant;
	struct nodo *prox;
}NODO;
typedef NODO *LISTA_DUP_ENC;
	
void criar(LISTA_DUP_ENC *pl)
{
	*pl=NULL;
	
}
int eh_vazia(LISTA_DUP_ENC l)
{
	return (l==NULL);
}
int tam(LISTA_DUP_ENC l)
{
	
	int i;
	for(l,i=0;l;l=l->prox,i++);
	return i;
}
void ins(LISTA_DUP_ENC *pl,int v, int k)
{
	if(k<1||k>tam(*pl)+1)
	{
		printf("POSICAO INVALIDA");exit(1);
	}
	else
	{
			LISTA_DUP_ENC novo;
			novo=(NODO*)malloc(sizeof(NODO));
			novo->inf=v;
			if(novo)
			{
				if(eh_vazia(*pl))
				{
					*pl=novo;
					novo->ant=NULL;
					novo->prox=NULL;
				}
				else
				{
					if(k==1)
					{
						novo->prox=*pl;
						(*pl)->ant=novo;
						novo->ant=NULL;
						*pl=novo;
						
					}
					else
					{
						NODO *aux;
						if(k==tam(*pl)+1)
						{
							novo->prox=NULL;
							for(aux=*pl;aux->prox!=NULL;aux=aux->prox);
							novo->ant=aux;
							novo->prox=aux->prox;
							aux->prox=novo;	
											
						}
						else
						{
							int i;
							for(i=2,aux=*pl;i!=k;aux=aux->prox,i++);
							novo->ant=aux;
							novo->prox=aux->prox;
							aux->prox=novo;
							novo->prox->ant=novo;
							
						}
					}
				}
			}
			else
			{
				printf("NAO FOI POSSIVEL ALOCAR MEMORIA!!");exit(4);
			}
		
		
	}
}
int recup(LISTA_DUP_ENC l ,int k)
{
	int i;
	if(k<1||k>tam(l))
	{
		printf("POSICION INVALIDE");
	}
	for(;k>1;k--,l=l->prox);
	return l->inf;
}
int ret(LISTA_DUP_ENC *pl,int k)
{
	NODO *aux;
	
	if(k<1||k>tam(*pl))
	{
		printf("VALOR INVALIDO");exit(6);
	}
		
	if(k==1) //SITUAÇAO 1
	{
		aux=*pl;
		*pl=aux->prox;
		if(*pl)//SITUAÇAO DOIS
		{
			(*pl)->ant=NULL;
				
		}	
		free(aux);
	}
	else //SITUAÇAO 3 e 4
	{
		for(aux=(*pl)->prox;k>2;k--,aux=aux->prox); //saio do for contendo em aux o endereço que eu quero remover
			aux->ant->prox=aux->prox;
			if(aux->prox)
			{
				aux->prox->ant=aux->ant;
			}
			free(aux);
	}
}
int destruir(LISTA_DUP_ENC l)
{
	NODO *aux;
	while(l)
	{
		aux=l;
		l=l->prox;
		free(aux);
	}
}
void imprimir(LISTA_DUP_ENC l)
{
	NODO *aux=l;
	int i=0;
	printf("\n=====================================");
	while(aux)
	{
		printf("\nLISTA= %d",aux->inf);
		aux=aux->prox;
		i++;
	}
	
}
void inse(LISTA_DUP_ENC *pl,int v,int k)
{
	if(k<1||k>tam(*pl)+1)
	{
		printf("POSICAO INVALIDA");exit(1);
	}
	else
	{
			LISTA_DUP_ENC novo;
			novo=(NODO*)malloc(sizeof(NODO));
			novo->inf=v;
			if(novo)
			{
				if(k==1)//SITUAÇAO 1
				{
					novo->ant=NULL;
					novo->prox=*pl;
					
					if(*pl)//SITUAÇAO 2
					{
						(*pl)->ant=novo;
					}
					*pl=novo;
					
				}
				else //SITUAÇÇAO 3 E 4 MEU PARCEIRO""
				{
					NODO *aux; 
					for(aux=*pl;k>2;k--,aux=aux->prox);
					novo->ant=aux;
					novo->prox=aux->prox;
					
					
					if(aux->prox)
					{
						//novo->prox->ant=novo;
						aux->prox->ant=novo;
					}
					aux->prox=novo;
				}
				
			}
			else
			{
				printf("ERRO NO MALLOC");exit(5);
			}
	}
}
void inverter_lista(LISTA_DUP_ENC *pl)
{
    LISTA_DUP_ENC aux,aux1;
    int i;
    if(*pl)
    {
     	do{
		
    	 aux=(*pl)->prox;
    	 (*pl)->prox=(*pl)->ant;
    	 (*pl)->ant=aux;
    	 if(aux)
    	 {
    	 	*pl=aux;
		 }
		}while(aux); 
	}
	else
	{
	 printf("LISTA VAZIA");
	}
}
//====================================================================================================================
//=======================RECURSIVAS PAI===============================================================================
int tamR(LISTA_DUP_ENC l)
{
	if(l)
	{
		return(tamR(l->prox)+1);
		
	}
	else
	{
		return 0;
	}
}
void insR(LISTA_DUP_ENC *pl,int v, int k)
{
	if(k<1||k>tam(*pl)+1)
	{
		printf("POSICAO INVALIDA");exit(3);
	}
	else
	{
		if(k<=2)
		{	
			insR(&((*pl)->prox),v,k-1);
		 	
		}
		else
		{
		
			LISTA_DUP_ENC novo;
			novo=(NODO *)malloc(sizeof(NODO));
			if(novo)
			{
				novo->inf=v;
			if(k==1)//SITUAÇAO 1
				{
					novo->ant=NULL;
					novo->prox=*pl;
					*pl=novo;
					if((*pl)->prox)//SITUAÇAO 2
					{
						(*pl)->prox->ant=novo;
					}
					
				}
				else //SITUAÇÇAO 3 E 4 MEU PARCEIRO""
				{
					NODO *aux; 
					for(aux=*pl;k>2;k--,aux=aux->prox);
					novo->prox=aux->prox;
					aux->prox=novo;
					novo->ant=aux;
					if(novo->prox)
					{
						novo->prox->ant=novo;
					}
			
			
				}
			}
			else
			{
				printf("ERRO NO MALLOC");exit(3);
			}
		}
	}
}

int main()
{
	LISTA_DUP_ENC l;
	criar(&l);
	inse(&l,1,1);
	inse(&l,2,2);
	inse(&l,3,3);
	//insR(&l,0,1);
	imprimir(l);
	//printf("\n TAMANHO %d",tamR(l));
	//ret(&l,1);
	//imprimir(l);
	//destruir(l);
   //printf("\n VALOR =%d",l->inf);
	//inverter_lista(&l);
	//imprimir(l);
	
	
	return 0;
}
