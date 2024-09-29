#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct 
{
	float inf;
	int next;
	
}NODO;
typedef struct
{
	int ind_pri_ele;
	int ind_nodo_livre;
	NODO elementos[MAX];
}LISTAENC
void criar(LISTAENC *l)
{
	int i=0;
	l->ind_pri_ele=-1;
	l->ind_nodo_livre=0;
	
		for(i=0;i<MAX-1;i++)
		{
			l->elementos[i].next=i+1;
		}
		l->elementos[i].next=-1;
		
}
int vazia(LISTAENC *l)
{
	return(l->ind_pri_ele==-1);	
}
int tam (LISTAENC *l) 
{ int cont=0, ind=l->ind_pri_ele;
		while (ind!=-1) 
		{
		 cont++; ind = l->elementos[ind].next;
		} return cont;
 }
