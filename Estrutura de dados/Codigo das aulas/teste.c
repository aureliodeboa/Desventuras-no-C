#include<stdio.h>
typedef struct 
{
	int num;
	int den;	
}RACIONAL;

int main()
{
	int a=4,b=5;
	RACIONAL *r;
	
	 r=(RACIONAL*)malloc(1*sizeof(RACIONAL));
	 
    (*r).den=a;
	(*r).num=b;
	printf("%d/%d",r->num,r->den);
}
