#include <stdio.h>
#include <conio.h> 
#include <locale.h>
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

void HEADER() // CABEÇALHO
{
	printf("-------------------------------------------\n");
	printf("----------- GESTOR DE ESTOQUE -------------\n");
	printf("--------------------------------------\n"); 
} 

void MENU() // OPÇÕES
{
	printf("\n(1) CADASTRAR PRODUTO\n");
	printf("(2) VENDA\n");
	printf("(3) ADICIONAR MERCADORIA\n");
	printf("(4) ALTERAR PREÇO\n");
	printf("(5) PESQUISAR TIPO \n");
	printf("(6) LISTAR TODOS DADOS\n");
	printf("(7) MUDAR TIPO\n");
	printf("(8) REMOVER CADASTRO\n");
	printf("(9) REMOVER TODOS OS DADOS\n");
	printf("(10) FINALIZAR PROGRAMA\n\n");
	printf("ESCOLHA UMA OPÇÃO: ");
}

float LUCRO(float a, float b) // LUCRO
{  
	float lucrot = ((b*100)/ a) - 100 ;
	return(lucrot);
}

int verificar(char nome[]) // VERIFICA SE JA TEM NOME EXISTENTE 
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

int auxmodificarEX(char nome[]) //MESMO ESQUEMA DE REMOVER POREM RETORNANDO 1 SE DER CERTO
{
	FILE *aux;
	arqestoque = fopen("estoque.bin","r+b");
	if(!arqestoque)
		return 0;	
	aux = fopen("auxiliar.bin","a+b");
	fread(&boss,sizeof(cadastro),1,arqestoque);
	while(!feof(arqestoque))
	{
		if(strcmp(nome,boss.tipo)) // SE ELES NAO FOREM IGUAIS OS VOU ESCREVER NO ARQUIVO NOVO 
			fwrite(&boss,sizeof(cadastro),1,aux);
		fread(&boss,sizeof(cadastro),1,arqestoque);
	}
	fclose(arqestoque);
	fclose(aux);
	if(!remove("estoque.bin") && !rename("auxiliar.bin","estoque.bin"))
	{
		return 1;
	}
	return 0;
}

void cadastrar() //1 FALTA DEIXA TUDO MAIUSCULO MAS TEM O PROBLEMA DE SE O CARA POR NUMERO QUANDO LER ISSO FALE COMIGO 
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
	printf("\nTIPO DE ROUPA: ");
	fflush(stdin); 
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

void vender() // 2
{
	char nome[30];
	cadastro mercadoria;
	int venda, total;
	arqestoque = fopen("estoque.bin","a+b");
	if(!arqestoque)
	{
		printf("ERRO AO TENTAR ABRIR O ARQUIVO!");
		getch();
		return;
	}
	system("cls");
	HEADER();
	printf("\nDIGITE O \"TIPO\" O QUAL FOI VENDIDO A(S) MERCADORIA(S): ");
	fflush(stdin);
    scanf("%29[^\n]",nome);
	if(verificar(nome))
	{	
		fread(&boss,sizeof(cadastro),1,arqestoque);
        printf("\n ---------------------------------------------------------\n"); 
		printf("|    TIPO  | QUANTIDADE |  CUSTO   |   PREÇO  | LUCRO  |\n");
		printf(" -------------------------------------------------------\n");
		printf("|\"%-18s\"|%-10i|%-19.2f|%-19.2f|%-9.2f%%|\n",boss.tipo,boss.quantidade,boss.custo,boss.preco,boss.lucro);
    	printf(" ----------------------------------------------------------------------------------------------\n\n\n");
		printf("DIGITE A QUANTIDADE DE MERCADORIAS VENDIDAS: ");
		scanf("%i",&venda);
		total = boss.quantidade - venda;
		if(total>-1)
		{
			
			strcpy(mercadoria.tipo,boss.tipo);
			mercadoria.quantidade = total;
			mercadoria.custo = boss.custo;
			mercadoria.preco = boss.preco;
			mercadoria.lucro = boss.lucro;
			fclose(arqestoque);
			if(auxmodificarEX(nome)) 
			{
				arqestoque = fopen("estoque.bin","a+b");
				if(!arqestoque)
					{
						printf("ERRO AO TENTAR ABRIR O ARQUIVO!");
					}
				fwrite(&mercadoria,sizeof(cadastro),1,arqestoque);	
				fclose(arqestoque);
				printf("QUANTIDADE ALTERADA COM SUCESSO!\n\n");				
			}
			else
			{
				printf("OCORREU ALGUM ERRO!");	
			}
		}
		else
		{
			printf("HOUVE ALGUM ENGANO, A QUANTIDADE DE VENDA É MAIOR QUE A DO ESTOQUE DA LOJA!\n");
			printf("CERTIFIQUE-SE DA QUANTIDADE APRESENTADA NA LOJA E TENTE NOVAMENTE!");
		}
	}
	else
    {
    	printf("\nNÃO EXISTE \"TIPO\" COM ESSE NOME!");
	}
    getch();
}

