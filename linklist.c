#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void clrscr()
{
  system("@cls||clear");
}
struct node{
  int info;
  struct node* next;
};
typedef struct node node;
void createemptylist(node *head)
{
  head->next=NULL;
}
void traverse(node *head)
{
  node *p;
  p=head;
  while(p!=NULL)
  {
    printf("%d ",p->info);
    p=p->next;
  }
  printf("\n");
}
node* search(node *head,int e)
{
  node *p;
  p=head;
  while(p!=NULL)
  {
    if(p->info==e)
    {
      printf("KEY FOUND!!\n");
      break;
    }
    p=p->next;
  }
  return p;
}
void insert_begin(node **head,int e)
{
  node *p,*newnode;
  //p=*head;
  newnode=(node *)malloc(sizeof(node));
  newnode->info=e;
  newnode->next=*head;
  *head=newnode;
}
void insert_end(node **head,int e)
{
  node *p,*newnode;
  p=*head;
  while(p->next!=NULL)
  {
    p=p->next;
  }
  newnode=(node *)malloc(sizeof(node));
  newnode->info=e;
  newnode->next=NULL;
  p->next=newnode;
}
void insert_afternode(node **head,int e,int x)
{
  node *p;
  p=*head;
  p=search(p,x);
  if(p==NULL)
  {
    printf("NODE NOT FOUND!!\n");
  }
  else
  {
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->info=e;
    newnode->next=p->next;
    p->next=newnode;
  }
}
void insert_beforenode(node **head,int e,int x)
{
  node *p;
  p=*head;
  if(*head==NULL)
  printf("list is empty\n");
  else if(p->info==x)
  {
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->info=e;
    newnode->next=*head;
    *head=newnode;
  }
  else if(p->next!=NULL)
  while(p->next->info!=x)
  {
    p=p->next;
  }
  if(p==NULL)
  {
    printf("NODE NOT FOUND!!\n");
  }
  else
  {
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->info=e;
    newnode->next=p->next;
    p->next=newnode;
  }
}
void delete_start(node ** head)
{
  if(*head==NULL)
  printf("List id empty\n" );
  else{
    node *p;
    p=*head;
    *head=p->next;
    free(p);
  }
}
void delete_end(node ** head)
{
  if(*head==NULL)
  printf("List id empty\n" );
  //to check it have atleast two node
  else if((*head)->next==NULL)
  {
    free(*head);
    *head==NULL;
  }
  else{
    node *p;
    p=*head;
    while((p->next)->next!=NULL)
    p=p->next;
    free(p->next);
    p->next=NULL;
  }
}
void delete_afternode(node **head,int x)
{
  node *p;
  p=*head;
  p=search(p,x);
  if(p==NULL)
  {
    printf("NODE NOT FOUND!!\n");
  }
  else if(p->next==NULL)
  printf("NO NODE AFTER THIS NODE\n" );
  else
  {
    node *x;
    x=p->next;
    p->next=x->next;
    free(x);
  }
}
void delete_beforenode(node **head,int x)
{
  node *p;
  p=*head;
  if(*head==NULL)
  printf("list is empty\n");
  else if(p->info==x)
  printf("NO NODE BEFORE THIS NODE\n");
  else if(p->next!=NULL)
  {
    if(p->next->info==x)
    {
      *head=p->next;
      free(p);
    }
    else
    {
      while(p->next->next!=NULL)
      {
        if(p->next->next->info==x)
        break;
        p=p->next;
      }

      if(p->next->next==NULL)
      {
        printf("NODE NOT FOUND!!\n");
      }
      else
      {
        node *x;
        x=p->next;
        p->next=x->next;
        free(x);
      }
    }
  }
}

void delete_all(node ** head)
{
  if(*head==NULL)
  printf("List id empty\n" );
  else{
    node *p;
    p=*head;
    while(*head!=NULL)
    {
      p=*head;
      *head=p->next;
      free(p);
    }
  }
}
void reverse(node ** head)
{
  if(*head==NULL)
  printf("List id empty\n" );
  else if((*head)->next==NULL)
  {
    printf("ONLY ONE NODE\n");
  }
  else{
    node *p,*x,*y;
    //  p=*head;
    //  y=p->next;
    x=*head;
    p=NULL;
    while(x!=NULL)
    {
      y=x;
      x=x->next;
      y->next=p;
      p=y;
    }
    *head=p;
  }
}

int main()
{
  node *head=NULL;
  //  head=NULL;
  //head=(node *)malloc(sizeof(node));
  //createemptylist(head);
  //printf("%p",head->next);
  while(1)
  {
    clrscr();
    printf("1.insert in beginning\n");
    printf("2.insert at end\n");
    printf("3.insert after a node\n");
    printf("4.insert before a node\n");
    printf("5.search for a key\n");
    printf("6.traverse\n");
    printf("7.delete from beginning\n");
    printf("8.delete from end\n");
    printf("9.delete after a node\n");
    printf("10.delete before a node\n");
    printf("11.delete all node\n");
    printf("12.sort the list\n");
    printf("13.reverse the list\n");
    printf("14.exit\n");
    int x,a,b;
    printf("enter your choice :\n");
    scanf("%d",&x);
    switch(x)
    {
      case 1:
      printf("enter the number \n");
      scanf("%d",&a);
      insert_begin(&head,a);
      break;

      case 2:
      printf("enter the number \n");
      scanf("%d",&a);
      insert_end(&head,a);
      break;

      case 3:
      printf("enter the number \n");
      scanf("%d",&a);
      printf("enter the node \n");
      scanf("%d",&b);
      insert_afternode(&head,a,b);
      break;

      case 4:
      printf("enter the number \n");
      scanf("%d",&a);
      printf("enter the node \n");
      scanf("%d",&b);
      insert_beforenode(&head,a,b);
      break;

      case 5:

      printf("enter the key to search \n");
      scanf("%d",&a);
      node *temp;
      temp=search(head,a);
      if(temp==NULL)
      printf("KEY NOT FOUND!!\n");
      break;

      case 6:
      traverse(head);
      break;

      case 7:
      delete_start(&head);
      break;

      case 8:
      delete_end(&head);
      break;

      case 9:
      printf("enter the number \n");
      scanf("%d",&a);
      delete_afternode(&head,a);
      break;

      case 10:
      printf("enter the number \n");
      scanf("%d",&a);
      delete_beforenode(&head,a);
      break;

      case 11:
      delete_all(&head);
      break;
      case 13:
      reverse(&head);
      break;
      case 14:
      return 0;

    }

    printf("\n\n enter a key to continue\n" );
    getch();
  }
}
