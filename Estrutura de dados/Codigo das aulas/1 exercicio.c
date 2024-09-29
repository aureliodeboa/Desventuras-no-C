#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	int n;
	int d;	
}RACIONAL;
void somar(RACIONAL *a,RACIONAL *b)
{
    RACIONAL c;
    
    c.d=((a->d)* (b->d));
    c.n=(((a->n)* (b->d))+((a->d)*(b->n)));
    
    printf("\n %d",c.n);
    printf("\n %d",c.d);
    
}
RACIONAL  *criar(RACIONAL *a)
{   
   	a=(RACIONAL*) malloc(1*sizeof(RACIONAL));
    
    if(!a){
     	printf("ERRO");
	}
	else{
	
	 
	printf(" \n NUMERADOR  ");
	scanf ("%d", &(a->n));
	printf(" \n DENOMINADOR ");
	scanf("%d", &(a->d));
	return (a);
	}
} 
RACIONAL *euclides(RACIONAL *x)
{
	int a,b,r,q;
	if(x->n>x->d)
	{
		a=x->n;
		b=x->d;
	}
	else
	{
		a=x->d;
		b=x->n;
			
	}
	while(b)
	{
		r=(a%b);
		a=b;
		b=r;
	}
	x->d/=a;
	x->n/=a;
	return(x);
}
int main()
{   
    int i,j;
    
	a=criar(a);
	a=euclides(a);
	printf("O VALOR SIMPLIFICADO EH %d/%d",a->n,a->d);
  	//b=criar(b);
	//somar(a,b);
	
}
