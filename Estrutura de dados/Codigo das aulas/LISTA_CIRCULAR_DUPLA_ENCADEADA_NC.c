#include<stdio.h>
#include<stdlib.h>
typedef struct nodo
{
	int inf;
	struct nodo *ant;
	struct nodo *prox;
}NODO;
typedef NODO *LISTA_CIR_DUP_ENC_NC;
void criar(LISTA_CIR_DUP_ENC_NC *pl)
{
	  
	  *pl=(LISTA_CIR_DUP_ENC_NC)malloc(sizeof(NODO));
	  if((*pl))
	  {
		(*pl)->inf=0;
		(*pl)->ant=*pl;
		(*pl)->prox=*pl;
	  }
	  else
	  {
	  	printf("ERRO NO MALLOC");exit(1);
	  }
}
int eh_vazia(LISTA_CIR_DUP_ENC_NC l)
{
	return(l->inf==0);
}
int tam(LISTA_CIR_DUP_ENC_NC l)
{
	return(l->inf);
}
void ins(LISTA_CIR_DUP_ENC_NC l,int v,int k)
{
	LISTA_CIR_DUP_ENC_NC novo,aux;
	if(k<1||k>tam(l)+1)
	{
		printf("POSICAO INVALIDA");exit(1);	
	}
	  novo=(LISTA_CIR_DUP_ENC_NC)malloc(sizeof(NODO));
	if(!novo)
	{ 	printf("ERRRO NO MALLOC");exit(2);	
		
	}
	 l->inf++; //aumentou o o tamanho
	novo->inf=v;
	
	while(--k)
	 l=l->prox;
	novo->ant=l;
	novo->prox=l->prox;
	l->prox=novo;
	novo->prox->ant=novo;
		
	      	
		   
		
}
void bk(LISTA_CIR_DUP_ENC_NC l,int v,int k)
{
	LISTA_CIR_DUP_ENC_NC novo,aux;
	if(k<1||k>tam(l)+1)
	{
		printf("POSICAO INVALIDA");exit(1);	
	}
	  novo=(LISTA_CIR_DUP_ENC_NC)malloc(sizeof(NODO));
	if(novo)
	{ 
		novo->inf=v;
		for(aux=l;k>1;aux=aux->prox,k--);
	      	novo->prox=aux->prox; //o proximo sera o antigo proximo
	      	novo->ant=aux; //o ant sera o antigo k
	      	aux->prox=novo; // o antigo aponta para o novo
	      	novo->prox->ant=novo;  // o novo proximo aponta em ant para novo
		    l->inf++; //aumentou o o tamanho
	}
	else
	{
		printf("ERRRO NO MALLOC");exit(2);	
	}	
}
int recup(LISTA_CIR_DUP_ENC_NC l, int k)
{

	if(k<1||k>tam(l))
	{
		printf("POSICAO INVALIDA");exit(3);
	}
	else
	{
		
		for(l=l->prox;k>1;l=l->prox,k--);
		return(l->inf);
	}
}
void ret(LISTA_CIR_DUP_ENC_NC l, int k)
{
   if(k<1||k>tam(l))
   {
   	 	printf("POSICAO INVALIDA");exit(5);
   }
   else
   {
  		  LISTA_CIR_DUP_ENC_NC aux,aux2;
  		
  		for(aux=l;k>1;aux=aux->prox,k--);
  		aux2=aux->prox;
  		aux->prox=aux2->prox;
  		aux->prox->ant=aux->prox;
  		free(aux2);
  		l->inf--;
  		
  		
   }
}
void destruir(LISTA_CIR_DUP_ENC_NC l)
{
	NODO *aux;
	int tam=l->inf;
 	while(tam--)
	{
		aux=l;
		l=l->prox;
		free(aux);
		
	}
}
void imprimir(LISTA_CIR_DUP_ENC_NC l)
{
	NODO *aux;
	int i;
	printf("\n=========LISTA===================");
	for(i=1,aux=l->prox;i<=l->inf;i++,aux=aux->prox)
	{
		printf("\n LISTA= %d",aux->inf);
	}
}
void inverter_lista(LISTA_CIR_DUP_ENC_NC l)
{
	LISTA_CIR_DUP_ENC_NC aux;
	int tam=l->inf;
	do
	{
		aux=l->prox;
		l->prox=l->ant;
		l->ant=aux;
		l=l->prox;
		
	}while(tam--);
}
//////////////////////////////////////////////////////////////////////////////////


