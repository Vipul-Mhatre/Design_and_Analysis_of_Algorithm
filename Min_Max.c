#include<stdio.h>
#include<conio.h>

int max,min,a[100];

void minmax(int i, int j)
{
  int max1,min1,mid;

  if(i==j)
  {
    max=min=a[i];
  }
  else
  {
     if(i==j-1)
     {
       if(a[i] < a[j])
       {
	 max=a[j];
	 min=a[i];
       }
       else
       {
	 max=a[i];
	 min=a[j];
       }
     }
     else
     {
	mid=(i+j)/2;
	minmax(i,mid);
	max1=max; min1=min;
	minmax(mid+1,j);
	if(max<max1)
	max=max1;
	if(min>min1)
	min=min1;
     }
  }
}

void main()
{
  int i,n;
  clrscr();

  printf("\nEnter how many elements: ");
  scanf("%d",&n);
  printf("\nEnter the elements: ");
  for(i=1;i<=n;i++)
  scanf("%d",&a[i]);
  max=a[0];
  min=a[0];
  minmax(1,n);
  printf("\nMinimun is: %d",min);
  printf("\nMaximum is: %d",max);
  getch();
}