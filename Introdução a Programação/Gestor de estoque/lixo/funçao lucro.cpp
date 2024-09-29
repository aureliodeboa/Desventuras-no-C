#include <stdio.h> 
#include <stdlib.h> 
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
{   int i;
    float custo,lucro;
    
    
       scanf("%f",&custo);
       scanf("%f",&lucro);
         printf("%.2f""%%",LUCRO(custo,lucro));
    


}
