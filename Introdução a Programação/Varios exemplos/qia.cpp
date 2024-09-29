#include <stdio.h>
#include<conio.h>
#include<stdlib.h>


 long int fat(long int n)
{
if (n)
return n*fat(n-1);
else
return 1;
}




int main()
{  
   long int n,num;
	scanf("%ld",&n);
	
   printf("FATORIAL  %ld ",fat(n));	
	
}
