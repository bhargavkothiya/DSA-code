//binary tree traversal

struct node
{
  int info();
  struct node *next;
  struct node *pre;
};
typedef struct node node;
node *start=NULL;

node *creatnode()
{
    node *t;
    t=(node *)malloc(sizeof(node));
    printf("Enter the data : ");
    scanf("%d",&t->info);
    t->next=NULL;
    t->prev=NULL;
    return t;
}
void pushbeg()
{
	node t;
	t=creatnode();


}


void main()
{
  int choice,c;
  clrscr();
  printf("Welcome to Binary tree traversel programme' \n'Press enter to continue'");
  getch();
  clrscr();
  do
  {
  printf("1.PUSH BEGENING\n");
  printf("2.PUSH END\n");
  printf("3.PUSH SPECIAL\n");
  printf("4.POP BEGENING\n");
  printf("5.POP END\n");
  printf("6.POP SPECIAL\n");
  printf("7.DISPLAY DATA IN PREFIX ORDER\n");
  printf("8.DISPLAY DATA IN INFIX ORDER\n");
  printf("9.DISPLAY DATA IN POSTFIX ORDER\n");
  printf("10.DISPLAY ENTERED DATA Y\n");
  printf("0.EXIT\n");
  printf("\n\nEnter your choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
	case 1: pushbeg();
		break;
	case 2: pushend();
		break;
	case 3: pushspl();
		break;
	case 4: popbeg();
		break;
	case 5: popend();
		break;
	case 6: popspl();
		break;
	case 7: prefix();
		break;
	case 8: infix();
		break;
	case 9: postfix();
		break;
	case 10:display();
		break;
	case 0: printf(" Thank you ");
		break;
	default:printf(" Invalid choice,try again  ");
		break;
		}
		getch();
		clrscr();

  }while(choice!=0);

  getch();
}
