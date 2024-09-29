#include<stdio.h>
#include <stdlib.h>


int main()
{
		float *matriz;
	    int aux,l,c;
	scanf("%d",&l);
	scanf("%d",&c);
	matriz= (float *) malloc((l*c)*sizeof(float));
	 
	 for(aux=0;aux<l*c;aux++)
	{
	 scanf("%f",matriz);
	 matriz+=aux;	
     }
    
     for(aux=0;aux<l*c;aux++)
     {printf("%f \n",matriz);
      matriz+=aux;
	 }
}