//EXERCICIOS

////////////////////////////////////////////////////////////////////////////////////////
void rett(LISTA_CIR_DUP_ENC_NC l,int k){
    int tamanho = l->inf;
    if(k<1 || k> tamanho){
        printf("posicao invalida!");
        exit(4);
    }
    l->inf--;
    while(k++<=tamanho)
        l=l->ant;
    l->prox->ant = l->ant;
    l->ant->prox = l->prox;
    free(l);
}

void inse(LISTA_CIR_DUP_ENC_NC l, int v ,int k)
{
	LISTA_CIR_DUP_ENC_NC aux,novo;
	if(k<1||k>l->inf+1)
	{
		printf("POSICAO I N V A L I D A");exit(1);
	}
  	novo=(LISTA_CIR_DUP_ENC_NC)malloc(sizeof(NODO));
  	if(novo)
  	{
  		novo->inf=v;
 		if(k<=(l->inf)/2)
 		{
 			for(aux=l;k>1;k--,aux=aux->prox);
			 novo->prox=aux->prox;
			 novo->ant=aux;
			 aux->prox=novo;
			 novo->prox->ant=novo;	
		}
		else
		{
			for(aux=l;k<=l->inf;k++,aux=aux->ant);
			novo->ant=aux->ant;
			novo->prox=aux;
			aux->ant=novo;
			novo->ant->prox=novo;
		}
  		l->inf++;
	}
	else
	{
		printf("ERRO NO MALLOC");exit(2);
	}
	
	
}
int recuperar(LISTA_CIR_DUP_ENC_NC l,int k)
{
	if(k<1||k>tam(l))
	{
		printf("POSICAO INVALIDA");
	}
	else
	{
		NODO *aux;
	   if(k<=(tam(l))/2)
	   {
	   	for(aux=l->prox;k>1;k--,aux=aux->prox);
	   	return(aux->inf);
	   }
	   else
	   {
	   	 for(aux=l;k<=l->inf;k++,aux=aux->ant);
	   	 return (aux->inf);
	   }
	}
}
int retirar(LISTA_CIR_DUP_ENC_NC l ,int k)
{
	if(k<1||k>tam(l))
	{
		printf("POSICAO INVALIDA");exit(1);
	}
	else
	{
		NODO *aux,*aux2;
		aux=l;
		if(k<=tam(l)/2)
		{
			for(;k>0;k--,aux=aux->prox);
		}
		else
		{
			for(;k<=tam(l);k++,aux=aux->ant);
		}
		aux2=aux;
		aux->ant->prox=aux->prox;
		aux->prox->ant=aux->ant;
		free(aux2);
		l->inf--;
		
		
		
		
		
		
		
		
		/*if(k<=tam(l)/2)
		{
			for(aux=l;k>1;k--,aux=aux->prox);
			aux2=aux->prox;
			aux->prox=aux2->prox;
			aux->prox->ant=aux->prox;
		
		}
		else
		{
			for(aux=l;k<l->inf;k++,aux=aux->ant);
			aux2=aux->ant;
			aux->ant=aux2->ant;
			aux->ant->prox=aux;
		}
			l->inf--;
			free(aux2);	
		*/		
	}
}
int main()
{
	LISTA_CIR_DUP_ENC_NC l;
	criar(&l);
	ins(l,1,1);
	ins(l,2,2);
	ins(l,3,3);
	ins(l,4,4);
	ins(l,5,5);
	/*
	inse(l,6,6);
	inse(l,7,7);
	inse(l,8,8);
	inse(l,9,9);
	inse(l,10,10);*/
	
	imprimir(l);
//	rett(l,2);
	destruir(l);
	//imprimir(l);
	printf("\n VALOR %d",recuperar(l,4));
	//retirar(l,2);
	//inverter_lista(l);
	//inse(l,30,7);
	
	//imprimir(l);
	//printf("\n %d",l->inf);

	 
}
