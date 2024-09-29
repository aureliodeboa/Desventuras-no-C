#include<stdio.h>
main()
{
	int fat,n,contador,acum;
	scanf("%d",&n);
	for(contador=1,fat=1,acum=0;contador<=n;contador++)
    fat=contador*fat;
        


	printf("%d",fat);
}
