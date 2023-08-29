#include<stdio.h>

void DFS();
int q[50],vertex;
int f=-1,r=-1;
int a[][4]={ {0,1,1,0},{1,0,0,0},{1,0,0,1},{0,0,1,0} };
status[4]={0};

void creatgraph()
{
	int **a,i,j,n;
	char ch;
	printf("Enter the number of vertex : ");
	scanf("%d",&n);
	*a=(int *)malloc(sizeof(int)*n);
	{
		for(i=0; i<n; i++)
		{
		  a[i]=(int *)malloc(sizeof(int)*n);
		  for(j=0; j<n; j++)
		  {

		    printf("Is there edge between V%d to V%d ? Y/N : ",i+1,j+1);
		    fflush(stdin);
		    scanf("%c",&ch);
		    if(ch=='y')
		      {
		       a[i][j]=1;
		      }
		    else
		      {
		       a[i][j]=0;
		      }
		  }
	       }
	}
}

void push(int num)
{
	if(f==-1)
	{
	  r=0;
	}
	f++;
	q[f]=num;
}

int pop()
{
	int d;
	if(r==-1)
	{
	 return -1;
	}
	else
	{
	 d=q[r];
	 if(f==r)
	 {
	  f=r=-1;
	 }
	 else
	 {
	  r++;
	 }
	 return d;
	}
}
void DFS(int n)
{
	int i;
	push(n);
	status[n]=1;
	while(r!=-1)
	{
		n=pop();
		printf("V%d\t",n);
		status[n]=2;
		for(i=0; i<4; i++)
		 {
			if(a[n][i]==1 && status[i]==0)
			{
				push(i);
				status[i]=1;
			}
		 }

	}

}

void main()
{
	clrscr();

	//creatgraph();
	printf("Enter the starting Vertex : ");
	scanf("%d",&vertex);
	DFS(vertex);
	getch();
}