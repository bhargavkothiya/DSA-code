\//infix to postfix with paranthesis
char stack[10];
int top = -1;

void push(char ch)
{
	stack[++top] = ch;
}
char pop()
{
	/*char ch = stack[top];
	top--;    */
	return stack[top--];
}
int priority(char ch)
{
	if(ch=='*' || ch=='/')
	{
		return 3;
	}
	else if(ch=='+' || ch=='-')
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

void convert(char infix[])
{
	char output[20];
	int i,j;
	int n1,n2;
	int p1,p2;
	char ch;

	i = 0;
	j = 0;

	while(infix[i] != '\0')
	{
		n1 = isdigit(infix[i]);
		n2 = isalpha(infix[i]);

		if(n1!=0 || n2!=0)
		{
			output[j++] = infix[i];

		}
		else if(top == -1 || infix[i]=='(')
		{
			push(infix[i]);
		}
		else if(infix[i]==')')
		{
			do
			{
				ch = pop();
				if(ch!='(')
				{
					output[j] = ch;
					j++;
				}
			}while(ch!='(');
		}
		else
		{
			p1 = priority(infix[i]);
			check:
			p2 = priority(stack[top]);

			if(p1 > p2)
			{
				push(infix[i]);
			}
			else
			{
				ch = pop();
				output[j] = ch;
				j++;
				if(top!=-1)
				{
					goto check;
				}
				else
				{
					push(infix[i]);
				}
			}
		}
		i++;
	}
	while(top!=-1)
	{
		ch = pop();
		output[j] = ch;
		j++;
	}

	output[j] = '\0';

	printf("PostFix : %s",output);
}
void main()
{
	char infix[20];
	clrscr();
	printf("Enter infix equation : ");
	scanf("%s",&infix);
	convert(infix);
	getch();
}