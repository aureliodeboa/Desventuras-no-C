#include<stdio.h>
main()
{
  int matriz[5][5];
   int soma=0,	p,c,l;
  for(c=0;c<=4;c++)
  {
  	 for(l=0;l<=4;l++)
  	 {  
  	    printf("MATRIZ[%d][%d]",c,l);
  	 	scanf("%d",&matriz[c][l]);
  	 	if(c==0)
  	 	soma=0;
  	 	else
  	 	if(c>l)
  	 	soma+=matriz[c][l];
  	 	
	 }
	 	 
}
printf("%d",soma);
 
}
