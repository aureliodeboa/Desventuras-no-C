#include<stdio.h>
main()
{ 
  int cont,valor;
  double soma;
  cont=1,valor=1,soma=0;
  
  for (;cont<=51; cont++){
  
  soma=soma+ (1/(valor*valor*valor));
  valor=valor+2;
}
  printf("resultado %lf ",soma);
}
