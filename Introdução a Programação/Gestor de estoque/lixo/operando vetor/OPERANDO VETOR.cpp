#include <stdio.h>
#include <conio.h> //getch()
#include <locale.h> // acentos
#include <stdlib.h>
#include <string.h>
void HEADER(void) 
{
	printf("----------------------------------------------------------------\n");
	printf("---------------------- GESTOR DE ESTOQUE -----------------------\n");
	printf("----------------------------------------------------------------\n"); 
} 

void OPTIONS(void) // opções dadas pelo programa 
{
	printf("\n(1) CADASTRO\n");
	printf("(2) VENDA\n");
	printf("(3) ADICIONAR MERCADORIA\n");
	printf("(4) CONSULTA\n");
	printf("(5) EXCLUSÃO DE DADOS\n");
	printf("(6) FINALIZAR PROGRAMA\n\n");
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
FILE *arqestoque;
void cadastrar()
{   
     int opc,count=1;
     do{
	arqestoque = fopen("estoque.txt","a+");//A+ ADICONA AO FINAL DO ARQUIVO
	if(arqestoque==NULL)
	{
		printf("ERRO AO TENTAR ABRIR O ARQUIVO !");
		exit(1);
	}
	else
	   {
			system("cls");
			 HEADER();
			setbuf(stdin, NULL);
	     printf("\nTIPO DE ROUPA: "); 
	      scanf("%[^\n]",boss.tipo);
	     printf("QUANTIDADE ADICIONADA: ");
	     scanf("%d",&boss.quantidade);
         printf("CUSTO DE COMPRA: ");
         scanf("%f",&boss.custo);
	     printf("PRECO ESTIMADO DE VENDA: ");	
         scanf("%f",&boss.preco);
         printf("LUCRO ESTIMADO DE ""%.2f%%\n",LUCRO(boss.custo,boss.preco));
         fwrite(&boss,sizeof(CADASTRO),1,arqestoque); //escreve tudo que tu digitou na struck no arquivo
         fclose(arqestoque);
          printf("CADASTRAR OUTRA ROUPA \n SIM (1) NAO(2)");
		   scanf("%d",&opc);
		   if(opc!=1&&2)
		   break;     
	   }
 	}while(opc==1||2);
}
void visualizar ()
{      FILE *arqestoque;
             system("cls");
             HEADER();
           arqestoque=fopen("estoque.txt","r");//MODO LEITURA
            if(arqestoque==NULL)
            {printf("ERRO AO ABRIR O ARQUIVO");
             exit(1);
			}
			else{
            do  
            {  
			          
			    fread(&boss,sizeof(CADASTRO),1,arqestoque); //ler o arquivo
			    printf("\nTIPO DE ROUPA: "); 
        		printf("%s \n",boss.tipo);
         		printf("QUANTIDADE ADICIONADA: ");
        		printf("%d \n",boss.quantidade);
        		printf("CUSTO DE COMPRA: ");
        		printf("%f \n",boss.custo);
        		printf("PRECO ESTIMADO DE VENDA: ");	
        		printf("%f \n",boss.preco);
        		
              }while(!feof(arqestoque));//verifica se é o final do arquivo
} 
printf("PRECIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL");
getch();
}
void procurar ()
{  char busca[30];
      
        system("cls");
			   HEADER();
			  
      printf("NOME DO TIPO:  ");
       setbuf(stdin,NULL);
      scanf("%s",busca);
     FILE *arqestoque;
      arqestoque=fopen("estoque.txt","r");
                if(arqestoque==NULL){
                	printf("ERRO AO ABRIR O ARQUIVO");
				}
				 else{
				 	fread(&boss,sizeof(CADASTRO),1,arqestoque);
                 if(strcmp(busca,boss.tipo));
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
                fclose(arqestoque);
                printf("PRECIONE QUALQUER TECLAR PARA VOLTAR AO MENU PRINCIPAL");
                getch();
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
			case 1: //Cadastro
				   cadastrar();
			break;
			case 2: // VENDA
			break;
			case 3:   // ADICIONAR MERCADORIA
			break;
			case 4: system("cls");
			         HEADER();
				    printf("PROCURAR POR NOME(1): \n ");
			        printf("LISTAR TODOS(2): \n ");
			        scanf("%d",&opc);
					if(opc==1){
					procurar();
			     	}
			     	if(opc==2){
			        visualizar();
				    }
			break;
			case 5: //EXCLUSÃO DE DADOS	
			break;
			case 6: //SAIR 
				printf("ATÉ A PRÓXIMA! ");
				exit(0);
			break;
			default:
				printf("OPÇÃO INVÁLIDA!\n\n");
				getch();
			break;
		}
	}while(opcao != 6);
}
