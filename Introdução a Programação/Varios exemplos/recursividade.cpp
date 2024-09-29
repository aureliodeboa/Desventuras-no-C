#include<stdio.h>
int fat(int a)
{
	int b;
	if (a)
	b*=fat(a-1);
	return b;
	if(!b)
	b=1;
	
}

int main()
{ int a;
 scanf("%d",&a);
 printf("%d",fat(a));
}
