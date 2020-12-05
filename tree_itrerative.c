#include<stdio.h>
#include<stdlib.h>
#define limit 10
struct node 
{
	int data;
	struct node *l,*rt;
};
typedef struct
{
	struct node *address[limit];
	int top;
}stk;
int push(stk *s,struct node *n)
{
	if(s->top==limit-1)
	{
		printf("Full Stack.\n");
		return 1;
	}
	s->top++;
	s->address[s->top]=n;
	return 0;
}
int pop(stk *s,struct node **n)
{
	if(s->top==-1)
	{
		printf("Empty Stack.\n");
		return 1;
	}
	*n=s->address[s->top];
	s->top--;
	return 0;
}
struct node* create(int n)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=n;
	ptr->l=ptr->rt=NULL;
	return ptr;
}
void MinMax(struct node *r)
{	
	if(r!=NULL)
	{
		stk s;
		s.top=-1;
		int x,y,m=r->data,le=r->data;
		x=push(&s,r);
		struct node *ptr;
		while(s.top!=-1)
		{
			y=pop(&s,&ptr);
			if(ptr->data > m)
				m=ptr->data;
			if(ptr->data < le)
				le=ptr->data;
			if(ptr->l!=NULL)
				x=push(&s,ptr->l);
			if(ptr->rt!=NULL)
				x=push(&s,ptr->rt);
		}
		printf("Maximum Value of Tree : %d\nMinimum Value of Tree : %d\n\n",m,le);
	}
}
void inorder(struct node *r)
{
	if(r!=NULL)
	{
		stk s;
		s.top=-1;
		int x,y;
		struct node *ptr=r;
		while(ptr!=NULL)
		{
			x=push(&s,ptr);
			ptr=ptr->l;
		}
		while(s.top!=-1)
		{
			y=pop(&s,&ptr);
			printf("%d ",ptr->data);
			if(ptr->rt!=NULL)
			{
				ptr=ptr->rt;
				x=push(&s,ptr);
				while(ptr->l!=NULL)
				{
					x=push(&s,ptr->l);
					ptr=ptr->l;
				}
			}
		}
	}
}
void preorder(struct node *r)
{
	if(r!=NULL)
	{
		stk s;
		s.top=-1;
		int x,y;
		struct node *ptr=r;
		x=push(&s,ptr);
		while(s.top!=-1)
		{
			y=pop(&s,&ptr);
			printf("%d ",ptr->data);
			if(ptr->rt!=NULL)
				x=push(&s,ptr->rt);
			if(ptr->l!=NULL)
				x=push(&s,ptr->l);
		}
	}
}
void postorder(struct node *r)
{
	if(r!=NULL)
	{
		stk s;
		s.top=-1;
		int x,y;
		struct node *ptr=r,*m,*n;
		while(ptr!=NULL)
		{
			if(ptr->rt!=NULL)
				x=push(&s,ptr->rt);
			push(&s,ptr);
			ptr=ptr->l;
		}
		while(s.top!=-1)
		{
			y=pop(&s,&m);
			if(m->rt==NULL)
				printf("%d ",m->data);
			else if(s.top==-1)
				printf("%d ",m->data);
			else
			{
				y=pop(&s,&n);
				if(m->rt==n)
				{
					x=push(&s,m);
					ptr=n;
					while(ptr!=NULL)
					{
						if(ptr->rt!=NULL)
							x=push(&s,ptr->rt);
						x=push(&s,ptr);
						ptr=ptr->l;
					}
				}
				else
				{
					printf("%d ",m->data);
					x=push(&s,n);
				}
			}
		}
	}
}
int main()
{
	struct node *root=NULL;
	root=create(1);
	root->l=create(2);
	root->rt=create(3);
	root->l->l=create(4);
	root->l->l->rt=create(5);
	root->rt->l=create(6);
	root->rt->rt=create(7);
	root->rt->l->l=create(8);
	root->rt->l->l->rt=create(9);
	MinMax(root);
	printf("Inorder of the Tree : ");
	inorder(root);
	printf("\n");
	printf("Preorder of the Tree : ");
	preorder(root);
	printf("\n");
	printf("Postorder of the Tree : ");
	postorder(root);
	printf("\n");
}
