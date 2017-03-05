#include<stdio.h>
#include<conio.h>
void expression();
void expression1();
void add();
void append();
void display(struct node*);
int coef2[4],coef1[4],deg2[4],deg1[4],co,deg;
struct node
{
int degree;
int coeff;
int temp;
struct node*link;
}*A,*B,*C,*lp;
void expression(int deg1,int coef1)
{
struct node*x;
x=(struct node*)malloc(sizeof(struct node));
x->degree=deg1;
x->coeff=coef1;
x->link=NULL;
if(A==NULL)
{
A=x;
lp=A;
}
else
{
lp->link=x;
lp=x;
}
}
void expression1(int deg2,int coef2)
{
struct node*x;
x=(struct node*)malloc(sizeof(struct node));
x->degree=deg2;
x->coeff=coef2;
x->link=NULL;
if(B==NULL)
{
B=x;
lp=B;
}
else
{
lp->link=x;
lp=x;
}
}
void add()
{
struct node*p;
struct node*q;
struct node*temp;
p=(struct node*)malloc(sizeof(struct node));
q=(struct node*)malloc(sizeof(struct node));
temp=(struct node*)malloc(sizeof(struct node));
p=A;
q=B;
while(p!=NULL&&q!=NULL)
{
if(p->degree==q->degree)
{
temp=p->coeff+q->coeff;
append(p->degree,temp);
p=p->link;q=q->link;
  }

else if(p->degree>q->degree)
{
append(p->degree,p->coeff);
p=p->link;
  }
  else
{
append(q->degree,q->coeff);
q=q->link;
  }
  }
  while(p!=NULL)
  {
  append(p->degree,p->coeff);
p=p->link;
}
while(q!=NULL)
  {
  append(q->degree,q->coeff);
q=q->link;
}
}
void append(int deg,int co)
{
struct node*f;
f=(struct node*)malloc(sizeof(struct node));
f->degree=deg;
f->coeff=co;
f->link=NULL;
if(C==NULL)
{
lp=C=f;
}
else
{
lp->link=f;
lp=f;
}
}
void display(struct node*C)
{
if(C!=NULL)
{
printf("C=");
while(C!=NULL)
{
printf("%dx^%d+",C->coeff,C->degree);
C=C->link;
}
}
else
{
printf("empty");
}
}

void main()
{
int i,n;
clrscr();

printf("enter 1 pol degree followed by coeff");
for(i=0;i<4;i++)
{
scanf("%d%d",&deg1[i],&coef1[i]);
expression(deg1[i],coef1[i]);
}
printf("enter 2 pol deg followed by coeff");
for(i=0;i<4;i++)
{
scanf("%d%d",&deg2[i],&coef2[i]);
expression1(deg2[i],coef2[i]);
}
add();
display(C);
getch();
}


