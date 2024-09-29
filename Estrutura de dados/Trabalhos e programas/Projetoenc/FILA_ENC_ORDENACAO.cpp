#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define b 10
#define d 4
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
typedef NODO * LISTA_ENC;
void cria_lista(LISTA_ENC *pl)
 {
 	*pl=NULL;
 }
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
int tam(LISTA_ENC l)
 {
 	int i;
 	for(i=0;l!=NULL;i++)
 	{
 		l=l->prox;
	}
	
 	return i;
 }
 int vazia_l(LISTA_ENC l)
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
 int recup_l(LISTA_ENC l, int k)
 {  
  int i;
   if(k<1||k>tam(l))
   {
   	printf("\n ERRO NA CONSULTA");exit(3);
   }
   else
   {
   	for(i==0;i<k-1;i++)
   	l=l->prox;
   	return(l->inf);
   }
 	
 }
 void ret_l(LISTA_ENC *pl, int k)
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
			*pl=aux->prox; 
			free(aux);		
		}
		else
		{
			NODO *aux2;
			for(aux=*pl;k<2;k--,aux=aux->prox);
			aux2=aux->prox;
			aux->prox=aux2->prox;
			free(aux2);
		}
	}
 	
 }
 void ins_l(LISTA_ENC *pl,int v, int k)
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
				novo->prox=*pl;
				*pl=novo;
			}
			else
			{
				LISTA_ENC aux;
				for(aux=*pl,i=0;i<k-2;aux=aux->prox,i++);
				novo->prox=aux->prox;
				aux->prox=novo;
			}
		}
	}
 	
 	
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
int recup(FILA_ENC l, int k)
 {  
  int i;
   
   
   	for(i==0;i<k-1;i++)
   	l->INICIO=l->INICIO->prox;   
   	return(l->INICIO->inf);
   
 	
 }

void ord_por_dist(LISTA_ENC *pl)
{
	int c1,c2;
	FILA_ENC vf[b];
	for(c2=0;c2<b;c2++)
	{
		criar(&vf[c2]);
	}
	for(c1=0;c1<d;c1++)
	{
		while(!vazia_l(*pl))
		{
			int v=recup_l(*pl,1),i;
			i=(v/(int)pow(b,c1))%b;
			ins(vf[i],v);
			ret_l(pl,1);
		}
		for(c2=0;c2<b;c2++)
		{
			while(!eh_vazia(vf[c2]))
			{
				ins_l(pl,cons_ret(vf[c2]),tam(*pl)+1);
			}
		}
	}
}

void imprimirl(LISTA_ENC *l)
 {
 	int i;
 	LISTA_ENC aux;
 	printf("\n==============LISTA===============");
 	for(aux=*l;aux!=NULL;aux=aux->prox)
 	{
 		printf("\n LISTA=%d  \n",aux->inf);
 		
	 }
 	
 }

  
int main()
{
	LISTA_ENC l;
	cria_lista(&l);
	ins_l(&l,194,1);
	ins_l(&l,131,2);
	ins_l(&l,053,3);
	ins_l(&l,273,4);
	ins_l(&l,013,4);
	ins_l(&l,261,4);
	ins_l(&l,313,4);
	ins_l(&l,216,4);
	ins_l(&l,102,4);
	ins_l(&l,39,4);
	ins_l(&l,11,4);
	ins_l(&l,21,4);
	ins_l(&l,360,4);
	ins_l(&l,07,4);
	imprimirl(&l);
	ord_por_dist(&l);
	imprimirl(&l);
	

}
