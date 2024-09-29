#include <stdio.h>

main()
{
	int n1,n2,mmc=1,d=2;
	printf("Digite o primeiro numero: ");
	scanf("%d",&n1);
	printf("\nDigite o segundo numero: ");
	scanf("%d",&n2);
	while(n1>1 || n2>1)
	{
		if(n1%d==0 || n2%d==0)
		{
			if(n1%d==0 && n2%d==0)
			{
				n1=n1/d;
				n2=n2/d;
				mmc*=d;
			}
			else
			{
				if(n1%d==0)
				{
					n1=n1/d;
					mmc*=d;
				}
				else
				{
					n2=n2/d;
					mmc*=d;
				}
			}
		continue;
		}
		d++;
	}
	printf("\nO mmc dos numeros informados eh: %d\n",mmc);
}