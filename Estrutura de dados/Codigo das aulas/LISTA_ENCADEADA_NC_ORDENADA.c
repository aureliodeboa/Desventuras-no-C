#include<stdio.h>
#include<stdlib.h>
typedef struct nodo
{
	int inf;
	struct nodo *next;
}NODO;

typedef NODO *LISTA_ENC_NC_ORD;
void criar(LISTA_ENC_NC_ORD *pl)
{
	*pl= (NODO*)malloc(sizeof(NODO));
	if(*pl)
	{
		(*pl)->inf=0;
		(*pl)->next=NULL;	
	}
	else
	{
		printf("NAO FOI POSSIVEL ALOCAR");exit(1);
	}
}
void imprimir(LISTA_ENC_NC_ORD l)
{
	NODO *aux;
	printf("\n===========================================");
	for(aux=l->next;aux!=NULL;aux=aux->next)
	{
		printf("\n LISTA= %d ",aux->inf);
	}
}
void inserir(LISTA_ENC_NC_ORD l,int v)
{
	NODO *aux,*novo; int i;
	
	novo=(NODO*)malloc(sizeof(NODO));
	if(!novo)
	{
		printf("NAO FOI POSSIVEL ALOCAR NOVO!!");exit(2);
	}
	else
	{    l->inf++;
		novo->inf=v;
		
		for(aux=l;aux->next!=NULL&&v>(aux->next)->inf;aux=aux->next);
			novo->next=aux->next;
			aux->next=novo;		
	}
	
}
int eh_vazia(LISTA_ENC_NC_ORD l)
{
	return(l->inf==0);
}
int tam(LISTA_ENC_NC_ORD l)
{
	return (l->inf);
}
int recup(LISTA_ENC_NC_ORD l,int v)
{
	NODO *aux;
	
	if(eh_vazia(l))
	{
		return 0;
	}
	else
	{
		for(aux=l->next;aux!=NULL;aux=aux->next)
		{
			if(aux->inf==v)
			{
				return 1;
			}
		}
		return 0;
	}
}
int ret(LISTA_ENC_NC_ORD l,int v)
{
	if(recup(l,v))
	{
		NODO *aux,*aux2;
		for(aux=l;(aux->next)->inf!=v;aux=aux->next);
		aux2=aux->next;
		aux->next=aux2->next;
		free(aux2);
	
	}
	else
	{
		printf("\n O VALOR %d NAO PERTENCE A LISTA!! \n",v);exit(3);
	}
}
void  destruir(LISTA_ENC_NC_ORD l )
{ 
  	NODO *aux;
    while(l)
    {
    	aux=l;
    	l=l->next;
    	free(aux);
	}
    
    
}
LISTA_ENC_NC_ORD  concatenar(LISTA_ENC_NC_ORD l1,LISTA_ENC_NC_ORD l2)
{
	LISTA_ENC_NC_ORD l;
	int i;
	criar(&l);
    for(l1=l1->next;l1!=NULL;l1=l1->next)
    {
    	if(!recup(l,l1->inf))
		 {
		 	inserir(l,l1->inf);
		 }
	}
	for(l2=l2->next;l2!=NULL;l2=l2->next)
	{
		if(!recup(l,l2->inf))
		{
			inserir(l,l2->inf);
		}
	}
 
 return(l);
	
}
void gera(LISTA_ENC_NC_ORD l,int m, int n)
{
	if(m>n)
	{
		printf("INTERVALO INVALIDO!!");exit(5);
	}
	if(m==n)
	{
	
		inserir(l,m);
	}
	else
	{
	  gera(l,m+1,n);
	  inserir(l,m);
	}
}
void insR(LISTA_ENC_NC_ORD l,int v)
{
	if(l->next&&l->inf<v)
	{
		insR(l->next,v);
	}
	else
	{	
		NODO *novo;
		novo=(NODO*)malloc(sizeof(NODO));
	 	if(novo)
	 	{
	 		novo->inf=v;
	 		novo->next=l->next;
	 		l->next=novo;
	 		
		}
		else
		{
			printf("NAO FOI POSSIVEL ALOCAR");exit(1);
		}
		
	}

}
int recupR(LISTA_ENC_NC_ORD l, int v)
{
	if(l->next!=NULL&&l->inf==v)
	{
		return(1);
	}
	else
	{
		if(l->next!=NULL&&l->inf!=v)
		{
			return(recupR(l->next,v));
		}
		else{
			return 0;
		}
	}
}
int retR(LISTA_ENC_NC_ORD l, int v)
{
	if(recupR(l,v))
	{
		if((l->next)->inf==v)
		{
		   NODO *aux;
		   aux=l->next;
		   l->next=aux->next;
		   free(aux); 
	     
		  return 1; 
		   
		}
		else
		{
			return(retR(l->next,v));	
		}
	}
	else
	{
		printf("ESSE VALOR NAO ESTA NA LISTA BJS"); return 0;
	}
}
void destruirR(LISTA_ENC_NC_ORD l)
{
	if(l)
    {
    	destruir(l->next);
    	free(l);
    	
	}
}
int main()
{
	LISTA_ENC_NC_ORD l,l1,l2;
	criar(&l);
	criar(&l1);
	criar(&l2);
	gera(l1,9,20);
	gera(l2,1,10);
	imprimir(l1);
	imprimir(l2);
	gera(l,1,2);
    //insR(l,4);
	//retR(l,1011);
	//imprimir(l);
    //destruir(l);
	//imprimir(l);
	

	
	
}




