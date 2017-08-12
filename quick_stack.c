#include<stdio.h>
typedef struct stack
{
  int a[50];
  int top;
}stack;
void createemptystack(stack *s)
{
  s->top=-1;
}
void push(stack *s,int e)
{
  s->top+=1;
  s->a[s->top]=e;
}
int pop(stack *s)
{
  int e;
  e=s->a[s->top];
  s->top-=1;
  return e;
}
/*void traverse(stack *s)
{
  int i;
  for(i=0;i<s->top;i++)
  printf("%d ",s->a[i]);
  printf("\n");
}*/
int isempty(stack s)
{
  if(s.top==-1)
  return 1;
  else
  return 0;
}
int partition(int x[], int lb,int ub)
{
  int down,up,temp;
  down=lb;
  up=ub;
  int pivot = x[lb];

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
void quicksort_stack (int arr[], int l, int h)
{
  stack s;
  createemptystack(&s);
  push(&s,l);
  push(&s,h);
  while (!isempty(s))
  {
    h = pop(&s);
    l = pop(&s);
    int p = partition( arr, l, h );
    if ( p-1 > l )
    {
      push(&s,l);
      push(&s,p-1);
    }
    if ( p+1 < h )
    {
      push(&s,p + 1);
      push(&s,h);
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
  quicksort_stack(arr,0,n-1);
  for(i=0;i<n;i++)
  printf("%d\n",arr[i] );
  return 0;
}
