#include <stdio.h>
#define c 3
#define l 3
#define a 3

int main()
{
    int matriz[c][l], i, j, maiorquant,x;
    float soma, custo[a],res;
  //letra.a
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("armazem [%d] produto[%d]: ",i+1, j+1);
            scanf("%i", &matriz[i][j]);
            setbuf(stdin,NULL);
        }
    }
    //letra.b
    for(i=0;i<l;i++){
        soma=0;
        for(j=0;j<c;j++){
      soma += matriz[i][j];
     }
     printf("no armazem %d existem %f produtos\n", i+1, soma);
 }
    //letra.c
    for(i=0;i<l;i++){
        maiorquant=0;
        if(matriz[i][2]>maiorquant)
        maiorquant=matriz[i][1];
        x=i;
    }
    printf("a maior quantidade do produto 2 esta no armazem: %d\n\n", x);

        setbuf(stdin,NULL);

      ///////////////!!!!!!//letra.d.a
    for(i=0;i<l;i++){

        printf("custo do %d produto no armazem %d: ",i+1,i+1);
        scanf("%f", &custo[i]);}
            for(j=0;j<c;j++){
                res = custo[i]*matriz[j][i];
                     soma += res;
                printf("o custo do %d produto eh: %f\n",j+1 ,soma);
            soma=0;
    }







 
    for(i=0;i<l;i++){
        soma=0;
            for(j=0;j<c;j++){

        soma+=matriz[i][j] * custo[i]; }


     printf("a quantidade de produto %d eh: %d\n" , j+1, soma);
    }

 



return 0;
}
