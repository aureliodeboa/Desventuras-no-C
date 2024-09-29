#include<stdio.h>
main()
{  float matriz[7][4];
   int	p,c,l;
   
   for(c=0;c<=6;c++){
   
     for(l=0;l<=3;l++)
     {
     	printf("MATRIZ[%d][%d]",c, l);
     	scanf("%f",&matriz[c][l]);
     	
     }
}
     for(c=0;c<=6;c++){
	 
     printf("\n|");
     for(l=0;l<=3;l++)
     {
     	printf(" %10.2f",matriz[c][l]);   	
}
printf("|");
}
}
