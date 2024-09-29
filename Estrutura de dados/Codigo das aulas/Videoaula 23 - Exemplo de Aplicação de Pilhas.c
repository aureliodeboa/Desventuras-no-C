#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAXCOLS 80
typedef struct nodo
{
	int inf;
	struct nodo *next;
	
}NODE;
typedef NODE *PILHA_ENC;
 
void create(PILHA_ENC *pp)
{
	(*pp)=NULL;
}
int is_empty(PILHA_ENC p)
{
	return(p==NULL);
}
void push(PILHA_ENC *pp,int v)
{
	NODE *novo;
	novo=(PILHA_ENC)malloc(sizeof(NODE));
	
	if(!novo)
	{
		printf("ERRO NO MALLOC \n");exit(1);
	}
	else
	{
		novo->inf=v;
		novo->next=*pp;
		*pp=novo;
		
	}
}
int top(PILHA_ENC p)
{
	if(!p)
	{
		printf("LISTA VAZIA");exit(2);
	}
	return(p->inf);
}
void pop(PILHA_ENC *pp)
{
	if(!pp)
	{
		printf("LISTA VAZIA");exit(3);
	}
	else
	{
		NODE *aux=*pp;
		(*pp)=(*pp)->next;
		free(aux);
	}
}
int top_pop(PILHA_ENC *pp)
{
		if(!pp)
	{
		printf("LISTA VAZIA");exit(4);
	}
	else
	{
		NODE *aux=*pp;
		int i=(*pp)->inf;
		*pp=(*pp)->next;
		free(aux);
		return(i);
	}
}
void destroy(PILHA_ENC p)
{
	NODE *aux;
	while(p)
	{
		aux=p;
		p=p->next;
		free(aux);
	}
}
int eh_operando(char op)
{
	return(op!='+' && op!='-' && op!='*' && op!='/' && op!='^');
}
int aplicar(int operando1 ,char operador, int operando2)
{
	switch(operador)
	{
		case '+':return(operando1+operando2);
		
		case '-':return(operando1-operando2);
				
		case '*':return(operando1*operando2);
		
		case '/':return(operando1/operando2);
		
		case '^':return((int)pow(operando1,operando2));
					
	}
		
	
}
int avaliar(char *e)
{
	char symbol;
	int i=0;
	PILHA_ENC pilha_operandos;
	create(&pilha_operandos);
	while(symbol=e[i++])
	{
		if(eh_operando(symbol))
		{
			push(&pilha_operandos,symbol-'0');	
		}
		else
		{
			int op2=top_pop(&pilha_operandos),op1=top_pop(&pilha_operandos);
			push(&pilha_operandos,aplicar(op1,symbol,op2));
		}
		
	}
	return(top_pop(&pilha_operandos));
	
}
int prcd(char op1,char op2)
{
	if((op1=='+'||op1=='-')&&(op2=='+'||op2=='-'))
		return (1);
	if((op1=='*'||op1=='/')&&(op2=='+'||op2=='-'||op1=='*'||op1=='/'))
		return (1);		
	if((op1=='^')&&(op2=='^'||op2=='-'||op1=='+'||op1=='/'||op1=='*'))
		return (1);
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		return(0);
	
}
void converter_s_p(char *o,char *d )
{
	char symbol;
	int i1=0,i2=0;
	PILHA_ENC opstk;
	create(&opstk);
	while(symbol=o[i1++])
	{
		if(eh_operando(symbol))
		d[i2++]=symbol;
		else{
			while(!is_empty(opstk)&&prcd(top(opstk),symbol))
			d[i2++]=top_pop(&opstk);
			push(&opstk,symbol);
		}
		while(!is_empty(opstk))
		d[i2++]=top_pop(&opstk);
	d[i2]='\0';	
	}
}


int main()
{
	char expr[MAXCOLS],s[MAXCOLS];
	int position=0;
	while((expr[position++]=getchar())!='\n');
	expr[--position]='\0';
  	printf("%s%s,a espressao original ehh",expr);
  	//
  	converter_s_p(expr,s);
  	printf(" \na FINAL EH =%d \n",s);
  	printf("=%d\n",avaliar(expr));
  	return 0;
}















