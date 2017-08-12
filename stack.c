#include<stdio.h>

typedef struct stack
{
  int a[10];
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
}
void traverse(stack *s)
{
  int i;
  for(i=0;i<s->top;i++)
  printf("%d ",s->a[i]);
  printf("\n");
}
int main()
{
    stack s;
    createemptystack(&s);
    traverse(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    push(&s,50);
    push(&s,60);
traverse(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    traverse(&s);
}
