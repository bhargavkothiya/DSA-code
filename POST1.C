char stack[10];
int top = -1;

void push(char ch)
{
	top++;
	stack[top] = ch;
}
char pop()
{
	char ch = stack[top];
	top--;
	return ch;
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
// a + b * c - d
// abc*+d-
//
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
			output[j] = infix[i];
			j++;
		}
		else if(top == -1)
		{
			push(infix[i]);
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
	char infix[20]="a+b";
	char expected[20] = "ab+";
	clrscr();

//	printf("Enter infix equation : ");
//	scanf("%s",&infix);

	convert(infix);
	printf("\nExpected : %s",expected);

	getch();
}