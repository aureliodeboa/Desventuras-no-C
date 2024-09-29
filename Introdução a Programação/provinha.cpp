#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	int i,j=0;
	char  str[40],str2[40];
	
	scanf("%s",str);
	for(i=0;i<40;i++)
	{
		if(!isdigit(str[i]))
		{ 
			str2[j]=str[i];
			j++;
		}
	}
	printf("%s",str2);
}
