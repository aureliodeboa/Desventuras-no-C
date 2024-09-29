#include<stdio.h>
main ()
{
	int valor,c,d;
	 
	 valor=123;
  while(valor)
  { 
  printf("VALOR:  \n");
  scanf("%d",&valor);
  d=(valor%10*100)+((valor/10)%10*10)+(valor/100);
    printf("%d\n",d);
  }

}
