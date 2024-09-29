#include <stdio.h>
#include <conio.h> //getch(l? um car?cter do teclado e n?o o mostra na tela)
#include <locale.h> // Para poder p?r acentos no programa
#include <stdlib.h>
#include <string.h>
#define TAMvetor 1000
void HEADER(void) 
{
	printf("----------------------------------------------------\n");
	printf("---------------GESTOR DE ESTOQUE--------------------\n");
	printf("----------------------------------------------------\n"); 
	printf("----------------SEjA BEM VINDO----------------------\n");
	printf("----------------------------------------------------\n\n");
} 
void OPTIONS(void) // op??es dadas pelo programa 
{
	printf("(1) CADASTRO\n");
	printf("(2) VENDA\n");
	printf("(3) CONSULTA\n");
	printf("(4) EXCLUS?O DE DADOS\n");
	printf("(5) FINALIZAR PROGRAMA\n\n");
	printf("ESCOLHA UMA OPCAO: ");
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




int main()
{   setlocale(LC_ALL, "Portuguese"); // Acentos no programa 
	int opcao,i;
	CADASTRO  boss[TAMvetor];
	
	HEADER();
	do{
		OPTIONS();
		scanf("%i",&opcao);
		switch(opcao){
		case 1:
		 printf("Sair (5)\n");
          for(i=0;i<TAMvetor;i++)
          { 
            printf("TIPO DE ROUPA \n");  
            scanf("%s",boss[i].tipo);
            printf("QUANTIDADE ADICIONADA \n");
            scanf("%d",&boss[i].quantidade);
            printf("CUSTO \n");
            scanf("%f",&boss[i].custo);
            printf("PRECO ESTIMADO DE VENDA\n");	
            scanf("%f",&boss[i].preco);
            printf("LUCRO ESTIMADO DE ""%.2f%%",LUCRO(boss[i].custo,boss[i].preco));
            
             break;
           
           }

		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		break;
		case 2: // VENDA
		break;
		case 3: // CONSULTA
		break;
		case 4: //EXCLUS?O DE DADOS 
		break;
		case 5: //SAIR 
			printf("AT? A PR?XIMA! ");
			getch();
		break;
		default:
			printf("OP??O INV?LIDA!\n\n");
			getch();
		break;
		}
	}while(opcao != 5);
}
