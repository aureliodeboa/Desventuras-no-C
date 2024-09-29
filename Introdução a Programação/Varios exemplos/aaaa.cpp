#include<stdio.h>

 void inicializar(int *v)
 { int i;
 for(i=0;i<10;i++)
 scanf("%d",v+i);
 }
 
 void escrever(int *v)
 {
 	int i;
 	for(i=0;i<10;i++)
 	{ printf("%d",v[i]);
	}
 }

 
 int main()
  {  int i=0;
 	int v[10];
 	 inicializar(v);
 	 escrever(v);
 }
