#include<stdio.h>
#include<string.h>
int main()
{
	int i,g;
	char s[4][30],nome[30];
	for(i=0;i<4;i++)
	{  
	    
		printf("\n string[%d]=  ",i);
		scanf("%[^\n]", s[i]);
		
	}

	printf("DIGA OQUE QUER ACHAR? ");
	scanf("%s", nome);
	for(i=0;i<4;i++)
	{
		if(!strcmp(s[i],nome))
		{
			printf("ESTA NO INDICE [%d] o nome %s",i,nome);
			break;
		}
		else
		{
		 if(i==3)
		 {
		 	printf("NAO PERTENCE");
		 }
		}
	}
		
}
