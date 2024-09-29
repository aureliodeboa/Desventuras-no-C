#include <stdio.h>
#include <conio.h> //getch()
#include <locale.h> // acentos
#include <stdlib.h>
#include <string.h>

void HEADER(void) //cabeçalho
{
	printf("----------------------------------------------------------------\n");
	printf("---------------------- GESTOR DE ESTOQUE -----------------------\n");
	printf("----------------------------------------------------------------\n"); 
} 

void OPTIONS(void) // opções dadas pelo programa 
{
	printf("\n(1) CADASTRAR PRODUTO\n");
	printf("(2) VENDA\n");
	printf("(3) ADICIONAR MERCADORIA\n");
	printf("(4) CONSULTAR TIPO \n");
	printf("(5) CONSULTAR TODOS DADOS\n");
	printf("(6) REMOVER CADASTRO\n");
	printf("(7) REMOVER TODOS OS DADOS\n");
	printf("(8) FINALIZAR PROGRAMA\n\n");
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
    char tipo[30];
    DATA dataC;
    int quantidade;
    float custo;
    float preco;
    float lucro;

} CADASTRO;

CADASTRO boss;
FILE *arqestoque;

void cadastrar() // TA RODANDO( FALTA TRANSFORMAR TUDO EM CARACTERES MAIUSCULOS );
{   
    int opc,count=1;
    do
	{
		arqestoque = fopen("estoque.txt","a+");
		if(!arqestoque)
		{
			printf("ERRO AO TENTAR ABRIR O ARQUIVO!");
		}
		else
	   {
			system("cls");
			HEADER();
			setbuf(stdin, NULL);
	        printf("\nTIPO DE ROUPA: "); 
	        scanf("%29[^\n]",boss.tipo);
	        printf("QUANTIDADE ADICIONADA: ");
	        scanf("%d",&boss.quantidade);
            printf("CUSTO DE COMPRA(R$): ");
            scanf("%f",&boss.custo);
	        printf("PRECO ESTIMADO DE VENDA(R$): ");	
            scanf("%f",&boss.preco);
            boss.lucro = LUCRO(boss.custo,boss.preco);
            printf("LUCRO ESTIMADO DE ""%.2f%%\n\n",boss.lucro);
            fwrite(&boss,sizeof(CADASTRO),1,arqestoque);
            fclose(arqestoque);
			printf("DESEJA CADASTRAR OUTRA ROUPA?\n(1)SIM\n(2)NÃO\n\nESCOLHA UMA OPÇÃO: ");
		    scanf("%d",&opc);
		    while(opc!=1 && opc!=2)
		    {
		    	printf("OPÇÃO INVÁLIDA!");
		    	getch();
		    	system("cls");
		    	HEADER();
		    	printf("DESEJA CADASTRAR OUTRA ROUPA?\n(1)SIM\n(2)NÃO\n\nESCOLHA UMA OPÇÃO: ");
		    	scanf("%d",&opc);		
			}
		}		         
	}while(opc!=2);
}

void visualizar () // TA INDO SO QUE O ULTIMO CADASTRADO RODA DUAS VEZES ;
{  
	FILE *arqestoque;
    system("cls");
    HEADER();
	arqestoque = fopen("estoque.txt","r");
    if(!arqestoque) 
    {
		printf("ERRO AO ABRIR O ARQUIVO!");
	}
	else
	{
        while(!feof(arqestoque)) //verifica esta no final do arquivo
        {  
			fread(&boss,sizeof(CADASTRO),1,arqestoque); 
			printf("\nTIPO DE ROUPA: %s \n",boss.tipo); 
         	printf("QUANTIDADE ADICIONADA: %d\n",boss.quantidade);
        	printf("CUSTO DE COMPRA(R$): %.2f\n",boss.custo);
        	printf("PRECO ESTIMADO DE VENDA(R$): %.2f \n",boss.preco);
        	printf("LUCRO: %.2f%%\n",boss.lucro);
		}
		fclose(arqestoque);
	} 
    getch();
}
void procurar () // TA OK! 
{  
	char busca[30];
    system("cls");
	HEADER();
	printf("NOME DO TIPO:  ");
    setbuf(stdin,NULL);
    scanf("%29[^\n]",busca);   	
    arqestoque=fopen("estoque.txt","r");
    if(arqestoque==NULL)
	{
        printf("ERRO AO ABRIR O ARQUIVO!");
	}
	else
	{   
		while(!feof(arqestoque))
		{   
				fread(&boss,sizeof(CADASTRO),1,arqestoque);
				if(!strcmp(busca,boss.tipo))
        		{
					printf("\nTIPO DE ROUPA: %s \n",boss.tipo); 
         			printf("QUANTIDADE ADICIONADA: %d\n",boss.quantidade);
        			printf("CUSTO DE COMPRA(R$): %.2f\n",boss.custo);
        			printf("PRECO ESTIMADO DE VENDA(R$): %.2f \n",boss.preco);
				}
		}	
    }
	fclose(arqestoque);
 	getch();
}

