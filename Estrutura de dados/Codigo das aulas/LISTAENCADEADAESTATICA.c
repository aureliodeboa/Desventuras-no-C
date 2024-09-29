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
	int ind_livre;
	NODO elementos[MAX]; 
	
}LISTAEN;

void criar(LISTAEN *l)
{
	int i;
	for(i=0;i<MAX-1;i++)
	{
		l->elementos[i].next=i+1;
	}
	 l->elementos[i].next=-1;
	 l->ind_pri_ele=-1;
	 l->ind_livre=0;
}
int vazia(LISTAEN *l) //RETORNA VERDADEIRO SE FOR VAZIA
{
	return(l->ind_pri_ele==-1);
}
int tam(LISTAEN *l)
{
	int i,cont=0;
	i=l->ind_pri_ele;
	
	while(i!=-1)
	{
			cont++;
			i=l->elementos[i].next;
	}
	return cont;
	 
	
	
	
}
void inserir(LISTAEN *l, int pos,float inf)
{
	int i,aux1,aux2;
	if(pos<1||pos>MAX)
	{
		printf("POSICAO INVALIDA!!! EXIT (1)");
		exit(1);
	}
	else
	{
		if(l->ind_livre==-1)
		{
			printf("DONT HAVE SPACE IN MEMORY I'M BI LINGUE");
			exit(2);
		}
		else
		{
			if(pos==1)
			{    
			    
				l->elementos[l->ind_livre].inf=inf; //armazenando o valor no nodo livre
			    aux1=l->elementos[l->ind_livre].next; //o novo indice livre
			    l->elementos[l->ind_livre].next=l->ind_pri_ele; //colocando o indice do antigo primeiro valor 
			    l->ind_pri_ele=l->ind_livre;
				l->ind_livre=aux1; //o primeiro elemento agora é o antigo livre, o livre agora é o next livre
				 
				 /*
				 l->elementos[l->ind_livre].inf=inf;
				 aux1=l->elementos[l->ind_livre].next;
				 l->elementos[l->ind_livre].next=l->ind_pri_ele;
				 l->ind_pri_ele=l->ind_livre;l->ind_livre=aux1; //ISSO LINDER QUE FEZ 
			 */
			}
			else
			{
				for(i=l->ind_pri_ele;i!=pos-2;i=l->elementos[i].next); //MANO -1 PQ O LOCAL é DE 1 a 100, E -1 de novo PORQUE É O VALOR ANTERIOR QUE VOCE QUER
				       //printf("\t %d",i);
				    aux1=l->elementos[l->ind_livre].next;
				 	l->elementos[l->ind_livre].inf=inf;
				 	l->elementos[l->ind_livre].next=l->elementos[i].next;
				 	l->elementos[i].next=l->ind_livre;
				 	l->ind_livre=aux1;
				 	
				
				
				/*for(i=l->ind_pri_ele;--pos-1;i=l->elementos[i].next);
				 	l->elementos[l->ind_livre].inf=inf;
				 	aux1=l->elementos[l->ind_livre].next;
				 	l->elementos[l->ind_livre].next=l->elementos[i].next;
				 	l->elementos[i].next=l->ind_livre;
				 	l->ind_livre=aux1;   //linder QUE FEZ
				*/
			}
			
		}
	}
}
void imprimir(LISTAEN *l)
{
	int i,aux;
	for(i=l->ind_pri_ele;i!=-1;i=l->elementos[i].next)
	{
		printf("\n| POSICAO [%d]= %.2f (next %d)|",i,l->elementos[i].inf,l->elementos[i].next);
	}
	
}
float recuperar(LISTAEN *l,int k)
{
	int i;
	if(k<1||k>tam(l)-1)
	{
		printf("POSIÇAO INVALIDA, PARCEIRO");exit(3);
	}
	else{
		for(i=l->ind_pri_ele;i<k;i=l->elementos[i].next);
		
			return(l->elementos[i].inf);		
	}
}
void tirar(LISTAEN *l , int k)
{
	int i,j,aux;
	if(k<1||k>tam(l))
	{
		printf(" POSICAO DE REMOCAO INVALIDA");
	}
	else
	{
		if(k==1)
		{
			aux= l->ind_pri_ele; //indice do antigo primeiro elemento
			l->ind_pri_ele=l->elementos[l->ind_pri_ele].next;//o indice do primeiro elemento agora é o next do antigo primeiro elemento
			l->elementos[aux].next=l->ind_livre; // o antigo primeiro elemento (livre), vai apontar pro primeiro ind livre anterior
		    l->ind_livre=aux;// o novo indice livre é o anigo primeiro elemento	  
			
			  			  
		}
		else
		{
			for(i=l->ind_pri_ele;i<k-2;i=l->elementos[i].next);
			  //j=l->ind_livre;
			  aux=l->elementos[i].next; //o indice do valor que eu quero excluir
			  l->elementos[i].next=l->elementos[aux].next; // fazendo com que o anterior aponte para onde o removido apontava
			  l->elementos[aux].next=l->ind_livre;
			  l->ind_livre=aux;
			 
			 
		}
	}
	
}

int main()
{
	LISTAEN l; int i;float j=0;

		criar(&l);
	 
	    for(i=1;i<=100;i++,j++)
	    {
	    	inserir(&l,i,j);
		} 
	    
	    imprimir(&l);
	    tirar(&l,2);
	    printf("\n TIRAR ====================================\n");
	    imprimir(&l);
	    inserir(&l,2,1);
	    printf("\n COLOCAR ====================================\n");
	    imprimir(&l);
	    
	    
	  
	
}
