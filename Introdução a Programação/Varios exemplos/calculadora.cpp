#include <stdio.h>


 int main()
 {   
  int a,b;
  char op;
  printf("DIGITE DOIS NUMEROS:   ");
  scanf("%d%d",&a, &b);
  printf ("DIGITE '+' PARA SOMAR DOIS NUMEROS \n");
  printf("DIGITE '*'PARA MULTIPLICAR \n ");
  printf("DIGITE '/'PARA DIVIDIR \n ");
  printf("DIGITE '-' PARA SUBTRAIR \n");
  
  scanf(" %c",&op);
     switch (op)
   	{ case '+':
   		printf(" O RESULTADO ENTRE A SOMA %d e  %d EH %i",a,b, a+b);
   		break;
   	case '*':
   		printf(" O RESULTADO ENTRE A MULTIPLICACAO %d E %d  %i",a,b, a*b);
   		break;
   	case '/':
   		if (b)
		{
		printf (" O RESULTADO ENTRE A DIVISAO %d  e %d EH %f",a,b, (float)a/b);
   		break;
		}
   		else 
   		printf ("OPCAO INVALIDA");
   		break;
   	case '-':
   		printf(" O RESULTADO ENTRE A SUBTRACAO %d e %d EH  %d",a,b, a-b);
   		break;
   		default: printf("OPCAO INVALIDA");
   }
 }
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 
