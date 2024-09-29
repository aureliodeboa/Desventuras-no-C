#include <stdio.h>
  main ()
  {
int alunos,contador=1; 
float n1,n2,media,maiormedia;
     
  	printf("Quanto alunos?   ");
  	scanf("%i",&alunos);
     	while(contador<=alunos)
    {
		 
     	printf(" primeira nota do %d aluno   ",contador);
     	scanf("%f",&n1);
     	printf(" segunda nota do %d aluno  ",contador++);
     	scanf("%f",&n2);
     	
     media=(n1+n2)/2;
     if(contador==2)
     maiormedia=media;
     else
	 {
	 if(maiormedia<media)
     maiormedia=media;
     }
  	//contador++;
  	//alunos--;
    }
    printf("maior MEDIA foi %.2f  ",maiormedia);
    
  }
