#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char *Realloc( int t, char *Z )
{
    Z = (char*) realloc(Z, t*sizeof(char));
    if( Z == NULL )
	{
        printf("SEM ESPACO PARA REALOCAR ");
        exit(1);
    }
    else
	{
    	return Z;
	}
}

char *ler(void)
{    
    
    char *valor;
    int t=1;
    FILE *arq;
	arq=fopen("entrada.txt","r");
	if(arq==NULL)
	{
		printf("ERRO AO LER AQUIVO");
	}
	else
	{  
		valor=(char*)malloc(t*sizeof(char));
		if(valor==NULL)
		{
			printf("ERRO AO ALOCAR MEMORIA");
			exit(1);
		}
		
	    	while(!feof(arq))
			{  
			    t++;
				valor= Realloc(t,valor);
				fscanf(arq,"%s",valor);
				
			}
			
		fclose(arq);	
	}

	return valor;
};

int tamanho(char *valor)
{ 
	 int tan;
	tan=strlen(valor);
	return tan;
}

int *transformar(char *valor)
{ 
	int i,tan,*vetor;
	 
	tan=tamanho(valor);
	vetor=(int*)malloc(tan*sizeof(int));
		if(valor==NULL)
		{
			printf("ERRO AO ALOCAR MEMORIA");
			exit(1);
		}
		for(i=0;i<=tan;i++)
		  {
			vetor[i]=valor[i]-'0'; //achei na internet que isso funciona para tirar apenas um carctere da string
		  } 
	return vetor;
}

int numero(char *valor)
{
 int num;
     sscanf(valor,"%d",&num);
 return num;
}

int narcisista(int tan,int *vetor,int num)
{
	int i, aux=0;
	for(i=0;i<tan;i++)
	{
	  aux+= (int)pow((double)vetor[i],(double)tan);
	}
	if(aux==num)
	{
		 return 1;
	}
	else
	{  
		return 0;
	}
}

void saida(int nar)
{  
  FILE *arq;
  
  		
		arq=fopen("saida.txt","w+");
		if(arq==NULL)
		{
			printf("ERRO SAIDA DO ARQUIVO");
			exit(1);
		}
		else
		{ 
		  	if(nar)
		  	{
		  		fprintf(arq,"%s","O NUMERO E NARCISISTA!");
		  	}
			else
			{
				fprintf(arq,"%s","O NUMERO NAO E NARCISISTA!");
			}    
	      
		}
		
  fclose(arq);	
}

int main(void)
{   
   
	int  nar ,*vetor;
    char *valor;
   
   	    valor=ler();
   	    
    	vetor=transformar(valor);
    	
        nar=narcisista(tamanho(valor),vetor,numero(valor));
        
        saida(nar);
        
	free(valor);
	free(vetor);
	
	
//	printf("AURELIODEBOA");
  return 0;
}
