int a[5],tos=-1;

void push()
{
	int x;
	if(tos==4)
	{
	 printf("Stack is overflow \n");
	}
	else
	{
	printf("Enter the number : ");
	tos++;
	scanf("%d",&x);
	printf("%d added",x);
	a[tos]=x;
	}
}
void pop()
{
	if(tos==-1)
	{
	 printf("Stack is underflow \n");
	}
	else
	{
	 printf("%d is deleted\n",a[tos]);
	 free(a[tos]);
	 tos--;
	}
}
void display()
{
	int i;
	if(tos==-1)
	{
	 printf("Under flow");
	}
	else
	{
	for(i=0; i<=tos; i++)
	{
	 printf(" \n%d ", a[i]);
	}
	}

}
void main()
{
  int ch;
  clrscr();
  do
  {     clrscr();
	printf("\n\npress 1 for push \n");
	printf("press 2 for pop \n");
	printf("press 3 for display \n");
	printf("press 0 for exit \n");
	printf("Enter your choice :  ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: push();
			break;
		case 2: pop();
			break;
		case 3: display();
			break;
		case 0: printf("BYE\nThank you");
			break;
		default: printf("Invalid choice");
	 }
	 getch();
   }
	 while(ch!=0);

}