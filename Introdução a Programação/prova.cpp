#include<stdio.h>
#include <math.h>
main()
{
	int h1=1,h2,m1,m2,tempo=0;
	while(h1){
		
	printf("DIGITE A HORA ATUAL \n ");
	scanf("%d",&h1);
	printf("DIGiTE O MINUTO ATUAL  \n");
	scanf("%d",&m1);
	printf("DIGITE A HORA QUE QUEIRA ACORDAR \n");
	scanf("%d",&h2);
	printf("DIGITE O MINUTO QUE QUER ACORADAR \n");
	scanf("%d",&m2);
	if(h1+h2+m1+m2==0)
	break;
	if(h1>h2)
	h2+=24;
//	if(m1>m2)

	tempo=abs(h2-h1)*60;
	tempo+= (m2-m1);
	printf("VOCE TEM %d HORAS DE  ", abs(h2-h1));
//	printf("E %d MIMUTOS DE SONO \n \n", abs(m2-m1));
	printf("QUE SAO %d ",tempo);
     }

}
