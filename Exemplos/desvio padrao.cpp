#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,acumulador=0,vetor[10]={5,6,8,4,6,7,3,2,0,9};
	float aux=0,media,valor;
	for(i=0;i<10;i++)
    {
		acumulador+=vetor[i];
	}
	media= (float)acumulador/10;

	
	for(i=0;i<10;i++)
	{
		 valor=vetor[i]-media;
	 aux+= ((valor*valor)/9);	
	}
	aux=sqrt(aux);
	printf(" %f",valor);
}
