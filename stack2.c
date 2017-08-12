//stack of stack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define row 2

void clrscr()
{
  system("@cls||clear");
}
typedef struct stack
{
  int a[10];
  int var;
}stack;
typedef struct stack2
{
  stack x[row];
  int top;
}stack2;
void createemptystack(stack2 *s)
{
s->top=0;
}
void push(stack2 *s,int e)
{
  s->x[s->top].var+=1;
  if(s->x[s->top].var==10)
  {
    s->x[s->top].var-=1;
    s->top+=1;
    s->x[s->top].var+=1;
  }
  s->x[s->top].a[s->x[s->top].var]=e;
}
int pop(stack2 *s)
{
  //int e;
  //e=s->x[s->top].a[s->x[s->top].var];
  s->x[s->top].var-=1;
  if(s->x[s->top].var==-1)
  {
    s->top-=1;
  }

}
void traverse(stack2 *s)
{
  int i,j;
  for(i=0;i<=s->top;i++)
  {
    for(j=0;j<=s->x[i].var;j++)
    {
      printf("%d ",s->x[i].a[j]);
    }
    printf("\n");
  }
  printf("\n");
}
int isfull(stack2 s)
{
  if(s.x[row-1].var==9)
  return 1;
  else
  return 0;
}
int isempty(stack2 s)
{
  if(s.x[0].var==-1)
  return 1;
  else
  return 0;
}

int main()
{
  stack2 s;
  int i;
  createemptystack(&s);
  for(i=0;i<row;i++)
  {
    s.x[i].var=-1;
  }
  while(1)
  {
    clrscr();
    printf("1.push in stack\n");
    printf("2.pop from stack\n");
    printf("3.isempty stack\n");
    printf("4.isfull stack\n");
    printf("5.traverse stack\n");
    printf("6.exit\n");
    int x,a;
    printf("enter your choice :\n");
    scanf("%d",&x);
    switch(x)
    {
      case 1:
      printf("enter the number \n");
      scanf("%d",&a);
      if(isfull(s))
      printf("overflow");
      else
      push(&s,a);
      break;

      case 2:
      if(isempty(s))
      printf("underflow");
      else
      pop(&s);
      break;

      case 3:
      if(isempty(s))
      printf("Stack1 is empty");
      else
      printf("Stack1 is not empty");
      break;

      case 4:
      if(isfull(s))
      printf("Stack is ful");
      else
      printf("Stack is not full");
      break;

      case 5:
      traverse(&s);
      break;

      case 6:
      return 0;

    }
    printf("\n\nenter a key to continue\n" );
    getch();
  }
}
