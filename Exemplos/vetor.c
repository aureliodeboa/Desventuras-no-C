#include<stdio.h>
int main()
{
	int i;
	float vetor[5];
	
	for(i=0;i<5;i++)
	{
		printf("VETOR[%d]",i+1);
		scanf("%f",&vetor[i]);
	}
	for(i=0;i<5;i++)
	{
		printf("\n VETOR[%d]: %2.f",i+1,vetor[i]);
		
	}
	
}
