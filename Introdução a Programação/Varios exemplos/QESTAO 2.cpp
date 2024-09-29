#include <stdio.h>
main() //(X*2)/1-(X*2)/2+(X*2)/3...+(X*2)/25
{
	int X, contador;
	float acumulador=0;
	do
	{ 	 printf("Digite o valor de X: ");
		 scanf("%i",&X);
	}while(X<0);
	for(contador=1;contador<=25;contador++)
	  	{	if(contador%2)
			acumulador += (X*X)/contador ;
	   	    else
			acumulador -= (X*X)/contador ;
		}
		printf("O resultado da expressao eh igual a %.3f ",acumulador);
}
