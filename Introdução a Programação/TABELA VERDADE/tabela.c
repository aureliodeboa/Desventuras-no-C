#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *Realloc( int t, char *Z )
{
  Z = (char*) realloc(Z, t*sizeof(char));
  if( Z == NULL )
  {
    printf("SEM ESPACO PARA REALOCAR ");
    exit(1);
  }
  else
  {
    return Z;
  }
}
int *Malloc(int t, int *Z)
{
  Z=(int*)malloc(t*sizeof(int));
  if( Z == NULL )
  {
    printf("SEM ESPACO PARA ALOCAR ");
    exit(1);
  }
  else
  {
    return Z;
  }
  
}
int ler(void)
{   
  FILE *arq;
  char *exp;
  int i=1,t=1,LEI;
  arq=fopen("entrada.txt","r");
  if(arq==NULL)
  {
    printf("ERRO AO LER AQUIVO");
  }
  else
  {
    exp=(char*)malloc(t*sizeof(char));
    if(exp==NULL)
    {
      printf("ERRO AO ALOCAR MEMORIA");
      exit(1);
    }
    
    while(!feof(arq))
    {
      t++;
      exp= Realloc(t,exp);
      fscanf(arq,"%s",exp);
      
    }
    if(!strcmp(exp,"!(p&&Q)==(!p)||(!q)"));
    {
      LEI=1;
    }
    if(!strcmp(exp,"!(p||Q)==(!p)&&(!q)"))
    {
      LEI=2;
    }
    
    fclose(arq);
  }
  return LEI;
};

int *pp(void)
{
  int *p,i,v=1,f=0;
  
  p= Malloc(4,p);
  
  for(i=0;i<4;i++)
  {
    switch (i)
    {
      case 0: p[i]=v;break;
      case 1: p[i]=v;break;
      case 2: p[i]=f;break;
      case 3: p[i]=f;break;
    }
  }
  return p;
}

int *qq(void)
{
  int *q,i,v=1,f=0;
  
  q=Malloc(4,q);
  for(i=0;i<4;i++)
  {
    switch (i)
    {
      case 0: q[i]=v;break;
      case 1: q[i]=f;break;
      case 2: q[i]=v;break;
      case 3: q[i]=f;break;
    }
  }
  return q;
}

void processamento1(int LEI,int *p,int *q )
{
  FILE *arq;
  int i,*peq,*pouq,*npounq,*npenq;
  peq=   Malloc(4,peq);
  pouq=  Malloc(4,pouq);
  npounq=Malloc(4,npounq);
  npenq= Malloc(4,npenq);
  
  arq=fopen("saida.txt","w+");
  if(arq==NULL)
  {
    printf("NAO FOI POSSIVEL ENCONTRAR O PONTEIRO DE ARQUIVO DA SAIDA");
    exit(1);
  }
  
  for(i=0;i<4;i++)
  {
    if((p[i]==1) && (q[i]==1))
    {
      peq[i]=1;
      npenq[i]=0;
    }
    else
    {
      npenq[i]=0;
      peq[i]=0;
      if(p[i]==0&&q[i]==0)
      {
        npenq[i]=1;
      }
      
    }
    if((p[i]==1)||(q[i]==1))
    {
      npounq[i]=1;
      pouq[i]=1;
      
      if((p[i]==1)&&(q[i]==1))
      {
        npounq[i]=0;
      }
      
    }
    else
    {
      
      npounq[i]=1;
      pouq[i]=0;
    }
    
  }
  
  
  
  
  if(LEI==1)
  {
    
    fprintf(arq,"%s","\n |---------------------------------------------|");
    fprintf(arq,"%s","\n | P  |  Q  | NOT(P AND Q) | NOT(P) OR NOT(Q)  |");
    fprintf(arq,"%s","\n |    |     |              |                   | ");
    fprintf(arq,"\n |%3d | %3d |      %3d     |       %3d         |",p[0],q[0],!peq[0],npounq[0]);
    fprintf(arq,"\n |%3d | %3d |      %3d     |       %3d         |",p[1],q[1],!peq[1],npounq[1]);
    fprintf(arq,"\n |%3d | %3d |      %3d     |       %3d         |",p[2],q[2],!peq[2],npounq[2]);
    fprintf(arq,"\n |%3d | %3d |      %3d     |       %3d         |",p[3],q[3],!peq[3],npounq[3]);
    
    
  }
  if(LEI==2)
  {
    
    
    fprintf(arq,"%s","\n |---------------------------------------------|");
    fprintf(arq,"%s","\n | P  |  Q  | NOT(P OR  Q) | NOT(P) AND NOT(Q) |");
    fprintf(arq,"%s","\n |    |     |              |                   | ");
    fprintf(arq,"\n |%3d | %3d |      %3d     |       %3d         |",p[0],q[0],!pouq[0],npenq[0]);
    fprintf(arq,"\n |%3d | %3d |      %3d     |       %3d         |",p[1],q[1],!pouq[1],npenq[1]);
    fprintf(arq,"\n |%3d | %3d |      %3d     |       %3d         |",p[2],q[2],!pouq[2],npenq[2]);
    fprintf(arq,"\n |%3d | %3d |      %3d     |       %3d         |",p[3],q[3],!pouq[3],npenq[3]);
    
  }
  
  
  
  
 
  free(p);
  free(q);
  free(pouq);
  free(peq);
  free(npounq);
  free(npenq);
  fclose(arq);
  
  
}

int main()
{
  int LEI;
  LEI=ler();
  processamento1(LEI,pp(),qq());
  
}



