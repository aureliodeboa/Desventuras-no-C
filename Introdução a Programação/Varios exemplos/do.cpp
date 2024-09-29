#include <stdio.h>
int main()
{
	float x=0,n1;
	float contador=0;
	do 
	{ 
		printf("foneca numeros naturais e quando quiser a media forneça um valor negativo: ");
		scanf("%f",&n1);
		if(n1 >= 0)
		{
			x += n1;
			contador++;
		}
	}while(n1>=0);
	printf("a media dos numeros fornecidos foi %.2f",x/contador);
}
