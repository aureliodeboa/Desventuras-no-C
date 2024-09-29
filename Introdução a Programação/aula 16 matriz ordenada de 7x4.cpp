#include<stdio.h>

main()
{   int c,l,p;
	float matriz[7][4];
	  
	    
		for( c=0;c<=7;c++)
		{
		
		  for(l=0;l<=7;l++)
		  {
		    scanf("%f",&matriz[c][l]);
				
		  }
	    }
	    
	    	for( c=0;c<=7;c++)
		{
		
		  for(l=0;l<=7;l++)
		  {
		    printf("%2.f",&matriz[c][l]);
				
		  }
	    }
	 
}
