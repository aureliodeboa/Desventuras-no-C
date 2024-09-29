#include <stdio.h>
int main()
  { 
	float acumulador=0, n1;
	float contador=0;
    do 
        { printf("foneca valores reais: ");
          scanf("%f",&n1);
       	 if(n1>=0)
       	 {
			
			acumulador +=n1;
		      
       	
       	contador++;
		}
	     }  	
	while(n1>=0);
	printf("a media dos numeros reais eh: %f ", acumulador/contador);
	
  }
