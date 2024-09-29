#include<stdio.h>
 int trocar(int *a,int *b)
 { 
   int c,d;
   c=*a;
   *a=*b;
   *b=c;
 }
 
 int main()
 { int a,b;
 scanf("%d",&a);
 scanf("%d",&b);
 trocar(&a,&b);
 printf("%d \n",a);
 printf("%d",b);
 }
