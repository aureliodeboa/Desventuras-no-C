#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
typedef struct node{
    char inf;
    struct node *next;
}NODO;

typedef struct nodenc{
    int inf;
    NODO *next;
}NODONC;

typedef NODONC *List;
char str[max];

List strcnvcl(List l,char *string){
    int i;
    98
    for(i=0;i<max-1;i++){
        ins(l,string[i],i+1);
    }
}
void ins(List l,char v, int k){
    NODO novo,aux;
    int i=k;
    if(k<1||k>l->inf+1){
        print("Posicao invalida para insercao");
        exit(2);
    }
    novo=(NODO ) malloc(sizeof(NODO));
    if(!novo){
        printf("Erro na alocacao para insercao");
        exit(3);
    }
    novo->inf=v;
    /*nas lista de NC eu so tenho que me preocupar com uma situação
    na inserção,que é percorrer a lista até o elemento que antecede a posição*/
    for(aux=l;i>1;aux=aux->next,i--);
    novo->next=aux->next;
    aux->next=novo;
    l->inf++;
}
int main()
{
	char string[10]="VALOR";
	List l;
	strcnvcl(&l,str);
		
}
