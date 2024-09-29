#include<stdio.h>
main()
{
int num,c,d;
num=1; 
 while (num)
 {
 
    printf("VALOR:  \n");
    scanf("%d",&num);
    if (num==0)
    break;
    
 for(c=1;c*c<=num;c++);
 c=c-1;
 if(c*c==num)
 printf("%d EH UM QUADRADO PERFEITO",c);
 else
 printf("NAO EH UM QUADRADO PERFEITO"); 
}
}
