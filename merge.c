
#include<stdlib.h>
#include<stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = 1;  // why??
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
     while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left+(right-left)/2;

        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);

        merge(arr, left, mid, right);
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
  mergesort(arr,0,n-1);
  for(i=0;i<n;i++)
  printf("%d\n",arr[i] );
  return 0;
}
