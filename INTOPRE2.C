//infix to prefix with parenthesis

#include<string.h>
char stack[20];
int top=-1;

void push(char ch)
{
  stack[++top]=ch;
}

char pop()
{
  return stack[top--];
}

int priority(char ch)
{
	if( ch=='*'|| ch=='/')
	{return 3;}
	else if( ch=='+'|| ch=='-')
	{return 2;}
	else
	{return 1;}
}

void convert(char input[])
{
	char ch,result[20];
	int i,j,n1,n2,p1,p2;
	i=j=0;
	strrev(input);
	while(input[i]!='\0')
	{
	  n1=isdigit(input[i]);
	  n2=isalpha(input[i]);

	  if( n1!=0 || n2!=0 )
	  {
	    result[j++]=input[i];
	  }
	  else if( top==-1 || ch==')')
	  {
	    push(input[i]);
	  }
	  else if(input[i]=='(')
	  {
		   do{
			ch=pop();
			result[j]=ch;
			j++;

	      }while(stack[top]!=')');
	  }
	  else
	  {
	   p1=priority(input[i]);
	   check:
	   p2=priority(stack[top]);
	   if(p1>=p2)
	   {
	     push(input[i]);
	   }
	   else
	   {
	     result[j]=pop();
	     j++;
	     if(top!=-1)
	     {
		goto check;
	     }
	     else
	     {
	       push(input[i]);
	     }
	   }

	  }
	  i++;
	}

	while(top!=-1)
	{
	 result[j]=pop();
	 j++;
	}
	result[j]='\0';
	strrev(result);
	printf("\nInfix to postfix : %s",result);
}

void main()
{
	char infix[20]="a*(b+c)/d";
	clrscr();
	printf("input : %s\n",infix);
	printf("Expecated output : /*a+bcd\n");
	convert(infix);
	getch();
}