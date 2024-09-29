#include <stdio.h> 
 main ()
 { 
 int a; 
 char b; 
 
a=120;
 printf ("nº de bytes da variavel a = %d\n", sizeof (a));
 printf ("conteudo da variavel a = %d\n", a);
  b=(char)a;
  /*sem perda de dados*/
   printf ("nº de bytes da variavel b = %d\n", sizeof (b)); 
   printf ("conteudo da variavel b = %d\n", b);
}
