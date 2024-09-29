#include <stdio.h>
#include <conio.h> //getch()
#include <locale.h> // acentos
#include <stdlib.h>
#include <string.h>
#define TAMvetor 1000
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
CADASTRO  boss[TAMvetor];

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
	int cont, opcao, i,j,a;
	char pesquisa[50];
	
	
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
        		//printf("LUCRO ESTIMADO DE ""%.2f%%\n",LUCRO(boss[i].custo,boss[i].preco));
				printf("\nVOCÊ DESEJA CADASTRAR OUTRA ROUPA? \n(1)SIM\n(2)NÃO\n");
				scanf("%i",&cont);
				while(cont!=1 && cont!=2)
					{ printf("OPÇÃO INVÁLIDA!\nDIGITE OUTRA VEZ: ");
						scanf("%i",&cont);	}	
				if(cont==2)
					break;

		}
		printf("DESEJA VISUALIZAR OS TIPOS ARMAZENADOS? (1)SIM\n(2)NÃO\n ");
		scanf("%d",&j);
		printf("QUANTOS ARQUIVOS? ");
		scanf("%d",&a);
	      if(j==1)
		  {
		  visualizar(a);
          	}
          	if(j==2)
          	{
          	    printf("DIGITE O NOME DO TIPO: ");
          	    scanf("%[49]",pesquisa);
          	    for(i=0;i<TAMvetor;i++)
          	    {
          	    if(!strcmp(pesquisa,boss[i].tipo));
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
		/*{   
		
			    printf("\nTIPO DE ROUPA: "); 
        		printf("%s \n",boss[i].tipo);
         		printf("QUANTIDADE ADICIONADA: ");
        		printf("%d \n",boss[i].quantidade);
        		printf("CUSTO DE COMPRA: ");
        		printf("%f \n",boss[i].custo);
        		printf("PRECO ESTIMADO DE VENDA: ");	
        		printf("%f \n",boss[i].preco); */
}

