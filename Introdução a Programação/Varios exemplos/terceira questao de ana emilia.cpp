#include<stdio.h>
main ()
{
	int cria,mas=0,fem=0,momas=0,v=0,topvivo=0,morto=0,contador;
	float a,b,c;
     char sexo,vivo;	
	printf("quantas criancas nasceram no periodo ? \n" );
	scanf("%d", &cria);
	contador=cria;
	 while (cria)
	 {
	 
	  printf("sexo f para feminino e m para masculo \n ");
	  scanf("%c%*c", &sexo);
	  switch(sexo)
	  { 
	  case 'f': 
	  fem++;
	  printf("vivo? s/n? \n");
	  scanf("%c", &vivo);
	   if (vivo=='s')
	   printf("mais de 24 meses de vida s/n? \n");
	   scanf("%c", &vivo);
	       if(vivo=='s')
	        topvivo++;
	   else 
	   morto++;
	   break;
	        
	    case 'm': 
		mas++;
		printf("vivo? s/n \n");
		scanf("%c", &vivo);
		if(vivo=='s'){
		
		 printf("viveu mais de 24 meses? s/n");
		 scanf("%c", &vivo);
	     }
		 if (vivo=='s')
		 topvivo++;
		     
	   else 
	   momas++;
	   morto++;
	   break;
	   cria--;
      }
	  }
       a=morto/contador*100;
       b=momas/contador*100;
       c=topvivo/contador*100;
	         printf("PORCENTGEM DE CRIANÇAS MORTAS %f%%\n", a);      
	         printf("PORCENTAGEM DE MENINOS MORTOS %f%% ",b);
	         printf("PORCENTAGEM DE CRIANÇAS QUE VIVERAM MAIS DE 24mes %f%%",c);
	   }        
	    

	  

