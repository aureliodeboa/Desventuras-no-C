#include <stdio.h>
main()
{
	int c,n1,d;
	
	 do 
	{ printf("UM NUMERO INT.POSITIVO  ");
	  scanf("%d",&n1);
	} while (n1<0);
	 
	 for (c=1;n1!=c; c++){
	 if(n1%c==0)	 
	 printf("DIVISOTES %d \t",c);
          }
          printf("DIVISORES %d \t",n1);
}
