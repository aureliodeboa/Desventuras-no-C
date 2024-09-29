#include<stdio.h>
#include<stdlib.h>
typedef struct  nodo
{
	int num,altd,alte;
	struct nodo *dir,*esq;
}NODO;
typedef  NODO *ArvoreAVL;

void rotacao_direita(ArvoreAVL *arvore)
{
	ArvoreAVL aux1,aux2;
	aux1=(*arvore)->esq;
	aux2=aux1->dir;
	(*arvore)->esq=aux2;
	aux1->dir=(*arvore);
	if((*arvore)->esq==NULL)
	 (*arvore)->alte=0;
	 else
	 	if((*arvore)->esq->alte > (*arvore)->esq->altd)
	 		(*arvore)->alte=(*arvore)->esq->alte+1;
	 	else
		 (*arvore)->alte=(*arvore)->esq->altd+1;
	if(aux1->dir->alte >aux1->dir->altd)
		aux1->altd=aux1->dir->alte+1;
	else
		aux1->altd=aux1->dir->altd+1;
	*arvore=aux1;		
}
void rotacao_esquerda(ArvoreAVL *arvore)
{
	ArvoreAVL aux1, aux2;
	aux1=(*arvore)->dir;
	aux2=aux1->esq;
	(*arvore)->dir=aux2;
	aux1->esq=(*arvore);
	if((*arvore)->dir==NULL)
		(*arvore)->altd=0;
	else
		if((*arvore)->dir->alte > (*arvore)->dir->altd)
			(*arvore)->altd= (*arvore)->dir->alte+1;
		else
			(*arvore)->altd=(*arvore)->dir->altd+1;
		if(aux1->esq->alte > aux1->esq->altd)
			aux1->alte=aux1->esq->alte +1;
		else
		  aux1->alte=aux1->esq->altd +1;
	*arvore=aux1;	  			
}
void balanceamento(ArvoreAVL *arvore)
{
	int FBpai,FBfilho;
	FBpai=(*arvore)->altd - (*arvore)->alte;
	if(FBpai==2){
		FBfilho=(*arvore)->dir->altd-(*arvore)->dir->alte;
		if(FBfilho>=0)
			rotacao_esquerda(arvore);
		else{
			rotacao_direita(&((*arvore)->dir));
			rotacao_esquerda(arvore);
		}	
	}else
		if(FBpai==-2){
			FBfilho=(*arvore)->esq->altd - (*arvore)->esq->alte;
			if(FBfilho<= 0)
				rotacao_direita(arvore);
			else{
				rotacao_esquerda(&((*arvore)->esq));
				rotacao_direita(arvore);
			}	
		}
}











