#include<stdio.h>
void main()
{
	int **a,i,j,n;
	char ch;
	clrscr();
	printf("Enter the number of edges : ");
	scanf("%d",&n);
	*a=(int *)malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
	{
	 a[i]=(int *)malloc(sizeof(int)*n);
	 for(j=0; j<n; j++)
	 {
	  printf("Have edge between V%d to V%d ? Y/N: ",i+1,j+1);
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
	printf("\n-------OUTPUT------ \n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
		 printf("%d\t",a[i][j]);
		}
		printf("\n");
	}

       getch();
}