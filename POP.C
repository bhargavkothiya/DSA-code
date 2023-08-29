int tos=-1,a[5];
void main()
{
  int n,i,size;
  clrscr();
  do
  {

	printf("\n\n1.push\n");
	printf("2.pop\n");
	printf("3.display\n");
	printf("0.Exit\n");
	printf("Enter your choice : ");
	scanf("%d",&n);

	switch(n)
	{
	  case 1:push(a,size);
		 break;
	  case 2:pop(a,size);
		 break;
	  case 3:display(a,size);
		 break;
	  case 0:printf("Thank you ");
		 break;
	  default:printf("Invalid choice");
		 break;

	}
	getch();
	clrscr();
  }
  while(n!=0);

  getch();
}

display(int a[],int size)
{
    int i;
    printf("Array : ");
    for(i=0; i<=tos; i++)
    {
	printf(" %d",a[i]);
    }
    return size;
}

int push(int a[],int size)
{
	if(tos==4)
	{
		printf("Over flow");
	}
	else
	{       int temp;
		printf("Enter number : ");
		scanf("%d",&temp);
		tos++;
		printf("%d added",temp);
		a[tos]=temp;

	}
	return tos;
}
int pop(int a[],int size)
{
	if(tos==-1)
	{
		printf("\nUnder flow");
	}
	else
	{
		printf("\nNumber deleted ");
		tos--;
	}
	return size;
}
