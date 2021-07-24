#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

double prefix(char expr[])
{
	double stk[50],op1,op2;
	char symb;
	int i=0,t=-1;
	do {
		symb=expr[i];
		i++;
		if(symb>='0'&&symb<='9')
		stk[++t]=symb-'0';
		else
		{
			op2=stk[t--];
			op1=stk[t--];
			switch(symb)
			{
				case'+':stk[++t]=op1+op2;break;
				case'-':stk[++t]=op1-op2;break;
				case'*':stk[++t]=op1*op2;break;
				case'/':stk[++t]=op1/op2;break;
				case'^':stk[++t]=pow(op1,op2);break;
				case'$':stk[++t]=pow(op1,op2);break;
				
			}
		}
	}while(expr[i]!='\0');
	return(stk[t]);
}
main()
{
	char expr[50],help[50];int i,length,j;
	double  b;
for(i=1;;i++)
 	{
	printf("\n%d"".Enter the Prefix Expression\n ",i);
	gets(expr);
	strrev(expr);
	puts(expr);
	b=prefix(expr);
	printf("Value of given Prefix String is:=%lf\n",b);
	printf("********************************************************************************************************************");
   }
}

