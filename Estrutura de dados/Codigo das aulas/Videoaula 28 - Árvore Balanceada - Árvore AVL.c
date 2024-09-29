#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node *father;
	struct node *left;
	struct node *right;

}NODE;
typedef NODE *ARV_BIN_ENC;
typedef NODE *ARV_BIN_BUSCA;
typedef struct nodo
{
	ARV_BIN_ENC arvore;
	struct nodo *prox;
}NODO;
typedef  struct 
{
	NODO *INICIO;
	NODO *FIM;
	int n;
	
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
	(*pf)->n=0;
}
int eh_vazia(FILA_ENC f)
{
	return(f->INICIO==NULL);
}
void ins(FILA_ENC f,ARV_BIN_ENC arvore)
{
	NODO *novo;
	novo=(NODO*)malloc(sizeof(NODO));
	if(!novo)
	{
		printf("ERRO NO MALLOC!!");exit(2);
		
	}
	else
	{
		novo->arvore=arvore;
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
		f->n++;
	}
}
ARV_BIN_ENC cons(FILA_ENC f)
{
	if(eh_vazia(f))
	{
		printf("A FILA ESTA VAZIA");exit(3);
	}
	else
	{
		return(f->INICIO->arvore);
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
		f->n--;
		free(aux);
	}
}
ARV_BIN_ENC cons_ret(FILA_ENC f)
{
	 if(eh_vazia(f))
	 {
	 	printf("WE HAVE A PROBLEM, THIS LIS IS EMPTY");exit(5);
	 }
	 else
	 {
	 	NODO *aux=f->INICIO;
	 	ARV_BIN_ENC i=f->INICIO->arvore;
	 	f->INICIO=f->INICIO->prox;
	 	free(aux);
	 	
	 	if(!f->INICIO)
	 	{
	 		f->FIM=NULL;	
		}
		f->n--;
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
int tam(FILA_ENC f)
{
	return (f->n);
}
/*void imprimir(FILA_ENC f)
{
	int i=0;
 	NODO *aux;
 	for(;f->INICIO;f->INICIO=f->INICIO->prox,i++)
 	{
 		printf("FILA[%d]=%d \n",i,info(cons(f->INICIO->arvore)));
	 }
}*/

void maketree(ARV_BIN_ENC *t, int x)
{
	*t=(ARV_BIN_ENC)malloc(sizeof(NODE));
	if(!(t))
	{
		printf("NAO POSSIVEL ALOCAR  A ARVORE NA MEMORIA");exit(1);
		
	}
	else
	{
		(*t)->info=x;
		(*t)->left=NULL;
		(*t)->right=NULL;
		(*t)->father=NULL;
	}
}
void setleft(ARV_BIN_ENC t,int x)
{
	t->left=(ARV_BIN_ENC)malloc(sizeof(NODE));
	if(!(t->left))
	{
		printf("NAO FOI POSSIBLE ALOCAR UM NOVO NODO (A ESQUERDA) NA MEMORIA!!");exit(2);
	}
	else
	{
		t->left->info=x;
		t->left->father=t;
		t->left->left=NULL;
		t->left->right=NULL;
		
	}
	
}
void setright(ARV_BIN_ENC t, int x)
{
	t->right=(ARV_BIN_ENC)malloc(sizeof(NODE));
	if(!(t->right))
	{
		printf("NAO FOI POSSIBLE ALICAR UM NOVO NODO (A DIREITA) NA MEMORIA");exit(3);
	}
	else
	{
		t->right->info=x;
		t->right->father=t;
		t->right->left=NULL;
		t->right->right=NULL;
	}
	
}
int info(ARV_BIN_ENC t)
{
	return(t->info);
}
ARV_BIN_ENC left(ARV_BIN_ENC t)
{
	return(t->left);
}
ARV_BIN_ENC right(ARV_BIN_ENC t)
{
	return(t->right);
}
ARV_BIN_ENC father(ARV_BIN_ENC t)
{
	return(t->father);
}
ARV_BIN_ENC brother(ARV_BIN_ENC t)
{
	if(t->father)
	 	if(isleft(t))
			return(t->father)->right;
		else
		return(t->father)->left;
	return NULL;			
}
 int isleft(ARV_BIN_ENC *t)
 {
 	  ARV_BIN_ENC q=(*t)->father;
 	 
	  if(!q)
		  return(0);
	  if(q->left==(*t))
	  	return(1);
	return(0);	     	 
 }
int isright(ARV_BIN_ENC *t)
{
	if((*t)->father)
	 return(!isleft(t));
	return (0); 
}
void precursorEmLargura(ARV_BIN_ENC arvore)
{
	FILA_ENC fila;
	criar(&fila);
	if(arvore)
	ins(fila,arvore);
	while(!eh_vazia(fila))
	{
		printf("%d ",info(cons(fila)));
		if(left(cons(fila)))
		 ins(fila,left(cons(fila)));
		if(right(cons(fila)))
		ins(fila,right(cons(fila)));
		ret(fila); 
	}
	
}
void precursoPreOrdem(ARV_BIN_ENC arvore)
{
	if(arvore)
	{
		printf("%d ",info(arvore));  /*V*/
		precursoPreOrdem(left(arvore)); /*L*/
		precursoPreOrdem(right(arvore)); /*R*/
	}
}
void precursoInOrdem(ARV_BIN_ENC arvore)
{
	if(arvore)
	{
	
		precursoInOrdem(left(arvore)); /*L*/
		printf("%d ",info(arvore));		/*V*/
		precursoInOrdem(right(arvore)); /*R*/
				
	}
}
void precursoPosOrdem(ARV_BIN_ENC arvore)
{
	if(arvore)
	{
		precursoPosOrdem(left(arvore)); /*L*/
		precursoPosOrdem(right(arvore)); /*R*/
		printf("%d ",info(arvore));     /*V*/
	}
}
void ins_ele(ARV_BIN_BUSCA *arv,int v)
{
	if(!(*arv))
	maketree(arv,v);
	else
	{
		ARV_BIN_BUSCA father= *arv;
		do
		{
			if(v<father->info)
			{
				if(father->left)
					father=father->left;
				else
				{
					setleft(father,v);
					break;	
				}	
			}
			else
			{
				if(father->right)
					father=father->right;
				else
				{
					setright(father,v);
					break;	
				}	
			}
		}while(1);
	}
}
void remocaoPorFusao(ARV_BIN_BUSCA *arvore)
{
	if(*arvore)
	{
		ARV_BIN_BUSCA tmp=*arvore;
		if(!((*arvore)->right)){
			if((*arvore)->left) (*arvore)->left->father=(*arvore)->father;
			*arvore=(*arvore)->left;
		}else
			if((*arvore)->left==NULL){
				(*arvore)->right->father=(*arvore)->father;
				*arvore=(*arvore)->right;
			}else{
				tmp=(*arvore)->left;
				while(tmp->right)
					tmp=tmp->right;
				tmp->right=(*arvore)->right;
				tmp->right->father=tmp;
				tmp=*arvore;
				*arvore=(*arvore)->left;
							
			}
		free(tmp);		
	}
}
void remocaoPorCopia(ARV_BIN_BUSCA *arvore)
{
	if(*arvore)
	{
		ARV_BIN_BUSCA tmp=*arvore;
		if(!((*arvore)->right)){
			if((*arvore)->left) (*arvore)->left->father=(*arvore)->father;
			*arvore=(*arvore)->left;
		}else
		if((*arvore)->left==NULL){
			(*arvore)->right->father=(*arvore)->father;
			*arvore=(*arvore)->right;
		}else{
			tmp=(*arvore)->right;
			while(tmp->left!=NULL)
				tmp=tmp->left;
			(*arvore)->info=tmp->info;
			if(tmp->father==*arvore){
				tmp->father->right=tmp->right;
				tmp->father->right->father=tmp->father;
				
			}else{
				tmp->father->left=tmp->right;
				tmp->father->left->father=tmp->father;
			}	
		}
	free(tmp);	
	}
}
void precursorEmLarguraColocacaoEmVetor(ARV_BIN_BUSCA arvore,int vetor[],int *num_elem)
{
		FILA_ENC fila;
		criar(&fila);
		if(arvore)
		{
			ins(fila,arvore);
			//num_elem=(int)malloc(sizeof(int));
			num_elem=0;
			vetor=NULL;
			
		}
		while(!eh_vazia(fila))
		{
			if(!(vetor=(int)realloc(vetor,(++(*num_elem))*sizeof(int)))) exit(1);
			vetor[(*num_elem)-1]=info(cons(fila));
			if(left(cons(fila)))
				ins(fila,left(cons(fila)));
			if(right(cons(fila)))
				ins(fila,right(cons(fila)));
			ret(fila);			
		}	
}	
int particionar(int v[],int ii,int is)
{
	int esq=ii,dir=is,pivo=v[ii];
	while(esq<dir)
	{
		while(v[esq]<=pivo)
		esq++;
		while(v[dir]>pivo)
			dir--;
		if(esq<dir){
			int temp;
			temp=v[esq];
			v[esq]=v[dir];
			v[dir]=temp;
		}
			
	}
	v[ii]=v[dir];
	v[dir]=pivo;
	return(dir);	
}	
void quicksort(int *v,int n)
{
	if(n>1)
	{
		int pont_part=particionar(v,0,n-1);
		quicksort(v,pont_part);
		quicksort(&v[pont_part+1],n-1-pont_part);
		}	
}
void balancearArvoreBinariaAux(ARV_BIN_BUSCA *arvore,int vetor[],int inicio,int fim)
{
	if(inicio<=fim)
	{
		int meio=(inicio+fim)/2;
		ins_ele(arvore,vetor[meio]);
		balancearArvoreBinariaAux(arvore,vetor,inicio,meio-1);
		balancearArvoreBinariaAux(arvore,vetor,meio+1,fim);
		
	}
		
		
}	
void balancearArvoreBinaria(ARV_BIN_BUSCA *arvore)
{
	int *vetor,num_elem;
	precursorEmLarguraColocacaoEmVetor(*arvore,vetor,&num_elem);
	quicksort(vetor,num_elem);
	while(*arvore)
		remocaoPorCopia(arvore);
	balancearArvoreBinariaAux(arvore,vetor,0,num_elem-1);
	free(vetor);	
}
int main()
{
	ARV_BIN_ENC t;
	ARV_BIN_BUSCA t1;
	int i=1;
	maketree(&t,13);
 	setleft(t,10);
 	setright(t,25);
 	setleft(t->left,2);
 	setright(t->left,12);
 	setright(t->right,31);
 	setleft(t->right,20);
 	setleft(t->right->right,29);
 	//===================================//
 	maketree(&t1,5);
 	ins_ele(&t1,1);
 	ins_ele(&t1,9);
 	ins_ele(&t1,8);
 	ins_ele(&t1,7);
 	ins_ele(&t1,0);
 	ins_ele(&t1,2);
 	ins_ele(&t1,3);
 	ins_ele(&t1,4);
 	ins_ele(&t1,6);
 	//remocaoPorFusao(&t);
 	//remocaoPorFusao(&t);
 	printf("\n T PERCURSO EM LARGURA = ");
 	precursorEmLargura(t);
 	printf("\n T PERCURSO EM PRE ORDEM = ");
 	precursoPreOrdem(t);
 	printf("\n T PERCURSO EM IN ORDEM = ");
 	precursoInOrdem(t);
 	printf("\n T PERCURSO EM POS ORDEM = ");
 	precursoPosOrdem(t);
 	//=====================//
 	printf("\n T1 PERCURSO EM LARGURA = ");
 	precursorEmLargura(t1);
 	printf("\n T1 PERCURSO EM PRE ORDEM = ");
 	precursoPreOrdem(t1);
 	printf("\n T1 PERCURSO EM IN ORDEM = ");
 	precursoInOrdem(t1);
 	printf("\n T1 PERCURSO EM POS ORDEM = ");
 	precursoPosOrdem(t1);
   // ===RODA O ALGOTITMO//
    balancearArvoreBinaria(&t1);
    printf("\n T1a PERCURSO EM LARGURA = ");
 	precursorEmLargura(t1);
 	printf("\n T1a PERCURSO EM PRE ORDEM = ");
 	precursoPreOrdem(t1);
 	printf("\n T1a PERCURSO EM IN ORDEM = ");
 	precursoInOrdem(t1);
 	printf("\n T1a PERCURSO EM POS ORDEM = ");
 	precursoPosOrdem(t1);
 	
 	
}









