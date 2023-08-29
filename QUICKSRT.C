void display(int a[])
{ int i;

  for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
}

int split(int a[],int low,int high)
{
	int key=a[low];
	int p=low+1;
	int q=high;
	int t;
	while(p<=q)
	{
		while(p<=high && key>=a[p])
		{
			p++;
		}
		while(q>low && key<=a[q])
		{
			q--;
		}
		if(p<q)
		{
			t=a[p];
			a[p]=a[q];
			a[q]=t;


		}
	}
	if(q!=low)
	{
	t=a[low];
	a[low]=a[q];
	a']t [q]=t;
	}
	return q;
}

void sort(int a[],int low,int high)
{
	int q;
	if(low<high)
	{
		q=split(a,low,high);
		//printf("%d\n",q);
		sort(a,low,q-1);
		sort(a,q+1,high);
	}
}
void main()
{
	int a[5]={4,3,6,2,1};
	int i;
	clrscr();
       /*	printf("ENTER THE DATA\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}*/
	sort(a,0,4);
	getch();
}t|