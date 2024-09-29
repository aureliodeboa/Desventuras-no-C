#include<stdio.h>
main()
{
	int a,b,num1,num2,q,resto;

	scanf("%d",&a);
	scanf("%d",&b);
	num1=a;
	num2=b;
	while(b!=0){
	
    resto=a%b;
	a=b;
	b=resto;
	if(resto)
	printf("MDC %d\n ",resto);
}
	printf("MMC %d\n",num1*num2/a);
	scanf("%d",&q);
}


