#include <stdio.h>
#include <conio.h>
 int main ()
{
 float nota1;
 float nota2;
 float nota3;
 float media;
 int peso1,peso2,peso3,x;
printf("DIGITE A PRIMEIRA NOTA: ");
    scanf("%f", &nota1);
printf("\n QUAL E O PESO DA PRIMEIRA NOTA?\n");
    scanf("%d", &peso1);
printf ("DIGITE A SEGUNDA NOTA: ");
    scanf("%f", &nota2);
printf("\n QUAL E O PESO DA SEGUNDA NOTA? \n");
    scanf("%d", &peso2);
printf("DIGITE A TERCEIRA NOTA:");
    scanf("%f", &nota3);
printf("\n QUAL E O PESO DA TERCEIRA NOTA? \n");
    scanf("%d", &peso3);
    media=((nota1*peso1) + (nota2*peso2)+ (nota3*peso3)) / (peso1 + peso2 + peso3); 
	    
  printf("\n A MEDIA PONDERADA \n %5.2f|", media);
  
  scanf("%d", &x);
	
return (0);		
}
