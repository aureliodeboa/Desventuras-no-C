#include<stdio.h>
int main()
{
    int soma3, soma5, total, i;

        for(i=0;i<1000;i+=3)

            soma3=soma3 + i;

        for(i=0;i<1000;i+=5)

            soma5= soma5 + i;

    printf("\nA soma é: %d\n", total=soma3+soma5);

}
