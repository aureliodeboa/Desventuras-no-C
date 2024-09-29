#include <stdio.h>
#include <stdlib.h>


typedef struct
{
int nl;
int nc;
int *elementos;
}MATRIZ;


void criar(int,int,MATRIZ*);
void ini(MATRIZ*);
void imprimir(MATRIZ*);
void soma(MATRIZ*,MATRIZ*,MATRIZ*);
void subtracao(MATRIZ*,MATRIZ*,MATRIZ*);
void subtracao(MATRIZ*,MATRIZ*,MATRIZ*);
void multiplicacao(MATRIZ*,MATRIZ*,MATRIZ*);


void criar(int nl,int nc,MATRIZ *m){
	m->elementos = (int *)malloc(nc*nl*sizeof(int));
	if(m->elementos == NULL){
		printf("\nNao foi possivel alocar!");
	}
	m->nc = nc;
	m->nl = nl;
}

void ini(MATRIZ *m){
	int i,j,k = 0;
	for(i=0;i<m->nl;i++){
		for(j=0;j<m->nc;j++){
			printf("\n[%d][%d] elemento: ",i+1,j+1);
			scanf("%d",&(m->elementos[k]));
			k++;
	}
}
}

void imprimir(MATRIZ *m){
	int i,j,k = 0;
	for(i=0;i<m->nl;i++){
		printf("\n");
		for(j=0;j<m->nc;j++){
			printf("%02d ",m->elementos[k]);
			k++;
	}
}
}

void soma(MATRIZ *a,MATRIZ *b,MATRIZ *c){
	if((a->nc == b->nc) && (a->nl == b->nl)){
		int i;
		criar(a->nl,a->nc,c);
		for(i=0;i<a->nc*a->nl;i++){
			c->elementos[i] = a->elementos[i] + b->elementos[i];
		}
		
	}
	else{
		printf("\nNao eh possivel fazer a soma!");
	}
}

void subtracao(MATRIZ *a,MATRIZ *b,MATRIZ *c){
	if((a->nc == b->nc) && (a->nl == b->nl)){
		int i;
		criar(a->nl,a->nc,c);
		for(i=0;i<a->nc*a->nl;i++){
			c->elementos[i] = a->elementos[i] - b->elementos[i];
		}
		
	}
	else{
		printf("\n\nNao eh possivel fazer a subtracao!");
	}
}

void multiplicacao(MATRIZ *a,MATRIZ *b,MATRIZ *c){

 if(a->nl==b->nc)
 {  
   criar(a->nl,b->nc,c);
   
   	int i,j,z,x,ija=0,ijb=0;
   	 
  	for(i=0;i<a->nl;i++,ija++)
  	{    
  		for(j=0;j<b->nc;j++,ijb++)
		  {
		  	
		  	 c->elementos[z]=0;
		  		for(z=0;z<b->nl;z++)
				  {   
				    for(x=0;x<a->nc;x++)
				    {
				    	c->elementos[z]+=(a->elementos[x]*b->elementos[x]);
					}
				  		
				  }	
				 
		  }	
	}
 }
 else
 {
 	printf("NAO FOI POSSIVEL MULTIPLICAR,DEVIDO INCOMPATIBILIDADE DAS MATRIZES");
 }
}


int main(){
	MATRIZ a,b,c;
	printf("\n\nMATRIZ 1");
	printf("\nNumero de linhas: ");
	scanf("%d",&(a.nl));
	printf("Numero de colunas: ");
	scanf("%d",&(a.nc));
	criar(a.nl,a.nc,&a);
	ini(&a);
	printf("\n\nMATRIZ 2");
	printf("\nNumero de linhas: ");
	scanf("%d",&(b.nl));
	printf("Numero de colunas: ");
	scanf("%d",&(b.nc));
	criar(b.nl,b.nc,&b);
	ini(&b);
	printf("\n\nMatriz 1: ");
	imprimir(&a);
	printf("\n\nMatriz 2: ");
	imprimir(&b);
	printf("\n\nSoma: ");
	soma(&a,&b,&c);
	imprimir(&c);
	printf("\n\nSubtracao: ");
	subtracao(&a,&b,&c);
	imprimir(&c);
	printf("\n\nMULTIPLICACAO: ");
	multiplicacao(&a,&b,&c);
	imprimir(&c);
	
}

