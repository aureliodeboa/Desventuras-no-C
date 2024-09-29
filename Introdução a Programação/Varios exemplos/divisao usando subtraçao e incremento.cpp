#include<stdio.h>
main()
{
	float n,b,v,resto;
	do{
	printf("dividendo  ");
	scanf("%f",&n);
    }while (n<0);
    do{
	printf("divisor  ");
	scanf("%f",&b);
    }while(b<=0);
	
	for(v=1;n-b!=0;n=n-b,v++);
	resto=n-b;
	printf("divisor %2.f o resto da divisao eh %2.f", v, resto );	
}

