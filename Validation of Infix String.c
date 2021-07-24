#include<stdio.h>  //Validation of given infix String:

int balance();                   

#define MAXSIZE 50
char infix[MAXSIZE];
char stack[MAXSIZE];
char help[MAXSIZE];
int top=-1;

void main()
{
	int temp,Number=0,sign=0;
    printf("Enter the infix expression\n");
    gets(infix);//accepted the infix expression :
    
    
    if(balance()==1){
	
    printf("The Paranthesis are  balanced\n");
    printf("\nNow checking for internal Expression......\n");int j,h=0,Q=1;
   	for(j=0;infix[j]!='\0';j++){
   		if(infix[j]=='('||infix[j]=='['||infix[j]=='{'||infix[j]=='}'||infix[j]==']'||infix[j]==')')
		   continue;
		   else
		   {
		   	help[h]=infix[j];h++;
		   }
		  // puts(help);
		   
	   } int H=strlen(help)-1;
	   if(help[0]=='*'||help[0]=='/'||help[0]=='-'||help[0]=='+'||help[0]=='^'||help[H]=='*'||help[H]=='/'||help[H]=='-'||help[H]=='+'||help[H]=='^'){
	   	printf("\nInvalid internal Expression\n");
	   	exit(0);
	   }
	   else
	   {
	   	
	   	for(temp=0;help[temp]!='\0';temp++){
	   		if((help[temp]>='0'&&help[temp]<='9')||(help[temp]>='a'&&help[temp]<='z')||(help[temp]>='A')&&help[temp<='Z'])
	   			Number+=1;
			   else
			   sign+=1;
		   }
		   //printf("%d\t%d",Number,sign);
		}
		if((Number-sign)==1)
		printf("\nYour Infix string is Valid\n");
		else
		printf("\nYour Infix String is Invalid\n");
	   }
    

    else
    printf("\nThe expression is unbalanced\n");
}
//-----------------------------------------------------------------------------------------------------------------------------------
int balance()
{
    int i;
    for(i=0;infix[i]!='\0';i++)
    {
        switch(infix[i])
        {
            case '{': top++;
                      stack[top]='{';
                      break;
            case '[': top++;
                      stack[top]='[';
                      break;
            case '(': top++;
                      stack[top]='(';
                      break;
            case '}': if(stack[top]=='{')
                      top--;
                      break;
            case ']': if(stack[top]=='[')
                      top--;
                      break;
            case ')': if(stack[top]=='(')
                      top--;
                      break;
        }
    }

    if(top==-1)
    return 1;
    return 0;
}
//------------------------------------------------------------------------------------------------------------------------------------
