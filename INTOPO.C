#include<stdio.h>
char stack[20];
int top=-1;

void push(char a)
{
    top++;
    stack[top]=a;
}
char pop()
{
    char b=stack[top];
    top--;
    return b;
}
int priority(char c)
{
	if(c=='*'||c=='/')
	return 3;
	else if(c=='+'||c=='-')
	return 2;
	else
	return 1;
}

void infixTopostfix(char a[20])
{
	char result[20];
	int i,j;
	int n1,n2;
	int p1,p2;
	char ch;
	i=j=0;
	while(a[i]!='\0')
	{
	    n1=isdigit(a[i]);
	    n2=isalpha(a[i]);
	    if(n1!=0 || n2!=0)
	    {
	      result[j]=a[i];
	      j++;
	    }
	    else if(top==-1)
	    {
	     push(a[i]);
	    }
	    else
	    {
	       p1=priority(a[i]);
	       check:
	       p2=priority(stack[top]);
	       if(p1>p2)
	       {

		push(a[i]);
	       }
	       else
	       {
		 ch=pop();
		 result[j]=ch;
		 if(top!=-1)
		 {
		   goto check;
		 }
		 else
		 {
		  push(a[i]);
		 }
	       }
	    }
	    i++;
	}
	while(top!=-1)
	{
	  ch=pop();
	  result[j]=ch;
	  j++;
	}
	result[j]='\0';
	printf("Postfix : %s",result);
}


void main()
{
	char a[20];
	clrscr();
	printf("Enter the equation : ");
	gets(a);
	infixTopostfix(a);
	getch();

}
