#include<stdio.h>
main()
{
	int i,*p,vetor[3][4];
	p=&vetor[0][0];
	    for(i=1;i<=12;i++)
	    {
		*(p++)=i;
	        if(i%4==1)
	        {
	         printf("|");
	        }
	       if(i<10)
	        printf("0%d ",i);
	        else
	        printf("%d ",i);
	       
	    if(i%4==0)
	    {
	    printf("| \n");
	    }
	    
	     
	
	
}
}
