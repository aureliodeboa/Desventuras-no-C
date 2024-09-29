#include<stdio.h>
#include<stdlib.h>
typedef struct nodo
{
	int inf;
	struct nodo *prox;
}NODO;
typedef  struct 
{
	NODO *INICIO;
	NODO *FIM;
	
}DESCRITOR;
typedef DESCRITOR *FILA_ENC;
void criar(FILA_ENC *pf )
{
	*pf=(DESCRITOR*)malloc(sizeof(DESCRITOR));
	if(!*pf)
	{
		printf("ERRO NO MALLOC!!");exit(1);
	}
	(*pf)->INICIO=NULL;
	(*pf)->FIM=NULL;
	
}
int eh_vazia(FILA_ENC f)
{
	return(f->INICIO==NULL);
}
void ins(FILA_ENC f,int v)
{
	NODO *novo;
	novo=(NODO*)malloc(sizeof(NODO));
	if(!novo)
	{
		printf("ERRO NO MALLOC!!");exit(2);
		
	}
	else
	{
		novo->inf=v;
		novo->prox=NULL;
		if(eh_vazia(f))
		{
			f->INICIO=novo;
		}
		else
		{
			f->FIM->prox=novo;
			
		}
		f->FIM=novo;
	}
}
int cons(FILA_ENC f)
{
	if(eh_vazia(f))
	{
		printf("A FILA ESTA VAZIA");exit(3);
	}
	else
	{
		return(f->INICIO->inf);
	}
}
void ret(FILA_ENC f)
{
	if(eh_vazia(f))
	{
		printf("WE HAVE A PROBLEM,THIS LIST IS empty");exit(4);
	}
	else
	{
		NODO *aux=f->INICIO;
		f->INICIO=f->INICIO->prox;
		if(!f->INICIO)
		{
			f->FIM=NULL;
		}
		free(aux);
	}
}
int cons_ret(FILA_ENC f)
{
	 if(eh_vazia(f))
	 {
	 	printf("WE HAVE A PROBLEM, THIS LIS IS EMPTY");exit(5);
	 }
	 else
	 {
	 	NODO *aux=f->INICIO;
	 	int i=f->INICIO->inf;
	 	f->INICIO=f->INICIO->prox;
	 	free(aux);
	 	
	 	if(!f->INICIO)
	 	{
	 		f->FIM=NULL;	
		}
		return(i);
	 }
}
void destruir(FILA_ENC f)
{
	
	NODO *aux;
	while(f->INICIO)
	{
		aux=f->INICIO;
		f->INICIO=f->INICIO->prox;
		free(aux);
		
	}
	free(f);
	
}
void imprimir(FILA_ENC f)
{
	int i=0;
 	NODO *aux;
 	for(;f->INICIO;f->INICIO=f->INICIO->prox,i++)
 	{
 		printf("FILA[%d]=%d \n",i,f->INICIO->inf);
	 }
}
int main()
{
	FILA_ENC f;
	criar(&f);
	ins(f,1);
	ins(f,2);
	ins(f,3);
	ins(f,4);
	//ret(f);
	imprimir(f);
	destruir(f);
}
