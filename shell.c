#include<stdio.h>

int shellsort(int x[], int n)
{
  int key,i,j,gap;
  for ( gap = n/2; gap > 0; gap /= 2)
  {
    for (i = gap; i < n; i += 1)
    {
      key = x[i];
      for (j = i-gap; j >= 0; j -= gap)
      {
        if(x[j]>key)
        x[j+gap] = x[j];
        else
        break;
      }
      x[j+gap] = key;
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
  shellsort(arr,n);
  for(i=0;i<n;i++)
  printf("%d\n",arr[i] );
  return 0;
}
