#include <stdio.h>>
 int main()
{
float n1,n2, media, maiormedia;
int alunos,contador=1;

 printf("qual a quantidade de alunos na SALA:  ");
 scanf("%d",&alunos);
   
   while(contador<=alunos)
   { 
     printf("A PRIMEIRA NOTA DO %d  ALUNO:  ",contador);
     scanf("%f",&n1);
     printf("A SEGUNDA NOTA DO %d ALUNO:  ",contador);
     scanf("%f",&n2);
       if(contador==1)
         {
         	maiormedia=media=(n1+n2)/2;
	     }  
	   else
	   {
	   	 media=(n1+n2/2);
	   	 if(maiormedia<media)
	   	 maiormedia=media;
	   	 }
 contador++;
   }
 printf("A MAIOR MEDIA DOS %d ALUNOS, FOI %4.f :  ",alunos,maiormedia);
}
