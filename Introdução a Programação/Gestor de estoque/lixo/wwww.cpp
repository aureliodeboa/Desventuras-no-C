#include<stdio.h>
main()
{ int i,j;
   char v[100];
   FILE *arq;
   arq= fopen("STRING.txt","w+");
   if(!arq)
   { printf("ERROOO404");}
   
    scanf("%s",v);
      for(i=0;v[i]!='\0';i++)
         { fputc(v[i],arq);
         }
   fclose(arq);
         
         arq=fopen("STRING.txt","r");
         if(!arq)
         {printf("ERRO404");}
         for(i=0;EOF;i++)
         {printf("%c",(char)getc(arq));}
         fclose(arq);
}
