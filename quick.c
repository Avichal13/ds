#include<stdio.h>

int quicksort(int x[], int lb,int ub)
{
  int key;
  key=partition(x,lb,ub);
  if(ub>lb)
  {
    quicksort(x,lb,key-1);
    quicksort(x,d+1,ub);
  }
  return 0;
}

int partition(int x[], int lb,int ub)
{
  int down,up,temp;
  down=lb;
  up=ub;
  pivot = x[lb];

  while (1)
  {
    while(pivot>x[down]&&down<ub)
    {
      down++;
    }
    while(pivot<x[up])
    {
      up--;
    }
    if(down<up)
    {
      temp=x[up];
      x[up]=x[down];
      x[down]=temp;
    }
    else
    {
      temp=x[up];
      x[up]=pivot;
      pivot=temp;
      return up;
    }
  }
  return 0;
}
int main()
{
  int n,i;
  printf("enter the number of the elements\n" );
  scanf("%d",&n);
  int arr[n];
  printf("enter the elements\n" );
  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
  printf("sorted array\n" );
  quicksort(arr,0,n-1);
  for(i=0;i<n;i++)
  printf("%d\n",arr[i] );
  return 0;
}
