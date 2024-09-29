#include <stdio.h>
 int main()
 
{
	float n1,n2,media,maiormedia;
	int alunos,contador=1;
	
	
	
	
	printf("COLOQUE A QUANTIDADE DE ALUNOS DA TURMA");
	scanf("%d",&alunos);
		while(alunos)
	{
   printf("digite as duas  notas  do %d  aluno ",contador);
   scanf("%f %f", &n1,&n2);
   if (contador==1)
    maiormedia=media=(n1+n2)/2;
    else
    { 
    media= (n1+n2)/2;
    if(maiormedia<media)
    maiormedia=media;
	}
 contador++;   
 alunos--;
}
	printf("A MAIOR NOTA FOI %f ",maiormedia);
	
	
	
	
	
	
	
	
	
	
	
	
}
