#include <stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
int mes;
char *nomemes [] = {"Janeiro", "Fevereiro", "Março",
"Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro",
"Outubro", "Novembro", "Dezembro"};
if(argc == 4)
{
mes = atoi(argv[2]);
if (mes<1 || mes>12)
printf("Erro!\nMes invalido!");
else
printf("\n%s de %s de 20%s", argv[1],nomemes[mes-1], argv[3]);
}
else
printf("Erro!\nUso: data dia mes ano, todos inteiros");
return 0;
}
