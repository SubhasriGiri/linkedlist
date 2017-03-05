#include<stdio.h>
#include<conio.h>
struct node
{
int data;
struct node * next;
}*head,*lp,*temp,*temp1,*ele;
struct node* display(struct node  *,int);
void dis();
void insert(int) ;
void main()
{
int i,a[5],n;
clrscr();
printf("enter the array");

for(i=0;i<5;i++)
{
scanf("%d",&a[i]);
//struct node*temp;
insert(a[i]);
}
dis();
printf("enter n");
scanf("%d",&n );
ele=display(head,n);
printf("\n%d",ele->data);
getch();
}
struct node * display(struct node *head,int n)
{
struct node * p1=head;
struct node *p2=head;
while (p1!=NULL&&n>0)
{
p1=p1->next;
n--;
}
while(p1!=NULL)
{
p1=p1->next;
p2=p2->next;
}
//printf("ele %d",p2->data) ;
return p2;
}
void dis()
{
if(head==NULL)
{
printf("");
}
else
{
struct node *t=head;
//t=(struct node*)malloc(sizeof(struct node));
while(t->next!=NULL)
{

printf("\t%d",t->data);
t=t->next;
}
}
}
void insert(int b)
{
temp=(struct node*)malloc(sizeof(struct node));
temp->data=b;
temp->next=NULL;
if(head==NULL)
{
head=temp;
lp=head;
}
else
{
lp->next=temp;
lp=temp;

}
}