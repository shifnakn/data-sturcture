#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node
{
int data;
struct node *next;
};
struct node *sp=(struct node*)0;
void push(int item)
{
struct node *t;
t=(struct node *)malloc(sizeof(struct node));
t->data=item;
t->next=sp;
sp=t;
return;
}
int pop(int *status)
{
struct node*t;
int item;
if(sp==(struct node*)0)
{
*status=0;
printf("empty stack");
}
else
{
item=sp->data;
t=sp;
sp=sp->next;
free(t);
*status=1;
return item;
}
}
int search(int item)
{
struct node*t=sp;
int count=0;
while(t!=(struct node*)0)
{
++count;
if(t->data==item)
return count;
t=t->next;
}
return 0;
}
int main()
{
int item,opt,ans,status;
do
{
printf("1.push\n");
printf("2.pop\n");
printf("3.search\n");
printf("4.exit\n");
printf("option:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("data:");
scanf("%d",&item);
push(item);
printf("\n inserted %d \n",item);
break;
case 2:item=pop(&status);
if(status!=0)
printf("delete item is %d \n",item);
break;
case 3: printf("searching");
scanf("%d",&item);
ans=search(item);
if(ans==0)
printf("item not found\n");
else
printf("found at %d node \n",ans);
break;
case 4:exit(0);
}
}
while(1);
}