void addmercadoria() //3
{
	char nome[30];
	cadastro mercadoria;
	int add, total;
	arqestoque = fopen("estoque.bin","a+b");
	if(!arqestoque)
	{
		printf("ERRO AO TENTAR ABRIR O ARQUIVO!");
		getch();
		return;
	}
	system("cls");
	HEADER();
	printf("\nDIGITE O \"TIPO\" O QUAL FOI RECEBERÁ MERCADORIA(S): ");
	fflush(stdin);
	scanf("%29[^\n]",nome);
	if(verificar(nome))
	{	
		fread(&boss,sizeof(cadastro),1,arqestoque);
     	printf("\n ----------------------------------------------------------------------------------------------\n"); 
		printf("|             TIPO             | QUANTIDADE |       CUSTO       |       PREÇO       |   LUCRO  |\n");
		printf(" ----------------------------------------------------------------------------------------------\n");
		printf("|\"%-28s\"|%-12i|%-19.2f|%-19.2f|%-9.2f%%|\n",boss.tipo,boss.quantidade,boss.custo,boss.preco,boss.lucro);
    	printf(" ----------------------------------------------------------------------------------------------\n\n\n");
		printf("DIGITE A QUANTIDADE DE MERCADORIAS REPOSTAS: ");
		scanf("%i",&add);
		total = boss.quantidade + add;
		strcpy(mercadoria.tipo,boss.tipo);
		mercadoria.quantidade = total;
		mercadoria.custo = boss.custo;
		mercadoria.preco = boss.preco;
		mercadoria.lucro = boss.lucro;
		fclose(arqestoque);
		if(auxmodificarEX(nome)) 
		{
			arqestoque = fopen("estoque.bin","a+b");
			if(!arqestoque)
				{
					printf("ERRO AO TENTAR ABRIR O ARQUIVO!");
				}
			fwrite(&mercadoria,sizeof(cadastro),1,arqestoque);	
			fclose(arqestoque);
			printf("QUANTIDADE ALTERADA COM SUCESSO!\n\n");
		}
		else
		{
			printf("OCORREU ALGUM ERRO!");
		}
	}
	else
    {
    	printf("\nNÃO EXISTE \"TIPO\" COM ESSE NOME!");
	}
    getch();
}

void alterarpreco() //4
{
	char nome[30];
	cadastro mercadoria;
	float Npreco;
	arqestoque = fopen("estoque.bin","a+b");
	if(!arqestoque)
	{
		printf("ERRO AO TENTAR ABRIR O ARQUIVO!");
		getch();
		return;
	}
	system("cls");
	HEADER();
	printf("\nDIGITE O TIPO QUE DEVERÁ TER SEU NOME ALTERADO: ");
	fflush(stdin);
	scanf("%29[^\n]",nome);
	if(verificar(nome))
	{	
		fread(&boss,sizeof(cadastro),1,arqestoque);
     	printf("\n ----------------------------------------------------------------------------------------------\n"); 
		printf("|             TIPO             | QUANTIDADE |       CUSTO       |       PREÇO       |   LUCRO  |\n");
		printf(" ----------------------------------------------------------------------------------------------\n");
		printf("|\"%-28s\"|%-12i|%-19.2f|%-19.2f|%-9.2f%%|\n",boss.tipo,boss.quantidade,boss.custo,boss.preco,boss.lucro);
    	printf(" ----------------------------------------------------------------------------------------------\n\n\n");
		printf("DIGITE O NOVO PREÇO: ");
		scanf("%f",&Npreco);
		strcpy(mercadoria.tipo,boss.tipo);
		mercadoria.quantidade = boss.quantidade;
		mercadoria.custo = boss.custo;
		mercadoria.preco = Npreco;
		mercadoria.lucro = LUCRO(mercadoria.custo,mercadoria.preco);
		fclose(arqestoque);
		if(auxmodificarEX(nome)) 
		{
			arqestoque = fopen("estoque.bin","a+b");
			if(!arqestoque)
				{
					printf("ERRO AO TENTAR ABRIR O ARQUIVO!");
				}
			fwrite(&mercadoria,sizeof(cadastro),1,arqestoque);	
			fclose(arqestoque);
			printf("PREÇO ALTERADO COM SUCESSO!\n\n");
		}
		else
		{
			printf("OCORREU ALGUM ERRO!");
		}
	}
	else
    {
    	printf("\nNÃO EXISTE \"TIPO\" COM ESSE NOME!");
	}
    getch();
}	

