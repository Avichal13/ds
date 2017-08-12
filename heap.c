#include <stdio.h>

void swap(int *a,int *b)
{
  int t;
  t=*a;
  *a=*b;
  *b=t;
}
void heapify(int arr[], int n, int i)
{
  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if (l < n && arr[l] > arr[largest])
  largest = l;

  if (r < n && arr[r] > arr[largest])
  largest = r;

  if (largest != i)
  {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapsort(int arr[], int n)
{
  for (int i = (n-1)/2; i >= 0; i--)
  heapify(arr, n, i);

  for (int i=n-1; i>=0; i--)
  {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
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
  heapsort(arr,n);
  for(i=0;i<n;i++)
  printf("%d\n",arr[i] );
  return 0;
}
