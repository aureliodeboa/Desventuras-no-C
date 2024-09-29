#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define b 10
#define d 4
typedef struct 
{
	char data[12],pais[50];
	int dia,mes,ano,casos,mortes;
	
	
}INF;
typedef struct nodo
{
	INF inf;
	struct nodo *ant;
	struct nodo *prox;
}NODO;
typedef struct node
{
	INF inf;
	struct node *prox;
}NODE;
typedef  struct 
{
	NODE *INICIO;
	NODE *FIM;
	
}DESCRITOR;
typedef DESCRITOR *FILA_ENC;

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
void criarf(FILA_ENC *pf )
{
	*pf=(DESCRITOR*)malloc(sizeof(DESCRITOR));
	if(!*pf)
	{
		printf("ERRO NO MALLOC!!");exit(1);
	}
	(*pf)->INICIO=NULL;
	(*pf)->FIM=NULL;
	
}
int eh_vaziaf(FILA_ENC f)
{
	return(f->INICIO==NULL);
}
void insf(FILA_ENC f,INF v)
{
	NODE *novo;
	novo=(NODE*)malloc(sizeof(NODE));
	if(!novo)
	{
		printf("ERRO NO MALLOC!!");exit(2);
		
	}
	else
	{
		novo->inf=v;
		novo->prox=NULL;
		if(eh_vaziaf(f))
		{
			f->INICIO=novo;
		}
		else
		{
			f->FIM->prox=novo;
			
		}
		f->FIM=novo;
	}
}
INF consf(FILA_ENC f)
{
	if(eh_vaziaf(f))
	{
		printf("A FILA ESTA VAZIA");exit(3);
	}
	else
	{
		return(f->INICIO->inf);
	}
}
INF cons_ret(FILA_ENC f)
{
	 if(eh_vaziaf(f))
	 {
	 	printf("WE HAVE A PROBLEM, THIS LIS IS EMPTY");exit(5);
	 }
	 else
	 {
	 	NODE *aux=f->INICIO;
	 	INF i=f->INICIO->inf;
	 	f->INICIO=f->INICIO->prox;
	 	free(aux);
	 	
	 	if(!f->INICIO)
	 	{
	 		f->FIM=NULL;	
		}
		return(i);
	 }
}
void destruirf(FILA_ENC f)
{
	
	NODE *aux;
	while(f->INICIO)
	{
		aux=f->INICIO;
		f->INICIO=f->INICIO->prox;
		free(aux);
		
	}
	free(f);
	
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
INF  recup(LCOVID l ,int k)
{
	int i;
	if(k<1||k>tam(l))
	{
		printf("POSICION INVALIDE");
	}
	for(;k>1;k--,l=l->prox);
	return (l->inf);
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
void destruir(LCOVID l)
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
void abrir(LCOVID *l,char *pais) //funcao cria uma lista com o pais desejado
{
	FILE *arq;
	INF inf;
	arq=fopen("bancoat.txt","r");
	if(arq==NULL)
	{
		printf("PROBLEMA AO ABRIR O ARQUIVO!! (1) \n");exit(1);
		
	}
	else
	{
	    char s[320],*token=NULL;
	    int c = 1;
	    criar(l);
		
		while(!feof(arq))
		{
			//printf("\n========================================================\n");
			fgets(s,320,arq);
			token=strtok(s,",");
	     	strcpy(inf.data,token);
   			//printf("\nDATA=%s",token);
			
			token=strtok(NULL,",");
			//printf("\nDIA=%s",token);
			inf.dia=atoi(token);
			
			token=strtok(NULL,",");
			//printf("\nMES=%s",token);
			inf.mes=atoi(token);	
				
			token=strtok(NULL,",");
			//printf("\nANO=%s",token);
			inf.ano=atoi(token);
			
			token=strtok(NULL,",");
		    //printf("\nCASOS=%s",token);
			inf.casos=atoi(token);
		
		
			token=strtok(NULL,",");
			//printf("\nMORTES=%s",token);
			inf.mortes=atoi(token);
			
			token=strtok(NULL,",");
			//printf("\nPAIS=%s",token);
			strcpy(inf.pais,token);
			
			if(!strcmp(pais,inf.pais))
			{
				ins(l,inf,c);
				c++;    
			}
			continue;
			
		}
		
	}
	
}
long int totcasos(LCOVID l)
{
  long int i=0; //LCOVID aux=l;
  while(l)
  {
     i+=l->inf.casos;
	l=l->prox;	
  }	
  return i;
}

int totmortes (LCOVID l){
	int t = 0;
	while(l){
		t += l->inf.mortes;
		l = l->prox;
	}
	return t;
}


void ord_por_mes(LCOVID *pl)
{
	ord_por_dia(pl);
	int c1,c2;
	FILA_ENC vf[b];
	for(c2=0;c2<b;c2++)
	{
		criarf(&vf[c2]);
	}
	for(c1=0;c1<d;c1++)
	{
		while(!eh_vazia(*pl))
		{
			INF v=recup(*pl,1);
			int i;
			i=(v.mes/(int)pow(b,c1))%b;
			insf(vf[i],v);
			ret(pl,1);
		}
		for(c2=0;c2<b;c2++)
		{
			while(!eh_vaziaf(vf[c2]))
			{
				ins(pl,cons_ret(vf[c2]),tam(*pl)+1);
			}
		}
	}
}

void ord_por_dia(LCOVID *pl)
{
	int c1,c2;
	FILA_ENC vf[b];
	for(c2=0;c2<b;c2++)
	{
		criarf(&vf[c2]);
	}
	for(c1=0;c1<d;c1++)
	{
		while(!eh_vazia(*pl))
		{
			INF v=recup(*pl,1);
			int i;
			i=(v.dia/(int)pow(b,c1))%b;
			insf(vf[i],v);
			ret(pl,1);
		}
		for(c2=0;c2<b;c2++)
		{
			while(!eh_vaziaf(vf[c2]))
			{
				ins(pl,cons_ret(vf[c2]),tam(*pl)+1);
			}
		}
	}
}

void totalperiodo(LCOVID l,int m1,int m2) //total de casos por periodo
{
	LCOVID l1;
	int k=1;
	criar(&l1);
	while(l)
	{
		if((l->inf.mes>=m1)&&(l->inf.mes<=m2))
		{
			ins(&l1,l->inf,k);
			k++;
		}
		l=l->prox;
	}
	//imprimir(l1);
   //	printf("\n TOTAL DE CASOS DO MES %d ATE O MES %d = %d \n",m1,m2,totcasos(l1));
}
void media_movel (LCOVID l){
	float s = 0.0;
	int c = 1,sem = 48;
	while(l != NULL){
		if(c==8){
			printf("\n%d semana: %.4f",sem,s/7);
			c=1;	
			sem--;
			s = 0.0;
		}
		s += l->inf.casos;
		c++;
		l = l->prox;
	}
}

void taxa_mortalidade (LCOVID l){
	
	int hab;
	float tot;
	if(strcmp(l->inf.pais,"Afghanistan") == 0){
		hab = 37170000;
	}
	else if (strcmp(l->inf.pais,"Albania") == 0){
		hab = 2846000;
	}
	else if (strcmp(l->inf.pais,"Italy") == 0){
		hab = 60360000;
	}
	
	tot = (float)totmortes(l)/hab;
	printf("\nTaxa de mortalidade de %s = %.2f mortes por milhao de pessoas",l->inf.pais,tot*1000000);
}


int main()
{
	LCOVID l1,l2,l3;
	char s1[]="Afghanistan",s2[]="Albania",s3[]="Italy";
	
    abrir(&l3,s2);
    //ord_por_mes(&l3);
	//imprimir(l3);
	//taxa_mortalidade(l3);
	//totalperiodo(l3,1,3);
    printf("TOTAL DE CASOS  %s = %ld\n",l3->inf.pais,totcasos(l3));
}

