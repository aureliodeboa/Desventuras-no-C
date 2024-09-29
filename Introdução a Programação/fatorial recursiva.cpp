#include<stdio.h>
 double fat( double n)
{ 
 		
	if(n==1)
	{ 
		return 1;
	}
	else
	{
		return n*fat(n-1);
	}
	
}
int main()
{
	printf("%lf",fat(52));
	
}