void pesquisar() //5
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
		printf("|             TIPO             | QUANTIDADE |       CUSTO       |       PREÇO       |   LUCRO  |\n");
		printf(" ----------------------------------------------------------------------------------------------\n");
		printf("|\"%-28s\"|%-12i|%-19.2f|%-19.2f|%-9.2f%%|\n",boss.tipo,boss.quantidade,boss.custo,boss.preco,boss.lucro);
    	printf(" ----------------------------------------------------------------------------------------------\n\n\n");	
    }
    else
    {
    	printf("\nNÃO EXISTE \"TIPO\" COM ESSE NOME!");
	}
    getch();
}

void listar() // 6 
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
	printf("|             TIPO             | QUANTIDADE |       CUSTO       |       PREÇO       |   LUCRO  |\n");
	printf(" ----------------------------------------------------------------------------------------------\n");
	fread(&boss,sizeof(cadastro),1,arqestoque);
	while(!feof(arqestoque))
    {
    	printf("|\"%-28s\"|%-12i|%-19.2f|%-19.2f|%-9.2f%%|\n",boss.tipo,boss.quantidade,boss.custo,boss.preco,boss.lucro);
    	printf(" ----------------------------------------------------------------------------------------------\n");
    	fread(&boss,sizeof(cadastro),1,arqestoque);
	}	   
	fclose(arqestoque);
	getch();
}

void mudartipo() // 7
{
	char nome[30], novo[30];
	cadastro mercadoria;
	int venda, total;
	arqestoque = fopen("estoque.bin","a+b");
	if(!arqestoque)
	{
		printf("ERRO AO TENTAR ABRIR O ARQUIVO!");
		getch();
		return;
	}
	system("cls");
	HEADER();
	printf("\nDIGITE O \"TIPO\" QUE VOCÊ DESEJA ALTERAR: ");
	fflush(stdin);
	scanf("%29[^\n]",nome);
	if(verificar(nome))
	{	
		fread(&boss,sizeof(cadastro),1,arqestoque);
        printf("\n ----------------------------------------------------------------------------------------------\n"); 
		printf("|             TIPO             | QUANTIDADE |       CUSTO       |       PREÇO       |   LUCRO  |\n");
		printf(" ----------------------------------------------------------------------------------------------\n");
		printf("|\"%-28s\"|%-12i|%-19.2f|%-19.2f|%-9.2f%%|\n",boss.tipo,boss.quantidade,boss.custo,boss.preco,boss.lucro);
    	printf(" ----------------------------------------------------------------------------------------------\n\n\n");
		printf("DIGITE O NOVO TIPO: ");
		fflush(stdin);
		scanf("%29[^\n]",novo);
		strcpy(mercadoria.tipo,novo);
		mercadoria.quantidade = boss.quantidade;
		mercadoria.custo = boss.custo;
		mercadoria.preco = boss.preco;
		mercadoria.lucro = boss.lucro;
		fclose(arqestoque);
		if(auxmodificarEX(nome)) 
		{
			arqestoque = fopen("estoque.bin","a+b");
			if(!arqestoque)
				{
					printf("ERRO AO TENTAR ABRIR O ARQUIVO!");
				}
			fwrite(&mercadoria,sizeof(cadastro),1,arqestoque);	
			fclose(arqestoque);
			printf("TIPO ALTERADO COM SUCESSO!\n\n");				
		}
		else
		{
			printf("OCORREU ALGUM ERRO!");
		}		
	}
	else
    {
    	printf("\nNÃO EXISTE \"TIPO\" COM ESSE NOME!");
	}
    getch();
}

