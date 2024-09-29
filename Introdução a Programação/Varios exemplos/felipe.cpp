#include <stdio.h>
main()
{
	int vivos=0, mortos=0, mortosM=0, Mpequeno=0, teste, total,idade;
	char sexo='A', vida; 
	while(sexo!='V')
   { printf("Digite M para Masculino e F para feminino (caso a quantidade de crianças seja atingida digite 'V': \n");
	 scanf("%c",&sexo);
	 setbuf(stdin,NULL);
	 switch(sexo) 
	 {
		case 'M': 
			 printf("Digite V para vivo e M para morta");
			 scanf("%c",&vida);
			 switch(vida)	
			 {
				case 'V': vivos++;
					  printf("Digite a quantidade de meses da criança: ");
					  scanf("%i",&idade);
						if(idade<=24)
						    Mpequeno++;
			        break;
				case 'M': mortos++;
					  mortosM++;
					  printf("Digite a quantidade de meses da criança: ");
					  scanf("%i",&idade);
						if(idade<=24)
						    Mpequeno++;				
		    	 }
		break;
		case 'F': 
			  printf("Digite V para vivo e M para morta");
			  scanf("%c",&vida);
			  switch(vida)	
			  {
				case 'V': vivos++;
					  printf("Digite a quantidade de meses da criança: ");
					  scanf("%i",&idade);
						if(idade<=24)
						    Mpequeno++;
				break;
				case 'M': mortos++;
					  printf("Digite a quantidade de meses da criança: ");
					  scanf("%i",&idade);
						if(idade<=24)
						    Mpequeno++;	
			 }
		break;
	 }	
   } 
   total= vivos + mortos;
   printf("A Porcentagem de Criancas mortas eh de %.2f%%",(float)mortos*100/total);
   printf("A Porcentagem de Criancas do sexo masculino morta eh de %.2f%%",(float)mortosM*100/total);
   printf("A Porcentagem de mortas com menos de 24 meses eh de %.2f%%",(float)Mpequeno*100/total);
   scanf("%i",&teste);
}
