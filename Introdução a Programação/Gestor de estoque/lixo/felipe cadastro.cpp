#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h>
#define aurelio 500
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
} data;
typedef struct
{
    char tipo[50];
    data dataC;
    int quantidade;
    float custo;
    float preco;
    float lucro;

} CADASTRO;
main()
{   
	setlocale(LC_ALL, "Portuguese");
	int i;
    CADASTRO  vet_cad[aurelio];
    for(i=0;i<aurelio || i!=0;i++)
    {
    	printf("Digite o tipo de roupa que voc? deseja cadastrar: ");
        scanf("%s",vet_cad[i].tipo);
        printf("Digite a dia: ");
        scanf("%i",&vet_cad[i].dataC.dia);
        printf("Digite o mes: ");
        scanf("%i",&vet_cad[i].dataC.mes);
        printf("Digite o ano:");
        scanf("%i",&vet_cad[i].dataC.ano);
        printf("Digite a quantidade de itens desse tipo: ");
        scanf("%i",&vet_cad[i].quantidade);
        printf("Digite o custo de compra: ");
        scanf("%f",&vet_cad[i].custo);
        printf("Digite o pre?o de venda: ");
        scanf("%f",&vet_cad[i].preco);
        vet_cad[i].lucro = LUCRO(vet_cad[i].custo,vet_cad[i].preco);
   }


}
