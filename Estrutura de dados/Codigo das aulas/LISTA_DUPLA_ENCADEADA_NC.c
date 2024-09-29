#include<stdio.h>
#include<stdlib.h>
typedef struct nodo
{
	int inf;
	struct nodo *ant;
	struct nodo *prox;
}NODO;

typedef NODO *LISTA_CIR_DUP_ENC_NC
