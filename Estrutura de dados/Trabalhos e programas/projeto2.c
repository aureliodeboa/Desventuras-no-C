#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
	int dia,mes,ano,casos,mortes;
	char data[11],pais[50];
	
}INF;

typedef struct nodo
{
	INF inf;
	struct nodo *ant;
	struct nodo *prox;
}NODO;

typedef NODO *LCOVID;

void criar(LCOVID *pl)
{
	*pl=NULL;
	
}

int eh_vazia(LCOVID l)
{
	return (l==NULL);
}

int tam(LCOVID l)
{
	
	int i;
	for(l,i=0;l;l=l->prox,i++);
	return i;
}

void ins(LCOVID *pl, INF inf,int k)
{
	if(k<1||k>tam(*pl)+1)
	{
		printf("POSICAO INVALIDA");exit(1);
	}
	else
	{
			LCOVID novo;
			novo=(NODO*)malloc(sizeof(NODO));
			novo->inf=inf;
			if(novo)
			{
				if(eh_vazia(*pl))
				{
					*pl=novo;
					novo->ant=NULL;
					novo->prox=NULL;
					
				}
				else
				{
					if(k==1)
					{
						novo->prox=*pl;
						(*pl)->ant=novo;
						novo->ant=NULL;
						*pl=novo;
						
						
					}
					else
					{
						NODO *aux;
						if(k==tam(*pl)+1)
						{
							novo->prox=NULL;
							for(aux=*pl;aux->prox!=NULL;aux=aux->prox);
							novo->ant=aux;
							novo->prox=aux->prox;
							aux->prox=novo;
							
											
						}
						else
						{
							int i;
							for(i=2,aux=*pl;i!=k;aux=aux->prox,i++);
							novo->ant=aux;
							novo->prox=aux->prox;
							aux->prox=novo;
							novo->prox->ant=novo;
							
							
						}
					}
				}
			}
			else
			{
				printf("NAO FOI POSSIVEL ALOCAR MEMORIA!!");exit(4);
			}
		
		
	}
}

int recup(LCOVID l ,int k)
{
	int i;
	if(k<1||k>tam(l))
	{
		printf("POSICION INVALIDE");
	}
	for(;k>1;k--,l=l->prox);
	return l->inf.pais;
}

int ret(LCOVID *pl,int k)
{
	NODO *aux;
	
	if(k<1||k>tam(*pl))
	{
		printf("VALOR INVALIDO");exit(6);
	}
		
	if(k==1) //SITUAÇAO 1
	{
		aux=*pl;
		*pl=aux->prox;
		if(*pl)//SITUAÇAO DOIS
		{
			(*pl)->ant=NULL;
				
		}	
		free(aux);
	}
	else //SITUAÇAO 3 e 4
	{
		for(aux=(*pl)->prox;k>2;k--,aux=aux->prox); //saio do for contendo em aux o endereço que eu quero remover
			aux->ant->prox=aux->prox;
			if(aux->prox)
			{
				aux->prox->ant=aux->ant;
			}
			free(aux);
	}
}

int destruir(LCOVID l)
{
	NODO *aux;
	while(l)
	{
		aux=l;
		l=l->prox;
		free(aux);
	}
}

void imprimir(LCOVID l)
{
		
	while(l)
	{   
	printf("\n--------------------------------------\n");
		printf("\nPAIS= %s",l->inf.pais);
		printf("\nCASOS= %d",l->inf.casos);
		printf("\nMORTES= %d",l->inf.mortes);
		printf("\nDATA= %s",l->inf.data);
    printf("\n--------------------------------------\n");	
    l=l->prox;
	
	
}
}


void abrir(LCOVID *l)
{
	FILE *arq;
	INF inf;
	arq=fopen("banco2.txt","r");
	if(arq==NULL)
	{
		printf("PROBLEMA AO ABRIR O ARQUIVO!! (1) \n");exit(1);
		
	}
	else
	{
	    char s[120],*token=NULL;
	    int c = 1;
		
		while(!feof(arq))
		{
			printf("\n========================================================\n");
			fgets(s,120,arq);
			
			token=strtok(s,",");
	
   			
   			
   			strcpy(inf.data,token);
   			//ESSA PRAGA DOS INFERNOS, PESTE BUBÔNICA, DESGRAÇAAAA NÃO VAI PORQUEEEEEEEEEEEEE??????????????????????
			printf("\nDATA=%s",token);
			
			
			token=strtok(NULL,",");
			printf("\nDIA=%s",token);
			inf.dia=token;
			
			
			token=strtok(NULL,",");
			printf("\nMES=%s",token);
			inf.mes=atoi(token);	
				
			token=strtok(NULL,",");
			printf("\nANO=%s",token);
			inf.ano=atoi(token);
			
			token=strtok(NULL,",");
		    printf("\nCASOS=%s",token);
			inf.casos=atoi(token);
		
		
			token=strtok(NULL,",");
			printf("\nMORTES=%s",token);
			inf.mortes=atoi(token);
			
			token=strtok(NULL,",");
			printf("\nPAIS=%s",token);
			strcpy(inf.pais,token);
			/*if(!strcmp("Italy",inf.pais))
			{
				ins(l,inf,c);
				c++;    
			}
			continue;
			*/
		}
		
	}
	
}

int main()
{
	LCOVID l;
	criar(&l);
	abrir(&l);
	imprimir(l);
}

