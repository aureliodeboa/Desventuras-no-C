#include<stdio.h>
main()
{
	int o=0,c=0,indice;
  float vetor[10],menor;
	
 for(;o<=9;o++)
 {
 
  printf("\n VETOR [%d]=  ",o+1);
   scanf("%f",&vetor[o]);
   if (o==0){
   
   menor=vetor[o];
   indice=o;
}
   else
   if (menor>vetor[o]) {
    menor=vetor[o];   
   indice=o;}
}
 
 printf("o menor vetor eh %d ",indice+1);
 
}
