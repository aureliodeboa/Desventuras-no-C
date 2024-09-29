#include <stdio.h>
#include <conio.h> //getch()
#include <locale.h> // acentos
#include <stdlib.h>
#include <string.h>
#define TAMvetor 1000
void HEADER(void) 
{
	printf("----------------------------------------------------------------\n");
	printf("---------------------- GESTOR DE ESTOQUE -----------------------\n");
	printf("----------------------------------------------------------------\n"); 
	printf("------------------------ SEjA BEM VINDO ------------------------\n");
	printf("----------------------------------------------------------------\n");
} 

void OPTIONS(void) // opções dadas pelo programa 
{
	printf("\n\n(1) CADASTRO\n");
	printf("(2) VENDA\n");
	printf("(3) CONSULTA\n");
	printf("(4) EXCLUSÃO DE DADOS\n");
	printf("(5) FINALIZAR PROGRAMA\n\n");
	printf("ESCOLHA UMA OPÇÃO: ");
}

float LUCRO(float a, float b)
{  
	float lucrot = ((b*100)/ a) - 100 ;
	return(lucrot);
}

typedef struct
{ 
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct
{
    char tipo[50];
    DATA dataC;
    int quantidade;
    float custo;
    float preco;
    float lucro;

} CADASTRO;
CADASTRO boss;

void procurar (char *pesquisa)
{  int i;
   
	for(i=0;i<=TAMvetor;i++)
          	    {
			    if(strcmp(pesquisa,boss.tipo));
          	    else
          	    {
		        printf("\nTIPO DE ROUPA: "); 
        		printf("%s \n",boss.tipo);
         		printf("QUANTIDADE ADICIONADA: ");
        		printf("%d \n",boss.quantidade);
        		printf("CUSTO DE COMPRA: ");
        		printf("%f \n",boss.custo);
        		printf("PRECO ESTIMADO DE VENDA: ");	
        		printf("%f \n",boss.preco);
          	    }
                }
	
}

void visualizar (int a)
{ int i;
            while(a)
            { 
			    printf("\nTIPO DE ROUPA: "); 
        		printf("%s \n",boss.tipo);
         		printf("QUANTIDADE ADICIONADA: ");
        		printf("%d \n",boss.quantidade);
        		printf("CUSTO DE COMPRA: ");
        		printf("%f \n",boss.custo);
        		printf("PRECO ESTIMADO DE VENDA: ");	
        		printf("%f \n",boss.preco);
        		i++;
        		a--;
              }
}
void cadastrar()
{  int opcao;
	CADASTRO boss;
	FILE *arqestoque;
	  arqestoque= fopen("estoque.txt","w");
	   if(arqestoque==NULL){
	   	printf("FALHA AO ABRIR O ARQUIVO");
	   }
	   else
	  {  
	     do 
    		{   
    		    setbuf(stdin, NULL); 
    		    printf("\nTIPO DE ROUPA: "); 
        		scanf("%49[^\n]",boss.tipo);
         		printf("QUANTIDADE ADICIONADA: ");
        		scanf("%d",&boss.quantidade);
        		printf("CUSTO DE COMPRA: ");
        		scanf("%f",&boss.custo);
        		printf("PRECO ESTIMADO DE VENDA: ");	
        		scanf("%f",&boss.preco);
        		fwrite(&boss,sizeof(CADASTRO),1,arqestoque);
        		do
        		{
				printf("\nVOCÊ DESEJA CADASTRAR OUTRA ROUPA? \n(1)SIM\n(2)NÃO\n");
				scanf("%i",&opcao);
				 }while(opcao!=1||2);
				if(opcao==2){
				fclose(arqestoque);
				break;
				}
    	     	  }while(opcao==1);
	       }
      }

int main()
{   setlocale(LC_ALL, "Portuguese"); // Acentos no programa 
	int cont, opcao,i,A;
	char pesquisa[50];
	
	HEADER();
	do{
		OPTIONS();
		scanf("%i",&opcao);
		switch(opcao){
		case 1: //Cadastro 
               cadastrar();
			
		case 2: // VENDA
		break;
		case 3: /* // CONSULTA
		       printf("FAZER BUSCA DO TIPO DESEJADO (1)\n");
			   printf("VISUALIZAR EM ORDEM DE SEQUENCIA DE ARQUIVOS (2)\n");
		       scanf("%d",&A);
		       if(A==1)
		       { 
		       
          	    printf("DIGITE O NOME DO TIPO: ");
          	    setbuf(stdin ,NULL);
          	    scanf("%49[^\n]",pesquisa);
          	    for(i=0;i<=TAMvetor;i++)
          	    {
			    if(strcmp(pesquisa,boss.tipo));
          	    else
          	    {
		        printf("\nTIPO DE ROUPA: "); 
        		printf("%s \n",boss[i].tipo);
         		printf("QUANTIDADE ADICIONADA: ");
        		printf("%d \n",boss[i].quantidade);
        		printf("CUSTO DE COMPRA: ");
        		printf("%f \n",boss[i].custo);
        		printf("PRECO ESTIMADO DE VENDA: ");	
        		printf("%f \n",boss[i].preco);
          	    }
                }
                }
                if(A==2)
		       { visualizar(A);} */
		break;
		case 4: //EXCLUS?O DE DADOS 
		break;
		case 5: //SAIR 
			printf("ATÉ A PRÓXIMA! ");
			getch();
		break;
		default:
			printf("OPÇÃO INVÁLIDA!\n\n");
			getch();
		break;
		}
	}while(opcao != 5);
}
