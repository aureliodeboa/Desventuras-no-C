#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct 
{
	int TOPO;
	int val[MAX];
}PILHA_SEQ;
void criar(PILHA_SEQ *p)
{
	p->TOPO=-1; //POIS AO INCREMENTAR TEREMOS O VALOR 0
}
 int eh_vazia(PILHA_SEQ *p)
 {
 	return(p->TOPO==-1);
 }
void push(PILHA_SEQ *p,int v)
{
	if(p->TOPO==MAX-1)
	{
		printf("ESTOURO NA PILHA");exit(1);
	}
	p->TOPO++;
	p->val[p->TOPO]=v;
  
}  
int top(PILHA_SEQ *p)
{
	if(p->TOPO==-1)
	{
		printf("PILHA VAZADA(VAZIA)");exit(2);
	}
	else
	{
		return(p->val[p->TOPO]);
	}
}
void pop(PILHA_SEQ *p)
{
	if(p->TOPO==-1)
	{
		printf("PILHA VAZADA(VAZIA)");exit(2);
	}
	else
	{
		p->TOPO--;
	}
}
int top_pop(PILHA_SEQ *p)
{
	if(p->TOPO==-1)
	{
		printf("PILHA VAZADA(VAZIA)");exit(2);
	}
	else
	{
		int i=p->val[p->TOPO];
		p->TOPO--;
		return(i);
	}
}
void imprimir(PILHA_SEQ *p)
{
	int i;
	for(i=p->TOPO;i>-1;i--)
	{
		printf("PILHA[%d]=%d \n",i,p->val[i]);
	}
}

int main( )
{
	PILHA_SEQ  p;
	criar(&p);
	push(&p,1);
	push(&p,2);
	push(&p,3);
	push(&p,4);
	//pop(&p);
	imprimir(&p);
	printf("\nTOP =%d \n",top(&p));
}

