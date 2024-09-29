#include<stdio.h>
#include<stdlib.h>

typedef struct nodo
{
	int inf;
	struct nodo *next;
}NODO;
typedef NODO *LISTA_ENC_ORD;
void cria_lista(LISTA_ENC_ORD *pl){
	*pl=NULL;
}
int vazia(LISTA_ENC_ORD l){
	if(l)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int tam(LISTA_ENC_ORD l){
	if(!l)
	{
		return (0);
	}
	else
	{
		return(1+tam(l->next));
	}
}
void ret(LISTA_ENC_ORD *pl, int k)
 {
 	NODO *aux;
 	int i=0;
 	if(k<1||k>tam(*pl))
 	{
 		printf("ERRO POSICA INVALIDA");exit(5);
	}
	else
	{
		if(k==1)
		{
			aux=*pl;
			*pl=aux->next; 
			free(aux);		
		}
		else
		{
			NODO *aux2;
			for(aux=*pl,i=0;i<k-2;aux=aux->next,i++);
			
			aux2=aux->next;
			aux->next=aux2->next;
			free(aux2);
		}
	}
 	
 }
void inserir(LISTA_ENC_ORD *pl,int v)
{   
    	

		NODO *novo;
		novo=(NODO*)malloc(sizeof(NODO));
		
		if(novo)
		{  
			novo->inf=v;
			if(*pl==NULL|| v<(*pl)->inf)
			{
				novo->next=*pl;
				*pl=novo;	
			}
			else
			{  
				NODO *aux;int i;
				for(aux=*pl;(aux->next!=NULL)&&v>((aux->next)->inf);aux=aux->next);//ou para no ultimo ou no aterior ao maior que o valor
					novo->next=aux->next;
					aux->next=novo;					
			}  
				
		}
		else
		{
			printf("NAO FOI POSSIVEL ALOCAR MEMORIA");exit(1);
		}
}
int retirar_valor(LISTA_ENC_ORD *pl,int v)
{
	 NODO *aux=*pl; 
	 int i=0;
	 int k=1;
	 
	 while(aux&&aux->inf<=v)
	 {
	 	if(aux->inf==v)
	 	{
	 		ret(pl,k);
	 		
	 		
	 		i=1;
	 	}
		 aux=aux->next;
		  k++;
	 }
	 return i;
	 	  
 }
int pertence(LISTA_ENC_ORD l,int v)
{
	NODO *aux=l;int i;
	
	while(aux)
	{
		if(aux->inf==v)
		{
			return 1;
		}
		else
		{ 
		   aux=aux->next;
						
		}
	}
	return 0;
}
 void imprimir(LISTA_ENC_ORD l)
 {
 
 	LISTA_ENC_ORD aux;
 	printf("=========================================");
 	for(aux=l;aux!=NULL;aux=aux->next)
 	{
 		printf("\n LISTA=%d  \n",aux->inf);
 		
	 }
 	
 }
 int ret_com_base_no_valor(LISTA_ENC_ORD *pl,int v)
 {
 	NODO *aux;int k=1;
 	
 	for(aux=*pl;aux&&aux->inf<=v;aux=aux->next,k++)
 	{
 		if(aux->inf==v)
		 {
		 		ret(pl,k);
		 		return 1;
		 }	
	}
	return 0;
 }
int ret_valor(LISTA_ENC_ORD *pl,int v)
{
	NODO *aux=*pl,*aux2;int k=1,i=0;   //NAO ESTA FUNCIONANDO PARA REMOVER DOIS VALORES IGUAIS
	
	for(;aux!=NULL && aux->inf<=v;k++)
	{  
	   if(aux->inf==v)
		{
			aux=aux->next;
		    ret(pl,k);
			i=1;
			k--;
		}
		else
		{
			aux=aux->next;
		}	
	}
	return i;
}
int main()
{
	LISTA_ENC_ORD l; 
	
    	cria_lista(&l);
		inserir(&l,9);
	    inserir(&l,22);
		inserir(&l,113);
		inserir(&l,12);
		inserir(&l,118);
		inserir(&l,122);
		inserir(&l,122);
	    inserir(&l,122);
		imprimir(l);
		ret_valor(&l,122);
	    imprimir(l);
	
	
}

