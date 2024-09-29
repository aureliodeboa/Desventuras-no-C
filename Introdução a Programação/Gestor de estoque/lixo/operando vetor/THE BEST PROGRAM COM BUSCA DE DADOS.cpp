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
///	printf("(2) VENDA\n");
//	printf("(3) ADICIONAR MERCADORIA\n");
	printf("(4) CONSULTA\n");
	printf("(5) REMOVER TODOS OS DADOS\n");
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
	         scanf("%49[^\n]",boss.tipo);
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
{  FILE *arqestoque;
             system("cls");
             HEADER();
             arqestoque=fopen("estoque.txt","r");//MODO LEITURA
             if(arqestoque==NULL)
               {
			      printf("ERRO AO ABRIR O ARQUIVO");
                 exit(1);
			   }
			 else
		     {
                 while(!feof(arqestoque))//verifica se é o final do arquivo
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
        		
                 }
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
         scanf("%29[^\n]",busca);
         FILE *arqestoque;
        arqestoque=fopen("estoque.txt","r");
                 if(arqestoque==NULL)
				 {
                     printf("ERRO AO ABRIR O ARQUIVO");
				 }
				 else
				 {  	do{
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
                 }while(!feof(arqestoque));
                 }
				 fclose(arqestoque);
 printf("PRECIONE QUALQUER TECLAR PARA VOLTAR AO MENU PRINCIPAL");
 getch();
}

void adicionar() //TODA VEZ QUE VOCE ADICONA ELE EXCLUI OS OUTROS
{    int opc,count=1,novo;
     char busca[30];
     float fnovo;
     
         printf("DIGITE O NOME DA MERCADORIA QUE DESEJA EDITAR");
         setbuf(stdin,NULL);
         scanf("%29[^\n]",busca);
         do
		 {            /*  o problema é por causa de w ou w+ foda que nao tem outra opçao*/
	     arqestoque = fopen("estoque.txt","w");//w+ tira o velho e adciona o novo 
	     if(arqestoque==NULL)
	     {
		 printf("ERRO AO TENTAR ABRIR O ARQUIVO !");
		 exit(1);
	     }
	     else
	     {    
	      system("cls");
	      HEADER();
		  setbuf(stdin,NULL); //ver a necessidade disso aqui
	      fread(&boss,sizeof(CADASTRO),1,arqestoque);
          if(strcmp(busca,boss.tipo));
          {
	         printf("QUANTIDADE : ");
	         printf("%d \n ",boss.quantidade);
	         printf("DIGITE A QUANTIDADE PARA ADICIONAR: ");
	         scanf("%d",&novo);
	         boss.quantidade+=novo;
             printf("CUSTO DE COMPRA: ");
             printf("%f \n",boss.custo);
             printf("DIGITE O NOVO CUSTO DE COMPRA: ");
             scanf("%f",&fnovo);
             boss.custo+=fnovo;
	         fwrite(&boss,sizeof(CADASTRO),1,arqestoque); //escreve tudo que tu digitou na struck no arquivo
             fclose(arqestoque);
             printf("EDITAR OUTRA ROUPA: \n SIM(1) NAO(2)");
		     scanf("%d",&opc);
     if(opc==2)
     {
      break;
	 }     
}
}
}while(opc==2);
}
void venda() //ajeitar para venda  PRA CONTABILIZAR AS VENDAS
{  
int opc,count=1,novo;
char busca[30];
float fnovo;
         printf("DIGITE O NOME DA MERCADORIA QUE VENDEU:");
         setbuf(stdin,NULL);
         scanf("%29[^\n]",busca);
         do{
	     arqestoque = fopen("estoque.txt","w+");//w+ tira o velho e adciona o novo 
	     if(arqestoque==NULL)
     	 {
	 	    printf("ERRO AO TENTAR ABRIR O ARQUIVO !");
	 	    exit(1);
	     }
	     else
	     {     
	 		 system("cls");
   		     HEADER();
			 //setbuf(stdin,NULL); //ver a necessidade disso aqui
			 fread(&boss,sizeof(CADASTRO),1,arqestoque);
             if(strcmp(busca,boss.tipo));
             {
	              printf("QUANTIDADE : ");
	              printf("%d \n ",boss.quantidade);
	              printf("DIGITE A QUANTIDADE QUE VENDEU: ");
	              scanf("%d",&novo);
	              boss.quantidade-=novo;
	              fwrite(&boss,sizeof(CADASTRO),1,arqestoque); //escreve tudo que tu digitou na struck no arquivo
                  fclose(arqestoque);
                  printf("VENDEU  OUTRA ROUPA: \n SIM(1) NAO(2)");
		          scanf("%d",&opc);
                  if(opc==2)
				  {
                  break;
				  }     
}
}
}while(opc==2);
}

 void remover() 
{            
int opc; 
printf(" TEM CERTEZA ?REMOVER TODOS OS DADOS \n SIM(1) NAO(2)");
scanf("%d",&opc);
         if(opc==1)
         {  
          arqestoque= fopen("estoque.txt","w+");
          if(arqestoque==NULL)
             {
			  printf("ERRO AO APAGAR ARQUIVO");
			 } 
			 else
			 {
			     printf("EXCLUINDO...");
			     getch();
 			      fclose(arqestoque);
			 }
		 }
			 else 
			 {   
			  exit(0);
			 }
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
				venda();
			break;
			case 3:
				 adicionar(); 
			break;
			case 4:  
				 system("cls");
			   	 HEADER();
			     printf("PROCURAR POR NOME(1) OU ");
			     printf(" LISTAR TODOS(2):\n ");
			     scanf("%d",&opc);
				 if(opc==1)
				 {
				  procurar();
			     }
			     if(opc==2)
				 {
			      visualizar();
				 }
			break;
			case 5: 
				remover();	
			break;
			case 6:  
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
