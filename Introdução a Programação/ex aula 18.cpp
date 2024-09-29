#include<stdio.h>
main()
{
	char nome[10][100],*p;
	int i,o;
	printf("DIGIETE VA \n");
	for(i=1,p=&nome[0][0],o=0;i<=10;i++,p+=100)
    {
	  
	  scanf("%s",p);
	 
    }
    for(i=1,p=nome[0];i<=10;i++,p+=100)
	  printf("\n %s",p);
	  
	  
	  
}
