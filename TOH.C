// TOWER OF HANNOI

void move(int c1,int c2,int c3,int n)
{
  if(n==1)
  {
	printf("%d to %d\t",c1,c3);
  }
  else
  {
	move(c1,c3,c2,n-1);
	printf("%d to %d\t",c1,c3);
	move(c2,c1,c3,n-1);
  }
}
void main()
{
	int n;
	clrscr();
	printf("Enter the number of disk : ");
	scanf("%d",&n);
	move(1,2,3,n);
	getch();
}
