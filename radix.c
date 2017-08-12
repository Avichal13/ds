#include<stdio.h>
int radixsort(int arr[], int n)
{
  int bucket[10][n],buck[n];
  int i,j,k,l,num,div,large,passes;

  div=1;
  num=0;
  large=arr[0];

  for(i=0 ; i<n ; i++)
  {
    if(arr[i] > large)
    {
      large = arr[i];
    }

    while(large > 0)
    {
      num++;
      large = large/10;
    }

    for(passes=0 ; passes<num ; passes++)
    {
      for(k=0 ; k<10 ; k++)
      {
        buck[k] = 0;
      }
      for(i=0 ; i<n  ;i++)
      {
        l = ((arr[i]/div)%10);
        bucket[l][buck[l]] = arr[i];
        buck[l]++;
      }

      i=0;
      for(k=0 ; k<10 ; k++)
      {
        for(j=0 ; j<buck[k] ; j++)
        {
          arr[i] = bucket[k][j];
          i++;
        }
      }
      div*=10;
    }
  }
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
  radixsort(arr,n);
  for(i=0;i<n;i++)
  printf("%d\n",arr[i] );
  return 0;
}
