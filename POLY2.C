#include<stdio.h>
typedef struct node
{
	int co;
	int pow;
	struct node *next;
}node;
void display(node *t)  // t = start1
{
	while(t->next!=NULL)
	{
		printf("%d*x^%d + ",t->co,t->pow);
		t = t -> next;
	}
	printf("%d = 0\n",t->co);
}
void evaluate(node *t)  // t = start1
{
	int sum = 0;
	int x,m = 1,i;

	printf("Enter the value of X : ");
	scanf("%d",&x);

	while(t != NULL)
	{
		m = 1;
		for(i=1;i<=t->pow;i++)
		{
			m = m * x;
		}
		sum = sum + t->co * m;
		t = t -> next;
	}
	printf("\n\n Value : %d\n",sum);
}

node * createNode()
{
	node *t;

	t = (node *)malloc(sizeof(node));

	printf("Enter co : ");
	scanf("%d",&t->co);

	printf("Enter power : ");
	scanf("%d",&t->pow);

	t -> next = NULL;

	return t;
}
node * createPoly()
{
	node *t,*z,*start = NULL;
	char ch;

	do
	{
		t = createNode();
		if(start == NULL)
		{
			start = t;
		}
		else
		{
			z = start;
			while(z -> next != NULL)
			{
				z = z -> next;
			}
			z -> next = t;
		}

		printf("Do you want to add more node ? (Y/N) ");
		fflush(stdin);
		scanf("%c",&ch);

	}while(ch=='Y' || ch=='y');

	return start;
}
void main()
{
	node *start1,*start2,*start3;

	clrscr();

	printf("Enter first Polynomial : \n");
	start1 = createPoly();

	display(start1);
	evaluate(start1);

	getch();
}