void remover()
{
	char item[30];
 	int opc;
 	FILE *aux;
 	CADASTRO boss2;
 	aux = fopen("remover.txt","w");
	arqestoque=fopen("estoque.txt","r");
	if(!arqestoque)
	{
		printf("ERROR AO ABRIR ARQUIVO!");
		getch();
	}
	else
	{   
		system("cls");
		HEADER();
		printf("DIGITE O \"TIPO\" QUE VOCÊ DESEJA APAGAR: ");
		setbuf(stdin,NULL);
		scanf("%29[^\n]",item);
		while(fread(&boss2,sizeof(CADASTRO),1,arqestoque));
		{
			if(!strcmp(item,boss2.tipo))
        	{
				printf("\nTIPO DE ROUPA: %s \n",boss2.tipo); 
         		printf("QUANTIDADE ADICIONADA: %d\n",boss2.quantidade);
        		printf("CUSTO DE COMPRA: %f\n",boss2.custo);
        		printf("PRECO ESTIMADO DE VENDA: %f \n",boss2.preco);
			}
			else
			{  
				fwrite(&boss2,sizeof(CADASTRO),1,aux);
			}
		}
		fclose(arqestoque);
		fclose(aux);
		printf("\nDESEJA MESMO REMOVER:\n(1)SIM\n(2)NÃO\n");
		printf("ESCOLHA UMA OPÇÃO: ");
		scanf("%i",&opc);
		if(opc==1)
		{    
	    	
			if(!remove("estoque.txt") && !rename("remover.txt","estoque.txt"))
		    {
				printf("REMOÇÃO CONCLUIDA!");
				getch();
			}
			else
			{
				printf("OCORREU UM ERROR!");
				getch();
			}
		}
		else
		{
			if(opc==2)
			{
				remove("remover.txt");
			}
			else
			{
				printf("OPÇÃO INVALIDA!");
				getch();				
			}		
		}
							
	}
			
}

void excluir() // TA OK!
{            
	int opc;
	do
	{
		system("cls");
		HEADER();
		printf("DESEJA MESMO REMOVER TODO OS DADOS?\n(1)SIM\n(2)NÃO\n");
		printf("\nESCOLHA UMA OPÇÃO: ");
		scanf("%i",&opc);
		if(opc==1)
		{	
			if(!remove("estoque.txt")) //verificando se foi removido
			{
				printf("REMOVENDO DADOS...\n");
				printf("REMOVIDO COM SUCESSO !");
				getch();
				break;
			}
			else
			{	
				printf("ERRO AO REMOVER OS DADOS...");
				getch();
				break;
			}
		}
		else
		{
			if(opc!=2)
			{
				printf("OPÇÃO INVÁLIDA!");
				getch();
			}
		}		
	}while(opc!=2);	
}

int main()
{   setlocale(LC_ALL, "Portuguese"); // Acentos no programa 
	int cont=1, opcao,opc, i;
	CADASTRO  boss;
   do
   {
   		 system("cls");
		 HEADER();
		 OPTIONS();
		 scanf("%i",&opcao);
		 switch(opcao)
		 {
			case 1: 
			 	cadastrar();
			break;
			case 2: 
			break;
			case 3:
			break;
			case 4:  
				procurar();
			break;
			case 5:
			    visualizar();
			break;
			case 6:
				remover();
			break;	
			case 7: 
				excluir();	
			break;
			case 8:  
				printf("ATÉ A PRÓXIMA! ");
				getch();
			break;
			default:
				printf("OPÇÃO INVÁLIDA!\n\n");
				getch();
			break;
		}
	}while(opcao != 8);
}
