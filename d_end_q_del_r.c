#include<stdio.h>
#include<stdlib.h>
#define m 5
typedef struct
{
	int data[m];
	int f,r;
}dqueue;
int insert(dqueue *q, int n, int s)
{
	if(q->r==m-1 && q->f==0)
	{
		printf("Full Queue.\n");
		return 1;
	}
	if(q->r==-1)
	{
		q->f=q->r=0;
		q->data[q->r]=n;
	}
	if(s==0)
	{
		if(q->f==0)
		{
			for(int i=q->r+1; i>0; i--)
			{
				q->data[i]=q->data[i-1];
			}
			q->data[q->f]=n;
		}
		else
		{
			q->f--;
			q->data[q->f]=n;
		}
	}
	if(s==1)
	{
		if(q->r==m-1)
		{
			for(int i=q->f; i<=q->r; i++)
			{
				q->data[i-1]=q->data[i];
			}
			q->data[q->r]=n;
		}
		else
		{
			q->r++;
			q->data[q->r]=n;
		}
	}
	return 0;
}
int delete(dqueue *q,int *n)
{
	if(q->f==-1)
	{
		printf("Empty Queue.\n");
		return 1;
	}
	if(q->f==q->r)
	{
		*n=q->data[q->f];
		q->f=q->r=-1;
	}
	else
	{
		*n=q->data[q->f];
		q->f++;
	}
	return 0;
}
void display(dqueue q)
{
	for(int i=q.f; i<=q.r; i++)
	{
		printf("%d ",q.data[i]);
	}
	printf("\n");
}
int main()
{
	dqueue q;
	q.f=q.r=-1;
	int s,x,y,n;
	for(int i=0; i<m-3; i++)
	{
		printf("Enter 0. To Insert from FRONT.\nEnter 1. To Insert from REAR.\nEnter side of insertion : ");
		scanf("%d",&s);
		printf("Enter Data : ");
		scanf("%d",&n);
		x=insert(&q,n,s);
		printf("\n");
	}
	y=delete(&q,&n);
	printf("\nOne Element Deleted Successfully.\n\n");
	for(int i=0; i<m-3; i++)
	{
		printf("Enter 0. To Insert from FRONT.\nEnter 1. To Insert from REAR.\nEnter side of deletion : ");
		scanf("%d",&s);
		printf("Enter Data : ");
		scanf("%d",&n);
		x=insert(&q,n,s);
	}
	printf("\nRemaining Data in Queue : ");
	display(q);
	printf("\n");
	return 0;
}
