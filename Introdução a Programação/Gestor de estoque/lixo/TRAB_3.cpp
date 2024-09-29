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
CADASTRO boss[TAMvetor];

void visualizar (int a)
{ int i;
            while(a)
            { 
			    printf("\nTIPO DE ROUPA: "); 
        		printf("%s \n",boss[i].tipo);
         		printf("QUANTIDADE ADICIONADA: ");
        		printf("%d \n",boss[i].quantidade);
        		printf("CUSTO DE COMPRA: ");
        		printf("%f \n",boss[i].custo);
        		printf("PRECO ESTIMADO DE VENDA: ");	
        		printf("%f \n",boss[i].preco);
        		i++;
        		a--;
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
        	for(i=0;i<TAMvetor;i++)
			{ 
          		printf("\nTIPO DE ROUPA: "); 
				setbuf(stdin, NULL); // Tive que limpar buffer pro programa rodar normalmente
        		scanf("%49[^\n]",boss[i].tipo);
         		printf("QUANTIDADE ADICIONADA: ");
        		scanf("%d",&boss[i].quantidade);
        		printf("CUSTO DE COMPRA: ");
        		scanf("%f",&boss[i].custo);
        		printf("PRECO ESTIMADO DE VENDA: ");	
        		scanf("%f",&boss[i].preco);
        		printf("LUCRO ESTIMADO DE ""%.2f%%\n",LUCRO(boss[i].custo,boss[i].preco));
				printf("\nVOCÊ DESEJA CADASTRAR OUTRA ROUPA? \n(1)SIM\n(2)NÃO\n");
				scanf("%i",&cont);
				while(cont!=1 && cont!=2)
					{ printf("OPÇÃO INVÁLIDA!\nDIGITE OUTRA VEZ: ");
						scanf("%i",&cont);	}	
				if(cont==2)
					break;
			}
		break;
		case 2: // VENDA
		break;
		case 3:  // CONSULTA
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
			    
          	    if(strcmp(pesquisa,boss[i].tipo));
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
		       { visualizar(A);}
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
