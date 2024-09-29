#include<stdio.h>
#include<string.h>
main()
{
	char st[10][100],aux[10];
	int  i[10],c,c2;
	
	     for(c=0;c<9;c++)
	    {
	    	printf("DIGITE UMA STRING ");
	    	scanf("%99s",st[c]);
	    	printf("DIGITE UM INTEIRO ");
	    	scanf("%d",&i[c]);
	    }
	    for(c=0;c<10;c++)
	    {
	    	sprintf(aux,"%d",i[c]);
	    	strcat(st[c],aux);
	        printf(st[c]);
		}
	

}
