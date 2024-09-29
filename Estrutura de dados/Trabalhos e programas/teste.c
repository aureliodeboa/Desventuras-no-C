#include <stdio.h>
#include <string.h>
 
int main(void)
{
   char *psRetorno;
   char sFrase[]="02/12/2020,2,12,2020,400,48,Afghanistan,AF,AFG,38041757,Asia,7.00545982";
 
   printf("\nFrase = %s", sFrase);
  /* Primeira pesquisa por espa�o em branco. */
   psRetorno = strtok(sFrase, ",");
 
   printf("\nRetorno = %s", psRetorno);
   printf("\nFrase = %s", sFrase);
 
   do
   {
      /* Nas pr�ximas chamadas, deve-se passar um ponteiro �nulo�. 
         Isto �indica� para a fun��o que a pesquisa deve continuar 
         no ponteiro anterior. */
      psRetorno = strtok('\0',","); //Demais pesquisas por , (v�rgula) ou espa�o em branco.
 
      /* Um valor nulo (NULL) � considerado sempre falso em compara��es 
         booleanas (verdadeiro ou falso). */
      if(psRetorno)
      {
         printf("\nRetorno = %s", psRetorno);
         
         
      } 
   } while(psRetorno); 
    
   return 0;
}
