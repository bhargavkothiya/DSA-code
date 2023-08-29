#include<stdio.h>

struct node
{
	int info;
	struct node *lp,*rp;
};
typedef struct node node;

node *creatnode(int root)
{
	node *t;
	t=(node *)malloc(sizeof(node));
	t->info=root;
	t->lp=NULL;
	t->rp=NULL;
	return t;
}

void main()
{
	node *t[10];
	int x,n=0,i,count=0;
	clrscr();
	while(1)
	 {
	  printf("Enter data : ");
	  scanf("%d",&x);
	  if(x==-1){break;}
	  t[n]=creatnode(x);
	  count++;
	 }
	 printf("data Entered : ");
	 for(i=0; i<count; i++)
	 {printf("%d ",t[i]->info);}
	getch();
}