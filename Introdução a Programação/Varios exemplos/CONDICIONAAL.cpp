#include<stdio.h>
main()
{
	float a,b;
	printf("DIGITE A  ");
	scanf("%f",&a);
	printf("DIGITE B ");
	scanf("%f",&b);
	printf("O VALOR DE A eh %1.f %% MAIOR QUE B ",a>b? b*100/a:a*100/b);
}
