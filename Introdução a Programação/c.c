#include<stdio.h>

int vetor(int *v)
{ int i,aux,j,maior=0;
   
   for(i=0;i<9;i++)
   { if(maior<*(v+i))
      { maior=*(v+i);
      }
   }
   
   return maior;
}

int main()
{ int i,v[10],*p;
   p=&v[0];
   for(i=0;i<9;i++)
   { scanf("%d",&v[i]);
      
   }
   printf("MAIOR ELEMENTO %d",vetor(*p));
}