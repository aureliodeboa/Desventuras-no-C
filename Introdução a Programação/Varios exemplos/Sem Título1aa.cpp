#include<stdio.h>
int main()
{
	float alt[100],maior=0,valor;
	int i=1;
	alt[0]=0;
	
	
	do
	{  scanf("%f",&alt[i]);
	  valor=alt[i];
	  if(alt[i]!=-1){
	  maior+=alt[i];
	  i++;
      }
	  
	  
	}while(valor!=-1);
	i--;

	printf("%.2f",(maior/i));

}
