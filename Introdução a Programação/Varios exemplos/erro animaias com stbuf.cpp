#include <stdio.h>
main()
{ 
float f;
char c;
printf ("entre com um real");
scanf("%f", &f);
printf("entre com um caractere:  ");
setbuf(stdin,NULL);
scanf("%c", &c);
printf("\n|%c|%f\n",c,f);
	
	
	
	
	
	
	
	
	
	
}
