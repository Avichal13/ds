//INFIX TO PREFIX CONVERTER

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 10

typedef struct stack
{
  char a[N];
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
char pop(stack *s)
{
  char e;
  e=s->a[s->top];
  s->top-=1;
  return e;
}
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

void reverse(char *c)
{
  int i,l;
  l=strlen(c);
  strrev(c);
  for(i=0;i<l;i++)
  {
    if(c[i]==')')
    c[i]='(';
    else if(c[i]=='(')
    c[i]=')';
  }
}

void infix_postfix(char *infix,char*postfix)
{
  int i,j,l;
  char x;
  stack s;
  createemptystack(&s);
  l=strlen(infix);
  for(i=0,j=0;i<l;i++)
    {
        if(isalnum(infix[i]))
            postfix[j++]=infix[i];
        else if(infix[i] == '(')
            push(&s,infix[i]);
        else if(infix[i] == ')')
        {
            while((x = pop(&s)) != '(')
                postfix[j++]=x;
        }
        else
        {
            while(priority(s.a[s.top]) >= priority(infix[i]))
                postfix[j++]=pop(&s);
            push(&s,infix[i]);
        }

    }
    while(s.top != -1)
    {
        postfix[j++]=pop(&s);

    }
}
int main()
{
  char c[100],x;
  printf("enter the expression\n");
  scanf("%[^\n]",&c);
  char postfix[100];
  reverse(c);
  infix_postfix(c,postfix);
  strrev(postfix);
  puts(postfix);

}
