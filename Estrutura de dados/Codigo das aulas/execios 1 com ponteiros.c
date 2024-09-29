#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	int num;
	int den;	
}RACIONAL;
void criar_racional(int num, int den,RACIONAL *r)
{
	r->num=num;
	r->den=den;
}
void multiplicar_racionais(RACIONAL *a,RACIONAL *b,RACIONAL *c)
{
	c->num= (a->num) * (b->num);
	c->den= (a->den) * (b->den);
	printf("%d/%d",c->num,c->den);
	
}
void soma_racionais(RACIONAL *a,RACIONAL *b,RACIONAL *c)
{
	c->num= (b->den * a->num)+(a->den* b->num);
	c->den= (a->den * b->den);
	printf("%d/%d",c->num,c->den);
}  
void equivalencia_racionais(RACIONAL *a, RACIONAL *b )
{
   float valor1,valor2;
	
    valor1= ((float)a->num/a->den);
    valor2= ((float)b->num/b->den);
    
	if (valor1==valor2)
    {
    	printf("EQUIVALENTES");
	}
	else
	{
		printf("NAO EQUIVALENTES");
	}
}
void Euclides(RACIONAL *rin)
{
	int a,b,aux;
	
	if (rin->num>rin->den)
	{
		a=rin->num;
		b=rin->den;
	}
	else
	{
		a=rin->den;
		b=rin->num;
		
	}
	while(b)
	{
		
		aux= (a%b);
		a=b;
		b=aux;
	   
		
	}
	rin->num = rin->num/a;
    rin->den = rin->den/a;
 
    system("cls");
    printf("%d/%d",rin->num,rin->den);
	
}
int main()
{    int a,b;
    RACIONAL *r1,*r2,*r3;
     r1=(RACIONAL*)malloc(1*sizeof(RACIONAL));
	 r2=(RACIONAL*)malloc(1*sizeof(RACIONAL));
	 r3=(RACIONAL*)malloc(1*sizeof(RACIONAL));
     
	scanf("%d",&a);
	scanf("%d",&b);
	criar_racional(a,b,r1);
	scanf("%d",&a);
	scanf("%d",&b);
	criar_racional(a,b,r2);
	
    system("cls");
	printf("QUAL OPERAÇAO DESEJA REALIZAR? ");
	scanf("%d",&a);
	
		switch (a)
		{
		  case 1: multiplicar_racionais(r1,r2,r3); break;
		  case 2: soma_racionais(r1,r2,r3); break;
		  case 3: equivalencia_racionais(r1,r2);break;	
		  case 4: Euclides(r1);break;
		}
		
		free(r1);
		free(r2);
		free(r3);	
}
