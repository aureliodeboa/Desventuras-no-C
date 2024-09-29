#include <stdio.h>
#include <conio.h> //getch()
#include <locale.h> // acentos
#include <stdlib.h>
#include <string.h>

/* STRUCT DATA, CADASTRO*/
typedef struct
{ 
    int dia;
    int mes;
    int ano;
} data;

typedef struct
{
    char tipo[30];
    int quantidade;
    float custo;
    float preco;
    float lucro;

} cadastro;

/*VARIAVEIS GLOBAIS */
FILE *arqestoque;
cadastro boss;

void HEADER() //cabeçalho
{
	printf("------------------------------------------------------------------------------------------------\n");
	printf("--------------------------------------- GESTOR DE ESTOQUE --------------------------------------\n");
	printf("------------------------------------------------------------------------------------------------\n"); 
} 

void MENU() // opções dadas pelo programa 
{
	printf("\n(1) CADASTRAR PRODUTO\n");
	printf("(2) VENDA\n");
	printf("(3) ADICIONAR MERCADORIA\n");
	printf("(4) BUSCAR TIPO \n");
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

int verificar(char nome[]) // Verificando se ja existe algum tipo igual 
{
    fread(&boss,sizeof(cadastro),1,arqestoque);
    while(!feof(arqestoque))
    {
    	if (!strcmp(boss.tipo,nome)) // Se forem iguais entra
		{
            fseek(arqestoque,-sizeof(cadastro),SEEK_CUR);
            return 1;   
			/* fssek(move a posição corrente de leitura ou escrita no arquivo de um valor especificado, a partir de um ponto especificado)
			SEEK_CUR a partir do ponto que o arquivo se encontra */                     
        }
        fread(&boss,sizeof(cadastro),1,arqestoque);
    }
	return 0;
}

void cadastrar() //1
{   
	char nome[30];
	arqestoque = fopen("estoque.bin","a+b");
	if(!arqestoque)
	{
		printf("ERRO AO TENTAR ABRIR O ARQUIVO!");
		getch();
		return;
	}
	system("cls");
	HEADER();
	fflush(stdin);
	printf("\nTIPO DE ROUPA: "); 
	scanf("%29[^\n]",nome);
	if(verificar(nome))
	{
		printf("UM TIPO COM ESSE NOME JÁ EXISTENTE!\n");
	}
	else
	{
		strcpy(boss.tipo,nome);
		printf("QUANTIDADE ADICIONADA: ");
		scanf("%d",&boss.quantidade);
    	printf("CUSTO DE COMPRA(R$): ");
    	scanf("%f",&boss.custo);
		printf("PRECO ESTIMADO DE VENDA(R$): ");	
    	scanf("%f",&boss.preco);
    	boss.lucro = LUCRO(boss.custo,boss.preco);
    	printf("LUCRO ESTIMADO DE ""%.2f%%\n\n",boss.lucro);
    	fwrite(&boss,sizeof(cadastro),1,arqestoque);
	}
	fclose(arqestoque);
	getch();
}

void pesquisar() //4
{
	char busca[30];
    arqestoque= fopen("estoque.bin","rb");
    if(!arqestoque)
    { 
    	 printf("ERRO AO ABRIR O ARQUIVO!");
    	 getch();
    	 return;
    }
	system("cls");
    HEADER();
    printf("DIGITE O \"TIPO\" DE ROUPA: ");
	fflush(stdin);
    scanf("%29[^\n]",busca);
	if(verificar(busca))
    {
    	fread(&boss,sizeof(cadastro),1,arqestoque);
    	printf("\n\n");
        printf("\n ----------------------------------------------------------------------------------------------\n"); 
		printf("|             TIPO             | QUANTIDADE |       PREÇO       |       CUSTO       |   LUCRO  |\n");
		printf(" ----------------------------------------------------------------------------------------------\n");
		printf("|\"%-18s\"|%-6i|%-8.2f|%-9.2f|%-7.2f%%|\n",boss.tipo,boss.quantidade,boss.preco,boss.custo,boss.custo);
    	printf(" ----------------------------------------------------------------------------------------------\n\n\n");	
    }
    else
    {
    	printf("\nNÃO EXISTE \"TIPO\" COM ESSE NOME!");
	}
    getch();
}

void listar() // 5 
{
	arqestoque = fopen("estoque.bin","r+b");
	if(!arqestoque)
	{
		printf("ERRO AO TENTAR ABRIR O ARQUIVO!");
		getch();
		return;
	}
	system("cls");
	printf("\n ----------------------------------------------------------------------------------------------\n"); 
	printf("|             TIPO             | QUANTIDADE |       PREÇO       |       CUSTO       |   LUCRO  |\n");
	printf(" ----------------------------------------------------------------------------------------------\n");
	fread(&boss,sizeof(cadastro),1,arqestoque);
	while(!feof(arqestoque))
    {
    	printf("|\"%-28s\"|%-12i|%-19.2f|%-19.2f|%-9.2f%%|\n",boss.tipo,boss.quantidade,boss.preco,boss.custo,boss.custo);
    	printf(" ----------------------------------------------------------------------------------------------\n\n\n");
    	fread(&boss,sizeof(cadastro),1,arqestoque);
	}	   
	fclose(arqestoque);
	getch();
}

void remover() // 6
{
	char busca[30];
	FILE *aux;
	arqestoque = fopen("estoque.bin","r+b");
	if(!arqestoque)
	{
		printf("\nERROR AO TENTAR ABRIR O ARQUIVO!");
		getch();
		return;
	}
	aux = fopen("auxiliar.bin","a+b");
	printf("DIGITE O TIPO QUE VOCÊ DESEJA EXCLUIR: ");
	fflush(stdin);
	scanf("%29[^\n]",busca);
	fread(&boss,sizeof(cadastro),1,arqestoque);
	while(!feof(arqestoque))
	{
		if(strcmp(busca,boss.tipo)) // SE ELES NAO FOREM IGUAIS OS VOU ESCREVER NO ARQUIVO NOVO 
			fwrite(&boss,sizeof(cadastro),1,aux);
		fread(&boss,sizeof(cadastro),1,arqestoque);
	}
	fclose(arqestoque);
	fclose(aux);
	if(!remove("estoque.bin") && !rename("auxiliar.bin","estoque.bin"))
	{
		printf("REMOÇÃO CONCLUIDA!");
	}
	else 
	{
		printf("OCORREU UM ERRO!");
	}
	getch();
}

void excluir() // 7
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
{   
	setlocale(LC_ALL, "Portuguese"); // Acentos no programa 
	int opcao;
    do
    {	 
   		system("cls");
		HEADER();
		MENU();
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
				pesquisar();  
			break;
			case 5:
				listar();
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
