#include <stdio.h>
void incrementa (int *a,int b)
{
*a+=b;
}
main ()
{
int num;
num=100;

printf ("\nValor de num antes da chamada %s%d",
"da funcao: ", num);
incrementa (&num,50);
printf ("\nValor de num depois da chamada %s%d","da funcao: ", num);
}
