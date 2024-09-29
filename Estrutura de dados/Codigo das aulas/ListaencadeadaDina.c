#include<stdio.h>
#include<stdlib.h>

 typedef struct nodo
 {
	int inf;
	struct nodo *next; //ponteiro para o proximo nodo por isso foi dado nome a struct
   }NODO;
 typedef NODO *LISTA_ENC;
 
 void cria_lista(LISTA_ENC *pl)
 {
 	*pl=NULL;
 }
 int vazia(LISTA_ENC l)
 {
 	if(l==NULL)
 	{
 		return 1;
	}
	else
	{
		return 0;
	}
	
 }
 int tam(LISTA_ENC l)
 {
 	int i;
 	for(i=0;l!=NULL;i++)
 	{
 		l=l->next;
	}
	
 	return i;
 }
 void ins(LISTA_ENC *pl,int v, int k)
 {
 	NODO *novo;
 	
 	if(k<1||k>tam(*pl)+1)
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
			int i;
			if(k==1)
			{
				novo->next=*pl;
				*pl=novo;
			}
			else
			{
				LISTA_ENC aux;
				for(aux=*pl,i=0;i<k-2;aux=aux->next,i++);
				novo->next=aux->next;
				aux->next=novo;
			}
		}
	}
 	
 	
 }
 void inserir(LISTA_ENC *pl,int v,int k)
 {
 	if(k<1||k>tam(*pl)+1)
 	{
 		printf("POSICAO DE INSERCAO INVALIDA ");exit(3);
	}
	else
	{
		if(k==1)
		{
			NODO *novo;
			novo=(NODO *)malloc(sizeof(NODO));
			if(!novo)
			{
				printf("NAO FOI POSSIVEL ALOCAR!!");exit(9);
			}
			novo->inf=v;
			novo->next=*pl;
			*pl=novo;
			
		}
		else
		{
			inserir(&((*pl)->next),v,k-1);
		}
	}
 	
 	
 	
 	
 }
 int recup(LISTA_ENC l, int k)
 {  
  int i;
   if(k<1||k>tam(l))
   {
   	printf("\n ERRO NA CONSULTA");exit(3);
   }
   else
   {
   	for(i==0;i<k-1;i++)
   	l=l->next;
   	return(l->inf);
   }
 	
 }
 void ret(LISTA_ENC *pl, int k)
 {
 	NODO *aux;
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
			for(aux=*pl;k<2;k--,aux=aux->next);
			aux2=aux->next;
			aux->next=aux2->next;
			free(aux2);
		}
	}
 	
 }
 void retirar(LISTA_ENC *pl, int k)
 {
 	if(k<1||k>tam(*pl))
 	{
 		printf("POSICAO INVALIDA");exit(6);
	 }
	 else
	 {
	 	if(k==1)
	 	{
	 		NODO *aux;
	 		
	 		aux=*pl;
	 		*pl=aux->next;
	 		free(aux); 
	    }
	    else
	    {
	    	retirar(&((*pl)->next),k-1);
		}
	 }
 }
 void destruir(LISTA_ENC l)
 {
 	LISTA_ENC aux;
 	while(l)
 	{
 		aux=l;
 		l=l->next;
 		free(aux); 	
	 }
 }
  int tamanho(LISTA_ENC l)
 {
 	if(!l)
 	{
 		return 0;
	 }
	 else
	 {
	 	return (1+tamanho(l->next));
	 }
 }
 int verificar(LISTA_ENC l, int k)
 {
 	if(k<1||k>tamanho(l))
 	{
 		printf("VALOR INVALIDO");
	}
	else
	{
		if(k==1)
		{
			return(l->inf);
		}
		else
		{
			return(verificar(l->next,k-1));
		}
		
		
		 	
	}
 	
 }
 void desstruir(LISTA_ENC l)
 {
 	/*
 	if(l==NULL)
 	{
 	 	free(l);	
	}
	else
	{
		desstruir(l->next);
		free(l->next);
	}*/
	if(l)
	{
		desstruir(l->next);
		free(l);
	}
 }
 int pertence(LISTA_ENC l,int v)
 {  
 	while(l)
 	{
 		if(l->inf==v)
 		{
 			return 1;
		 }
		 l=l->next;
	 	
	}
 	return 0;

}
int pertencer(LISTA_ENC l, int v)
{
	if(l)
	{
		if(l->inf==v)
		{
			return 1;
		}
		else
		{
		   return (pertencer(l->next,v));
		}
	}
	return 0;		
}
int eh_ord(LISTA_ENC l)
{
	NODO *aux,*aux2;
	for(aux=l,aux2=aux->next;aux2!=NULL;aux=aux->next,aux2=aux2->next)
	{
		if(aux->inf>aux2->inf)
		{
			return 0;
		}
	}
	return 1;
}
int eh_ordR(LISTA_ENC l)
{
	NODO *aux=l->next;
	if(aux)
	{
		if(l->inf>aux->inf)
		{
			return 0;
		}
		else
		{
			return(eh_ordR(l->next));
		}
	}
	return 1;
}
void gera_lista(LISTA_ENC *pl,int m, int n)
{
	if(m>n)
	{
		printf("INTERVALO INVALIDO");exit(5);
	}
	
	if(m==n)
	{
		inserir(pl,m,1); //Atenta-se que a lista é criada de tras para frente
	}
	else
	{
		gera_lista(pl,m+1,n);
		inserir(pl,m,1);
	}
}
void imprimir(LISTA_ENC *l)
 {
 	int i;
 	LISTA_ENC aux;
 	printf("\n==============LISTA===============");
 	for(aux=*l;aux!=NULL;aux=aux->next)
 	{
 		printf("\n LISTA=%d  \n",aux->inf);
 		
	 }
 	
 }
 void troca(LISTA_ENC *l1,LISTA_ENC *l2,int k1,int k2)
 {
 	LISTA_ENC aux1,aux2,aux;
 	if((k1<1)||(k2<1)||(k1>tam(*l1))||(k2>tam(*l2)))
 	{
 		printf("POSISAO INVALIDA ");exit(1);
	 }
	 else
	 {
	 	int i;
	 	for(aux1=*l1,i=1;i<k1;i++,aux1=aux1->next);
	 	for(aux2=*l1,i=1;i<k2;i++,aux2=aux2->next);
	 	i=aux1->inf;
	 	aux1->inf=aux2->inf;
	 	aux2->inf=i;
	 }
 	
 }
 int main()
 {
 	LISTA_ENC l1,l2; int i,j;
 	cria_lista(&l1);
 	cria_lista(&l2);
    gera_lista(&l1,20,30);
    gera_lista(&l2,30,40);
	 //imprimir(&l);
	 //desstruir(l);
	 imprimir(&l1);
	 //imprimir(&l2);
	 troca(&l1,&l1,1,3);
	 imprimir(&l1);
	 //imprimir(&l2);
	 
	 
	 
 }
