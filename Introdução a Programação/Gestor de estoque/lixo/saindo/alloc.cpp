#include <stdio.h>
 #include <stdlib.h> 
main() {
 char* vetor_strings; 
 int num_elementos, comprimento_max, i; 
 printf ("Entre com o numero de elementos do vetor de strings: ");
  scanf ("%d",&num_elementos);
printf ("Entre com o comprimento maximo das strings do vetor: ");
 scanf ("%d",&comprimento_max);
  vetor_strings= (char*) calloc (num_elementos, (comprimento_max+1)*sizeof(char));
   if (! vetor_strings) 
    { printf ("\nERRO!\n"); 
	exit (1);}
for (i=0;i<num_elementos;i++)
 { printf ("Entre com a string[%d]: ",i+1);
  scanf ("%s", vetor_strings+(i*(comprimento_max+1)));
   } printf ("\nStrings contidas no vetor:\n"); 
   for (i=0;i<num_elementos;i++)
for (i=0;i<num_elementos;i++) 
printf ("\nString[%d]: %s",i+1, vetor_strings+(i*(comprimento_max+1)));
}
