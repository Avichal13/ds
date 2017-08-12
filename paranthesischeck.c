//PARENTHESIS CHECKING

#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct stack
{
  char a[10];
  int top;
}stack;
void createemptystack(stack *s)
{
  s->top=-1;
}
void push(stack *s,char e)
{
  s->top+=1;
  s->a[s->top]=e;
}
void pop(stack *s)
{
  s->top-=1;
}
int isempty(stack s)
{
  if(s.top==-1)
  return 1;
  else
  return 0;
}

int main()
{
  char c[100];
  printf("enter the expression\n");
  scanf("%[^\n]",&c);
  stack s;
  createemptystack(&s);
  int l,i;
  l=strlen(c);
  for(i=0;i<l;i++)
  {
    if(c[i]=='(')
    push(&s,'(');
    else if(c[i]==')')
    {
      if(isempty(s))
      {
        printf("opening ( is missing\n");
        return 0;
      }
      else
      pop(&s);
    }
  }
  if(isempty(s))
  printf("expression is correct\n");
  else
  printf("closing ) is missing\n");
  return 0;
}
