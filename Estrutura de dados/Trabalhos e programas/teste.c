#include <stdio.h>
#include <string.h>
 
int main(void)
{
   char *psRetorno;
   char sFrase[]="02/12/2020,2,12,2020,400,48,Afghanistan,AF,AFG,38041757,Asia,7.00545982";
 
   printf("\nFrase = %s", sFrase);
  /* Primeira pesquisa por espaço em branco. */
   psRetorno = strtok(sFrase, ",");
 
   printf("\nRetorno = %s", psRetorno);
   printf("\nFrase = %s", sFrase);
 
   do
   {
      /* Nas próximas chamadas, deve-se passar um ponteiro “nulo”. 
         Isto “indica” para a função que a pesquisa deve continuar 
         no ponteiro anterior. */
      psRetorno = strtok('\0',","); //Demais pesquisas por , (vírgula) ou espaço em branco.
 
      /* Um valor nulo (NULL) é considerado sempre falso em comparações 
         booleanas (verdadeiro ou falso). */
      if(psRetorno)
      {
         printf("\nRetorno = %s", psRetorno);
         
         
      } 
   } while(psRetorno); 
    
   return 0;
}
