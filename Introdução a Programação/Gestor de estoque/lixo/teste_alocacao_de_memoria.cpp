#include <stdio.h>
#include <conio.h> //getch()
#include <locale.h> // acentos
#include <stdlib.h>
typedef struct
{
    int quantidade;
    float custo;
    float preco;
    float lucro;

} CADASTRO;

float LUCRO(float a, float b)
{  
	float lucrot = ((b*100)/ a) - 100 ;
	return(lucrot);
}

int main()
{  CADASTRO *boss=NULL ;
   int num=0, aux;
   boss =(CADASTRO*)realloc(boss,num*sizeof(CADASTRO));;
   	
   			  printf("QUANTIDADE ADICIONADA: ");
        		scanf("%d",boss+(0*sizeof(int)));
        		printf("CUSTO DE COMPRA: ");
        		scanf("%f",boss+(1*sizeof(int)+(1*sizeof(float))));
        		printf("PRECO ESTIMADO DE VENDA: ");	
        		scanf("%f",boss+(1*sizeof(int)+(2*sizeof(float)))); 
}
