#include <stdio.h> 
int main() 
{

float a,b;
 printf ("Entre com um valor inteiro: ");
  scanf ("%f",&a);
   printf ("\nEntre com outro valor inteiro: "); 
   scanf ("%f",&b); 
   printf("o valor do maior eh %1.f %% maior que o primeiro ", a>b?(b/a*100):(a/b*100) );
   
    } 
