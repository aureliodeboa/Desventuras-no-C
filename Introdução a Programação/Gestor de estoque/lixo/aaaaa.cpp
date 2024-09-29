#include<stdio.h>
main()
{
	char str1[]="hudson";
	char str2[7];
	int i,j,tamanho;
	
	for(i=0;str1[i]!='\0';i++);
	tamanho=i;
	i=tamanho-1;
	for(j=0;j<=tamanho;j++,i--)
	{
		str2[j]=str1[i];
	}
	str2[7]='\0';
	printf("%s",str2);
}
