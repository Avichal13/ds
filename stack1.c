//TWO STACK IN ONE ARRAY

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define N 10
void clrscr()
{
    system("@cls||clear");
}

typedef struct stack
{
  int a[N];
  int top1;
  int top2;
}stack;
void createemptystack(stack *s)
{
  s->top1=-1;
  s->top2=N;
}
void push1(stack *s,int e)
{
  s->top1=s->top1+1;
  s->a[s->top1]=e;
}
void push2(stack *s,int e)
{
  s->top2=s->top2-1;
  s->a[s->top2]=e;
}
int pop1(stack *s)
{
  int e;
  e=s->a[s->top1];
  s->top1-=1;
}
int pop2(stack *s)
{
  int e;
  e=s->a[s->top2];
  s->top2+=1;
}
void traverse1(stack *s,int top)
{
  int i;
  for(i=0;i<=top;i++)
  printf("%d ",s->a[i]);
  printf("\n");
}
void traverse2(stack *s,int top)
{
  int i;
  for(i=N-1;i>=top;i--)
  printf("%d ",s->a[i]);
  printf("\n");
}
int isfull(stack *s)
{
  if(s->top2 - s->top1 ==1)
  return 1;
  else
  return 0;
}
int isempty(int n)
{
  if(n==-1||n==N)
  return 1;
  else
  return 0;
}
int main()
{
stack s;
createemptystack(&s);
while(1)
{
  clrscr();
  printf("1.push in stack1\n");
  printf("2.pop from stack1\n");
  printf("3.push in stack2\n");
  printf("4.pop from stack2\n");
  printf("5.isempty stack1\n");
  printf("6.isempty stack2\n");
  printf("7.isfull stack1\n");
  printf("8.isfull stack2\n");
  printf("9.traverse stack1\n");
  printf("10.traverse stack2\n");
  printf("11.exit\n");
  int x,a;
  printf("enter your choice :\n");
  scanf("%d",&x);
  switch(x)
  {
    case 1:
    printf("enter the number \n");
    scanf("%d",&a);
    if(isfull(&s))
    printf("overflow");
    else
    push1(&s,a);
    break;

    case 2:
    if(isempty(s.top1))
    printf("underflow");
    else
    pop1(&s);
    break;

    case 3:
    printf("enter the number \n");
    scanf("%d",&a);
    if(isfull(&s))
    printf("overflow");
    else
    push2(&s,a);
    break;

    case 4:
    if(isempty(s.top2))
    printf("underflow");
    else
    pop2(&s);
    break;

    case 5:
    if(isempty(s.top1))
    printf("Stack1 is empty");
    else
    printf("Stack1 is not empty");
    break;

    case 6:
    if(isempty(s.top2))
    printf("Stack2 is empty");
    else
    printf("Stack2 is not empty");
    break;

    case 7:
    case 8:
    if(isfull(&s))
    printf("Stack is ful");
    else
    printf("Stack is not ful");
    break;

    case 9:
    traverse1(&s,s.top1);
    break;

    case 10:
    traverse2(&s,s.top2);
    break;

    case 11:
    return 0;

  }

printf("\n\n enter a key to continue\n" );
getch();
}
}
