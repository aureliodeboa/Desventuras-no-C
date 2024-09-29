#include<stdio.h>
main()
{ 
 float n[10],vemen;
 int contador,i,menor;
 for(contador=1;contador<=10;contador++){
 
 printf("DE O PAPO VETOR [%d]  ",contador);
 scanf("%d",&i);
 n[contador]=i;
}
  for(contador=1;contador<=10;contador++)
  {
  	if(contador==1)
  	{
	  
  	vemen=n[1];
  	menor=contador;
    }
	else
	if (vemen>=n[contador]) 
	{
	
	vemen=n[contador]; 
    menor=contador;
   }
  }
  printf("menor VETOR TEM INDICE %d \n ",menor);
}
