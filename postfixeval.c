#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 10

typedef struct stack
{
  float a[N];
  int top;
}stack;
void createemptystack(stack *s)
{
  s->top=-1;
}
void push(stack *s,float e)
{
  s->top+=1;
  s->a[s->top]=e;
}
float pop(stack *s)
{
  float e;
  e=s->a[s->top];
  s->top-=1;
  return e;
}
float postfixevaluation(char *c)
{
  int l,i;
  float r,x,y;
  stack s;
  createemptystack(&s);
  l=strlen(c);
  for(i=0;i<l;i++)
  {
    if(isalnum(c[i]))
    {
      push(&s,c[i]-48);
    }
    else
    {
      x=pop(&s);
      y=pop(&s);
      switch(c[i])
      {
        case '+':
        r=y+x;
        break;
        case '-':
        r=y-x;
        break;
        case '*':
        r=y*x;
        break;
        case '/':
        r=y/x;
        break;
      }
      push(&s,r);
    }
  }
  r=pop(&s);
  return r;
}
int main()
{
  char c[100];
  float result;
  printf("enter the expression\n");
  scanf("%[^\n]",&c);
  result=postfixevaluation(c);
  printf("evaluation reuslt : %f\n",result);
}
