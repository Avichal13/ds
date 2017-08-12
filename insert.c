#include<stdio.h>

int insertsort(int x[],int n)
{
  int i,j,key;
  for(i=1;i<n;i++)
  {
    key=x[i];
    //for(j=i-1;j>=0;j--)
    for(j=i-1;x[j]>key && j>=0;j--)
    {
    //  if(x[j]>key)
      x[j+1]=x[j];
    //  else
    //  break;
    }
    x[j+1]=key;
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
  insertsort(arr,n);
  for(i=0;i<n;i++)
  printf("%d\n",arr[i] );
  return 0;
}
