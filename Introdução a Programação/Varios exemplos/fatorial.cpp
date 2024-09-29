#include <stdio.h>
main()
{
	int num,fat=1,c,i;
	do
	{  
	   printf("FATORIAL DE:  ");
	   scanf("%d",&num);
	} while (num<0);
	
    for(i=2;i<=num;fat=i*fat,i++);
	 printf("O FATORIAL DE  %d EH %d	", num,fat);  
}
