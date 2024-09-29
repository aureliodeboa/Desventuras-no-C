#include<stdio.h>
int main()
{
	int i=0,aux=0;
	
    do
	{
    	aux+=++i;	
    	printf("\n \t %d  o n= %d",i,aux);
	} while (i+aux<100);
	
}
