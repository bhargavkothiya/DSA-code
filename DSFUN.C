//Operation on array

int add();
int remove();
void update();
void display();
int i;
void main()
{
	int choice,*a,size;
	clrscr();
	printf("Enter your array size : ");
	scanf("%d",&size);
	a=(int *)malloc(sizeof(int)*size);
	printf("Enter value of array \n");
	for(i=0; i<size; i++)
	{
	 printf("a[%d] = ",i);
	 scanf("%d",&a[i]);
	}
	clrscr();
	do
	{       clrscr();
		printf("\nYour latest array : ");
		for(i=0; i<size; i++)
		{
		 printf(" %d ",a[i]);
		}
		printf("\n 1 : Add element: ");
		printf("\n 2 : Remove element: ");
		printf("\n 3 : Update element: ");
		printf("\n 4 : Display: ");
		printf("\n 0 : Exit : ");
		printf("\n\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:add(a,size);
			 break;
		case 2:remove(a,size);
			 break;
		case 3:update(a,size);
			 break;
		case 4:display(a,size);
			 break;
		case 0:printf("Thank you %c",2);
			 break;
		default:printf("Invalid selection,Try again.");
			break;
		}
		getch();
	} while(choice!=0);
	getch();
}

int add(int a[],int size)
{
	int x,pos,temp;
	printf("Enter the position number : ");
	scanf("%d",&pos);
	if(pos<=size && pos>0)
	{
		printf("Enter the number you want to add : ");
		scanf("%d",&x);
		size++;
		for(i=size; i>=pos; i--)
		{
		  a[i]=a[i-1];
		}
		a[pos-1]=x;

	 printf("\%d added sucessfully",x);

	} else{printf("Enter position value within 1 to %d",size);}
	return size;
}
int remove(int a[],int size)
{
	int i,x,count,pos;
	printf("Enter the number you want to delete : ");
	scanf("%d",&x);
	for(i=0; i<size; i++)
	{
	   if(a[i]==x)
		{
		 count++;
		 pos=i;
		}
	}
	  if(count>0)
	  {
	   printf("Number found and deleted");
	   for(i=pos; i<size; i++)
	   {
	    a[i]=a[i+1];
	   }
	   size--;
	  }
	  else{printf("Number not Found");}
	  return size;
}

void update(int a[],int size)
{

	int i,x,count,pos;
	printf("Enter the number you want to update : ");
	scanf("%d",&x);
	for(i=0; i<size; i++)
	{
	   if(a[i]==x)
		{
		 count++;
		 pos=i;
		}
	}
	if(count>0)
	  {
	   printf("Number found,Enter the number you want to replace : ");
	   scanf("%d",&a[pos]);
	   printf("Number updated sucessfully");

	  }
	  else{printf("Number not Found");}

}
void display(int a[],int size)
{
	int i;
	printf("Your Array : ");
	for(i=0; i<size+1; i++)
	{
	 printf(" %d ",a[i]);
	}

}