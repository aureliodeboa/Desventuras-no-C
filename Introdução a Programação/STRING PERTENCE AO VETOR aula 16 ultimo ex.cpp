#include <stdio.h>
#include<string.h>
main ()
{
char strings [5][100],nome[50];
int count,v;
for (count=0;count<5;count++)

{
printf ("\nDigite a %d string do vetor: ", count+1);
scanf ("%s", strings[count]);
}
printf("DIGITE PRA SABER SE PERTENCE AO VETOR  ");
scanf("%s",nome);

for (count=0; count<5; count++)
{  
v=!strcmp(nome,strings[count]);
   if(v)
    {
	  printf("PERTENCE MEU REI NO INDICE [ %d ]",count+1 );
	  break;
    }
    else
    if(count==4)
    printf("\n NAO PERTECE A ESSE VETOR");
}

}
