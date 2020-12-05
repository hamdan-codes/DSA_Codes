#include<stdio.h>
#include<stdlib.h>

struct node
{
	int cof;
	int exp;
	struct node *next;
};
struct node *head=NULL;

void create(struct node **);
void display(struct node *);
void join(struct node **,struct node *);
void simply(struct node *);
int s=3;

int main()
{
	struct node *h1=NULL,*h2=NULL,*p;
	create(&h1);
	create(&h2);
	printf("Initial LL\n");
	display(h1);
	display(h2);
	for(p=h2;p!=NULL;p=p->next)
	{
		p->cof*=-1;
	}
	join(&h1,h2);
	printf("After joining\n");
	display(h1);
	simply(h1);
	printf("After simply\n");
	display(h1);
}
void create(struct node **h)
{	
	int i;
	struct node *cur,*ptr;
	
	for(i=0;i<s;i++)
	{
		cur=(struct node *)malloc(sizeof(struct node));
		printf("Enter data\n");
		scanf("%d%d",&cur->cof,&cur->exp);
		cur->next=NULL;
		
		if(*h==NULL)
		{
			*h=cur;
			ptr=cur;
		}
		else
		{
			ptr->next=cur;
			ptr=cur;
		}
	}
}

void display(struct node *h)
{	
	struct node *ptr=h; 
	if(h==NULL)
	{
		printf("List is empty\n");
		return;
	}

	for(;ptr!=NULL;ptr=ptr->next)
	{
		printf("%d, %d\t",ptr->cof,ptr->exp);
	}
	printf("\n\n");
}

void join(struct node **h1,struct node *h2)
{
	struct node *p;
	if(*h1==NULL)
	{
		*h1=h2;
		return;
	}
	for(p=*h1;p->next!=NULL;p=p->next);
	p->next=h2;
}

void simply(struct node *h1)
{
	struct node *p1,*p2,*prv;
	for(p1=h1;p1!=NULL;p1=p1->next)
	{
		prv=p1;
		p2=p1->next;
		while(p2!=NULL)
		{
			if(p1->exp==p2->exp)
			{
				p1->cof+=p2->cof;
				prv->next=p2->next;
				free(p2);
				p2=prv;
			}
			prv=p2;
			p2=p2->next;
		}
	}
}
