#include <stdio.h> 
main () 
{ int a;
 char b;
  b='B';
 printf ("nº de bytes da variavel b = %d\n", sizeof (b));
  printf ("conteudo da variavel b = %d\n", b);
   a=b; 
   printf ("nº de bytes da variavel a = %d\n", sizeof (a));
    printf ("conteudo da variavel a = %d\n", a);
}
