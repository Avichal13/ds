//INFIX TO POSTFIX CONVERTER

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define N 300

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

    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
        else if(x == '^')
            return 3;
        else
        return 0;
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
  //  postfix[j]='\0';
}

int main()
{int t,i;
scanf("%d",&t);
fflush(stdin);
for(i=0;i<t;i++)
{
  char c[400];
  scanf(" %[^\n]",&c);
  char postfix[400];
  infix_postfix(c,postfix);
  puts(postfix);
}

}
