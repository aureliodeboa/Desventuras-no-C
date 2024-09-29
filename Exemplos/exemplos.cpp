#include<stdio.h>
int troca (int *a,int *b)
{ 


 int m = *a;
 *a = *b;
 *b = m;

}
int main()
{ int a=5,b=4;
	troca(&a,&b);
	printf("a=% d , b=%d",a,b);
}

