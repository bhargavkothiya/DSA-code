int a[5],f=-1,r=-1;

void push()
{
	int x;
	if( (f==0 && r==4) || r+1==f)
	{
	 printf("Queue is overflow \n");
	}
	else
	{
	printf("Enter the number : ");
	scanf("%d",&x);
	if(f==-1||r==-1)
	      {	f=r=0; }
	else if(r==4){r=0;}
	else{r++;}
	a[r]=x;
	}
	printf("f=%d,r=%d",f,r);
}
void pop()
{
	if(f==-1)
	{
	 printf("Stack is underflow \n");
	}
	else
	{
	 printf("%d is deleted\n",a[f]);
	 if(f==r)
	 {
		f=r=-1;
	 }
	 else if(f==4)
	 {
		f=0;
	 }
	 else
	 {
		f++;
	 }
	}
	printf("f=%d,r=%d",f,r);
}
void display()
{
	int i;
	if(f==-1)
	{
	 printf("Under flow");
	}
	else
	{       if(f<=r)
		{
			for(i=f; i<=r; i++)
			{
			 printf(" \n%d ", a[i]);
			}
		}
		else
		{
		  for(i=f; i<=4; i++)
			{
			 printf(" \n%d ", a[i]);
			}
		  for(i=0; i<=r; i++)
			{
			 printf(" \n%d ", a[i]);
			}
		}
	}
	printf("f=%d,r=%d",f,r);
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