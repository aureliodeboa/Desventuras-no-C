#include<stdio.h>
typedef struct{
	float x,y;
}ponto;

main()
{  ponto ponto2;
	scanf("%f",&ponto2.x);
	scanf("%f",&ponto2.y);
	printf("%f",(ponto2.x)-(ponto2.y));
	
}
