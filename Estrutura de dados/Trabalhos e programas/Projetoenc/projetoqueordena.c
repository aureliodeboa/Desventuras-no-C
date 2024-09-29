#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define b 10
#define d 4
typedef struct 
{
	char data[12],pais[50];
	int dia,mes,ano,casos,mortes,tam;
	
	
}INF;
typedef struct nodo
{
	INF inf;
	
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
	*pl = (NODO *) malloc(sizeof(NODO));
	if(*pl == NULL){
		printf("\nMemoria insuficiente!");
		exit(1);
	}
	strcpy((*pl)->inf.pais,"pais");
	strcpy((*pl)->inf.data,"data");
	(*pl)->inf.casos = 0;
	(*pl)->inf.mortes = 0;
	(*pl)->inf.tam = 0;
	(*pl)->prox=NULL; 
	
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
			int i;
			novo=(NODO*)malloc(sizeof(NODO));
			novo->inf=inf;
		    if(!novo)
			{
				printf("ERRO NO MALLOC");exit(2);
			}
			else
			{
				if(k==1)
				{
				novo->prox=*pl;
				*pl=novo;
				}
				else
				{
					LCOVID aux;
					for(aux=*pl,i=0;i<k-2;aux=aux->prox,i++);
					novo->prox=aux->prox;
					aux->prox=novo;
				}
			}
			
				(*pl)->inf.tam++;
	            (*pl)->inf.casos += novo->inf.casos;
	            (*pl)->inf.mortes += novo->inf.mortes;
	            strcpy((*pl)->inf.pais,novo->inf.pais);
	            strcpy((*pl)->inf.data,novo->inf.data);	
		
		
	}
}
INF  recup(LCOVID l ,int k)
{
 
  int i;
   if(k<1||k>tam(l))
   {
   	printf("\n ERRO NA CONSULTA");exit(3);
   }
   else
   {
   	for(i==0;i<k-1;i++)
   	l=l->prox;
   	return(l->inf);
   }
}
void ret(LCOVID *pl,int k)
{
	
	
	NODO *aux;
 	if(k<1||k>tam(*pl))
 	{
 		printf("ERRO POSICA INVALIDA");exit(5);
	}
	else
	{
		if(k==1)
		{
			aux=*pl;
			*pl=aux->prox; 
			free(aux);		
		}
		else
		{
			NODO *aux2;
			for(aux=*pl;k<2;k--,aux=aux->prox);
			aux2=aux->prox;
			aux->prox=aux2->prox;
			free(aux2);
		}
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
/*void imprimir(LCOVID l)
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
	
}*/
void imprimir(LCOVID l)
{
	int in;
	
	LCOVID aux=l;
	
 	printf("\n-------------INFORMAÇOES GERAIS-------------------\n");
		printf("\nPAIS= %s",aux->inf.pais);
		printf("\nCASOS= %d",aux->inf.casos);
		printf("\nMORTES= %d",aux->inf.mortes);
    	printf("\n--------------------------------------\n");
    	
    	printf("DIGITE (1) SE DESEJAR VER TODAS AS NOTIFICAÇOES\n E (0) PARA VOLTAR AO MENU PRINCIPAL ");
    	scanf("%d",&in);
    	
    	if(in==1)
    	{
    		while(aux)
			{   
				printf("\n--------------------------------------\n");
				printf("\nPAIS= %s",aux->inf.pais);
				printf("\nCASOS= %d",aux->inf.casos);
				printf("\nMORTES= %d",aux->inf.mortes);
				printf("\nDATA= %s",aux->inf.data);
    			printf("\n--------------------------------------\n");	
    			aux = aux->prox;
			}
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
	    int c = 1,aux=0;
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
				aux++;
				ins(l,inf,c);
				c++;    
			}
			continue;
			
		}
		if(aux==0)
		{
			printf("ESSE PAIS NAO PERTENCE AO BANCO\n");exit(32);
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
int totalperiodomortes(LCOVID l,int m1,int m2) //total de casos por periodo
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

   return(totmortes(l1));
}
int totalperiodocasos(LCOVID l,int m1,int m2) //total de casos por periodo
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

   return(totcasos(l1));
}
void media_movel (LCOVID l){
	float s = 0.0;
	int c = 1,sem = 48;
	printf("MEDIA MOVEL %s\n",l->inf.pais);
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
void comparar_paises(LCOVID l1,LCOVID l2)
{
   int m1,m2;
   printf("Desde o mes?: \n ");
   scanf("%d",&m1);
   printf("Ate o mes ? :\n");
   scanf("%d",&m2);
   printf("Total de casos (%s) do perido = %d \n",l1->inf.pais,totalperiodocasos(l1, m1, m2));
   printf("Total de Mortes (%s) do perido = %d \n",l1->inf.pais,totalperiodomortes(l1, m1, m2));
   
   printf("Total de casos (%s) do perido = %d \n",l2->inf.pais,totalperiodocasos(l2, m1, m2));
   printf("Total de mortes (%s) do perido = %d \n",l2->inf.pais,totalperiodomortes(l2, m1, m2));
  getch();
   
}
int  menu()
{
	int op;
	system("cls");
	printf("\n====================MENU=============================\n");
	printf("\nCOMPARAR PAISES POR PERIODO (1)\n");
	printf("TODOS OS CASOS DE UM DETERMINADO PAIS ORDENADO (2)\n");
	printf("MEDIA MOVEL DE UM DETERMINADO PAIS (3)\n");
	printf("TAXA DE MORTALIDADE DE 10 PAISES (4)\n");
	printf("TOTAL DE MORTES POR PERIODO DE UM DETERMINADO PAIS(5)\n");
	printf("TOTAL DE INFECTADOS POR PERIODO DE UM DETERMINADO PAIS(6)\n");
	printf("NUMERO  ACUMULADO TOTAL DE  INFECTADOS POR PAIS (7)\n");
	printf("NUMERO  ACUMULADO TOTAL DE  MORTES POR PAIS (8)\n");
	printf("PARA FINALIZAR O PROGRAMA (0)\n");
	printf("\n======================================================\n");
	scanf("%d",&op);
	
	return (op);
}
int main()
{
	LCOVID l1,l2,l3;
	int op,aux1,aux2;
	char pais1[50],pais2[50];
	
	
	do
	{
		op=menu();
		switch (op)
		{
   			case 1:
     			system("cls");
     			printf("QUAL PAIS 1: \n");
     			setbuf(stdin,NULL);
     			gets(pais1);
     			
     			printf("QUAL PAIS 2: \n");
     			setbuf(stdin,NULL);
     			gets(pais2);
     			abrir(&l1,pais1);
     			abrir(&l2,pais2);
     			comparar_paises(l1,l2);
     			
     			break;

   			case 2: //TODOS OS CASOS DE UM DETERMINADO PAIS ORDENADO (2)\n
   			
     			system("cls");
     			printf("QUAL PAIS : \n");
     			setbuf(stdin,NULL);
     			gets(pais1);
     			abrir(&l1,pais1);
     			ord_por_mes(&l1);
     			imprimir(l1);
     			getch();
     			break;
   			
			case 3://MEDIA MOVEL DE UM DETERMINADO PAIS (3)\n"
     			
				system("cls");
     			printf("QUAL PAIS : \n");
     			setbuf(stdin,NULL);
     			gets(pais1);
     			system("cls");
     			abrir(&l1,pais1);
     			media_movel(l1);
     			getch();
     			break;
				
			case 4: //TAXA DE MORTALIDADE DE 10 PAISES (4)\n
     		
     		
     			break;
     			
   			case 5: //"TOTAL DE MORTES POR PERIODO DE UM DETERMINADO PAIS(5)\n");
     			system("cls");
     			printf("QUAL PAIS : \n");
     			setbuf(stdin,NULL);
     			gets(pais1);
     			system("cls");
     			abrir(&l1,pais1);
     			printf("DESDE O MES : \n");
     			scanf("%d",&aux1);
     			printf("ATE O MES : \n");
     			scanf("%d",&aux2);
     			printf(" O TOTAL DE MORTES  (%s) \n NO PERIDO DO MES %d ATE O MES %d \n FOI DE: %d ",l1->inf.pais,aux1,aux2,totalperiodomortes(l1,aux1,aux2));
     			getch();
     			break;
     			
   			case 6: //TOTAL DE INFECTADOS POR PERIODO DE UM DETERMINADO PAIS(6)\n");
     			system("cls");
     			printf("QUAL PAIS : \n");
     			setbuf(stdin,NULL);
     			gets(pais1);
     			system("cls");
     			abrir(&l1,pais1);
     			printf("DESDE O MES : \n");
     			scanf("%d",&aux1);
     			printf("ATE O MES : \n");
     			scanf("%d",&aux2);
     			printf(" O TOTAL DE INFECTADOS  (%s) \n NO PERIDO DO MES %d ATE O MES %d \n FOI DE: %d ",l1->inf.pais,aux1,aux2,totalperiodocasos(l1,aux1,aux2));
     			getch();
     			break;
     			
   			case 7: //"NUMERO  ACUMULADO TOTAL DE  INFECTADOS POR PAIS (7)\n");
     			system("cls");
     			printf("QUAL PAIS : \n");
     			setbuf(stdin,NULL);
     			gets(pais1);
     			system("cls");
     			abrir(&l1,pais1);
     			printf(" O TOTAL ACUMULADO DE INFECTADOS (%s)\n EH DE: %d ",l1->inf.pais,(int)totcasos(l1));
     			getch();
     			 
     			break;
     			
   			case 8:
				system("cls");
     			printf("QUAL PAIS : \n");
     			setbuf(stdin,NULL);
     			gets(pais1);
     			system("cls");
     			abrir(&l1,pais1);
     			printf(" O TOTAL ACUMULADO DE MORTES (%s)\n EH DE: %d ",l1->inf.pais,(int)totmortes(l1));
     			getch();     		
     		break;
     			
  		 	
     		
		}
	
   }while(op!=0);
    //abrir(&l3,s3);
    //abrir(&l1,s1);
    //ord_por_mes(&l3);
    //ord_por_mes(&l1);
	//imprimir(l3);
	//taxa_mortalidade(l3);
	//totalperiodo(l3,1,3);
    //printf("TOTAL DE CASOS  %s = %ld\n",l3->inf.pais,totcasos(l3));
    //comparar_paises(l1,l3);
    
}

