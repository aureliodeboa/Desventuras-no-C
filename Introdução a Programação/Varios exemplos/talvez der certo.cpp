#include <stdio.h>
main() //(X*2)/1-(X*2)/2+(X*2)/3...+(X*2)/25
{
	int X, contador;
	float acumulador=0;
	int par=2,imp=1;
	do
	{ 	 printf("Digite o valor de X: ");
		 scanf("%i",&X);
	}while(X<0);
	for(contador=1;contador<=13;contador++)
	  	{	
			acumulador += (X*X)/imp;
			acumulador -= (X*X)/par;
			imp=imp+2;
			par=par+2;
		}
		printf("O resultado da expressao eh igual a %.3f ",acumulador+(X*X)/26);
}
