#include<stdio.h>
struct Tree
{
	int info;
	int ht;
	struct Tree *left,*right;
};
typedef struct Tree Tree;

Tree* rotatRight(Tree* t)
{
	Tree *x;

	x = t->left;
	t->left = NULL;
	x->right = t;

	t->ht = height(t);
	x->ht = height(x);

	return x;
}

Tree* rotateLeft(Tree* t)
{
	Tree *x;

	x = t->right;
	t->right = x->left;
	x->left = t;

	t->ht = height(t);
	x->ht = height(x);

	return x;
}

int BF(Tree *t)
{
	int lh,rh;

	if(t == NULL)
		return 0;
	if(t->left == NULL)
		lh = 0;
	else
		lh = 1+t->left->ht;
	if(t->right== NULL)
		rh = 0;
	else
		rh = 1+t->right->ht;

	return (lh-rh);
}

Tree* RL(Tree *t)
{
	t->right = rotatRight(t->right);
	t = rotateLeft(t);
	return t;
}


Tree* RR(Tree *t)
{
	t = rotateLeft(t);
	return t;
}


Tree* LL(Tree *t)
{
	t = rotatRight(t);
	return t;
}


Tree* LR(Tree *t)
{
	t->left = rotateLeft(t->left);
	t = rotatRight(t);
	return t;
}

int height(Tree *t)
{
	int lh,rh;

	if(t==NULL)
		return 0;
	if(t->left == NULL)
		lh=0;
	else
		lh = 1 + t->left->ht;
	if(t->right == NULL)
		rh = 0;
	else
		rh = 1 + t -> right->ht;
	if(lh>rh)
		return lh;
	else
		return rh;
}


Tree * insert(Tree *t,int key)
{

	if(t==NULL)
	{
		t = (Tree *)malloc(sizeof(Tree));

		t->info = key;
		t->left = NULL;
		t->right = NULL;
	}
	else if(t->info < key)
		{
			t->right = insert(t->right,key);

			if(BF(t) == -2)
			{
				if(key>t->right->info)
					t = RR(t);
				else
					t = RL(t);
			}
		}
	else
	{
		t->left = insert(t->left,key);

		if(BF(t)==2)
		{
			if(key<t->left->info)
				t = LL(t);
			else
				t = LR(t);
		}
	}

	t->ht = height(t);
	return t;
}
void preorder(Tree *t)
{
	if(t!=NULL)
	{
		printf("%d\t%d\n",t->info,BF(t));
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(Tree *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d\t%d\n",t->info,BF(t));
		inorder(t->right);
	}
}
void postorder(Tree *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%d\t%d\n",t->info,BF(t));
	}
}
void main()
{
	Tree *root = NULL;

	clrscr();

	root=insert(root,300);
	root=insert(root,200);
	root=insert(root,100);
	root=insert(root,500);


	printf("\n");
	preorder(root);


	getch();
}