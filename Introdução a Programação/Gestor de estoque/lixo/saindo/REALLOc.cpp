#include<stdio.h>
#include<stdlib.h>
main()
{
	int i,j,v,aux;
	char *str;
	
	scanf("%d",&i);
	scanf("%d",&j);
	aux=i*j;
	i=j;
	v=j;
        str= (char*)calloc(aux,sizeof(char));
        if(!str)
        { printf("ERORORORO");
		}
        for(j=0;j<aux;j+=v)
        { scanf("%s",str+j);
		}
		for(i=0;i<aux;i+=v)
		{
			printf("%s\n",str+i);
		}
}
