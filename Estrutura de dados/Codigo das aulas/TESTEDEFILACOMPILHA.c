#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct 
{
	int N;
	int FIM;
	int INICIO;
	int val[MAX];
	
}FILA_SEQ;
typedef struct 
{
	int TOPO;
	int val[MAX];
}PILHA_SEQ;
void criar_PILHA(PILHA_SEQ *p)
{
	p->TOPO=-1; //POIS AO INCREMENTAR TEREMOS O VALOR 0
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
void criar(FILA_SEQ *f)
{
		f->N=0;
		f->FIM=-1;
		f->INICIO=0;
		
		
}
int eh_vazia(FILA_SEQ *f)
{
	return(f->N==0);
}
int tam(FILA_SEQ *f)
{
	return(f->N);
}
void ins (FILA_SEQ *f,int v)
{
	if(f->N==MAX)
	{
		printf("ESTOURO NA FILA\n");
		exit(1);
	}
	f->FIM=(f->FIM+1)%MAX; //caso nao se trate do primeiro indice(0) como ultimo valor, atribui-se o valor do indice +1
	f->val[f->FIM]=v;  //atribuiçao do valor ao vetor no indice +1;
	f->N++;// incremento do tamanho
	 
}
int cons(FILA_SEQ *f)
{
	if(eh_vazia(f))
	{
		printf("LISTA EH VAZIA \n"); exit(2);
		
	}
	else
	{
		return (f->val[f->INICIO]);
	}
}
void ret (FILA_SEQ *f)
{
	if(eh_vazia(f))
	{
		printf("FILA EH VAZIA!!!");exit(3);
	}
	else
	{
		f->INICIO=(f->INICIO+1)%MAX;
		f->N--;
	}
}
int cons_ret(FILA_SEQ *f)
{
	if(eh_vazia(f))
	{
		printf("FILA EH VAZIA!!!");exit(4);
	}
	else
	{
		int i=f->val[f->INICIO];
		f->INICIO=(f->INICIO+1)%MAX;
		f->N--;
		return (i);
	}
}
void imprimir(FILA_SEQ *f)
{
	int i;
	for(i=f->INICIO;i<=f->FIM;i++)
	{
		printf("FILA[%d]=%d\n",i,f->val[i]);
		
	}
}
void gera_fila(FILA_SEQ *f, int m, int n)
{
	if(m>n)
	{
		printf("INTERVALO INVALIDO");exit(6);
	}
	else
	{
		if(m==n)
		{
			criar(f);
			ins(f,m);
		}
		else
		{
			gera_fila(f,m,n-1);
			ins(f,n);
			
		
		
		}
	}
	
}
void inverte_fila(FILA_SEQ *f)
{
	PILHA_SEQ p;
	criar_PILHA(&p);
	while(!eh_vazia(f))
	{
	 push(&p,cons_ret(f));	
	}
	
	while(p.TOPO!=-1)
	{
		ins(f,top_pop(&p));
	}
	
}
int main()
{
	FILA_SEQ f;
	//criar(&f);
	gera_fila(&f,1,10);
	/*ins(&f,1);
	ins(&f,2);
	ins(&f,3);
	ins(&f,4);
	ins(&f,5);
	//ret(&f);
 	//ins(&f,1);*/
    
	imprimir(&f);
	printf("\n==========================\n");
	inverte_fila(&f);
	imprimir(&f);
	//printf("\nFIM = %d \n",f.FIM);
   
	
	
	
	
	
	
}