void remover() // 8
{
	char busca[30];
	int opc;
	FILE *aux;
	arqestoque = fopen("estoque.bin","r+b");
	if(!arqestoque)
	{
		printf("\nERROR AO TENTAR ABRIR O ARQUIVO!");
		getch();
		return;
	}
	aux = fopen("auxiliar.bin","w+b");
	system("cls");
	HEADER();
	printf("DIGITE O TIPO QUE VOCÊ DESEJA EXCLUIR: ");
	fflush(stdin);
	scanf("%29[^\n]",busca);
	fread(&boss,sizeof(cadastro),1,arqestoque);
	while(!feof(arqestoque))
	{
		if(strcmp(busca,boss.tipo)) // SE ELES NAO FOREM IGUAIS OS VOU ESCREVER NO ARQUIVO NOVO 
			fwrite(&boss,sizeof(cadastro),1,aux);
		else
		{
			printf("\n ----------------------------------------------------------------------------------------------\n"); 
			printf("|             TIPO             | QUANTIDADE |       CUSTO       |       PREÇO       |   LUCRO  |\n");
			printf(" ----------------------------------------------------------------------------------------------\n");
			printf("|\"%-28s\"|%-12i|%-19.2f|%-19.2f|%-9.2f%%|\n",boss.tipo,boss.quantidade,boss.custo,boss.preco,boss.lucro);
    		printf(" ----------------------------------------------------------------------------------------------\n\n\n");
		}
		fread(&boss,sizeof(cadastro),1,arqestoque);		
	}
	fclose(arqestoque);
	fclose(aux);
	printf("DESEJA MESMO REMOVER:\n(1)SIM\n(2)NÃO\nESCOLHA UMA OPÇÃO: ");
	scanf("%i",&opc);
	while(opc !=1 && opc !=2)
	{
		printf("OPÇÃO INVALIDA!");
		getch();
		printf("\nDESEJA MESMO REMOVER:\n(1)SIM\n(2)NÃO\n");
		printf("ESCOLHA UMA OPÇÃO: ");
		scanf("%i",&opc);
	}
	if(opc==1)
	{	if(!remove("estoque.bin") && !rename("auxiliar.bin","estoque.bin"))
		{
			printf("REMOÇÃO CONCLUIDA!");
		}
		else 
		{
			printf("OCORREU UM ERRO!");
		}
	}
	else
	{
		if(remove("auxiliar.bin")!=0)
			printf("OCORREU UM ERRO!");		
	}
	getch();
}

void excluir() // 9
{            
	int opc;	
	system("cls");
	HEADER();
	printf("DESEJA MESMO REMOVER TODO OS DADOS?\n(1)SIM\n(2)NÃO\n");
	printf("\nESCOLHA UMA OPÇÃO: ");
	scanf("%i",&opc);
	while(opc !=1 && opc !=2)
	{
		printf("OPÇÃO INVALIDA!");
		getch();
		system("cls");
		HEADER();
		printf("DESEJA MESMO REMOVER TODOS OS DADOS?\n(1)SIM\n(2)NÃO\n");
		printf("\nESCOLHA UMA OPÇÃO: ");
		scanf("%i",&opc);
	}
	if(opc==1)
	{	
		if(!remove("estoque.bin")) //verificando se foi removido
		{
			printf("REMOVENDO DADOS...\n");
			printf("REMOVIDO COM SUCESSO !");
			getch();
		}
		else
		{	
			printf("ERRO AO REMOVER OS DADOS...");
			getch();
		}
	}
	else
	{
		printf("VOLTAREMOS AO MENU INICIAL...");
		getch();
	}
}

int main()
{   int opcao;
	setlocale(LC_ALL, "Portuguese"); // Acentos no programa 
	
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
				vender(); 
			break;
			case 3:
				addmercadoria();
			break;
			case 4:
				alterarpreco();
			break;
			case 5:
				pesquisar();  
			break;
			case 6:
				listar();
			break;
			case 7: 
				mudartipo();
			break;
			case 8:
				remover();
			break;	
			case 9: 
				excluir();	
			break;
			case 10:  
				printf("ATÉ A PRÓXIMA! ");
				getch();
			break;
			default:
				printf("OPÇÃO INVÁLIDA!\n\n");
				getch();
			break;
		}
	}while(opcao != 10);
} 
