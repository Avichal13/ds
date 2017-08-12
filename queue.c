// simple queue

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define max 10

void clrscr()
{
  system("@cls||clear");
}
typedef struct queue
{
  int a[max];
  int front;
  int rear;
}queue;
void createemptyqueue(queue *q)
{
  q->front=q->rear=-1;
}
int isfull(queue q)
{
  if(q.rear==max-1)
  return 1;
  else
  return 0;
}
int isempty(queue q)
{
  if(q.front==-1)
  return 1;
  else
  return 0;
}

void enqueue(queue *q,int e)
{
  if((isempty(*q)))
  {
    q->front=q->rear=0;
  }
  else
  q->rear+=1;
  q->a[q->rear]=e;
}
int dequeue(queue *q)
{
  if(q->front==q->rear)
  q->front=q->rear=-1;
  else
  q->front+=1;
}
void traverse(queue q)
{
  int i;
  if(!isempty(q))
  for(i=q.front;i<=q.rear;i++)
  printf("%d ",q.a[i]);
  printf("\n");
}
int main()
{
    queue q;
    createemptyqueue(&q);
    while(1)
    {
      clrscr();
      printf("1.enqueue in Queue\n");
      printf("2.dequeue from Queue\n");
      printf("3.isempty Queue\n");
      printf("4.isfull Queue\n");
      printf("5.traverse Queue\n");
      printf("6.exit\n");
      int x,a;
      printf("enter your choice :\n");
      scanf("%d",&x);
      switch(x)
      {
        case 1:
        printf("enter the number \n");
        scanf("%d",&a);
        if(isfull(q))
        printf("overflow");
        else
        enqueue(&q,a);
        break;

        case 2:
        if(isempty(q))
        printf("underflow");
        else
        dequeue(&q);
        break;

        case 3:
        if(isempty(q))
        printf("Queue is empty");
        else
        printf("Queue is not empty");
        break;

        case 4:
        if(isfull(q))
        printf("Queue is ful");
        else
        printf("Queue is not full");
        break;

        case 5:
        traverse(q);
        break;

        case 6:
        return 0;

      }
      printf("\n\nenter a key to continue\n" );
      getch();
    }
}
