#include<stdio.h>
#include<stdlib.h>
#define m 5
typedef struct
{
	int data[m];
	int f,r;
}dqueue;
int insert(dqueue *q,int n)
{
	if(q->r==m-1)
	{
		printf("Full Queue.\n");
		return 1;
	}
	if(q->r==-1)
	{
		q->r=q->f=0;
		q->data[q->r]=n;
	}
	else
	{
		q->r+=1;
		q->data[q->r]=n;
	}
	return 0;
}
int delete(dqueue *q,int *n,int s)
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
	else if(s==0)
	{
		*n=q->data[q->f];
		q->f+=1;
	}
	else
	{
		*n=q->data[q->r];
		q->r-=1;
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
	q.r=q.f=-1;
	int n,x,y,s;
	printf("Enter %d no.:\n",m);
	for(int i=0; i<m; i++)
	{
		scanf("%d",&n);
		x=insert(&q,n);
	}
	display(q);
	do{
	printf("Enter 0. Tp Delete from FRONT End.\nEnter 1. To Delete from REAR End.\nEnter side of deletion : ");
	scanf("%d",&s);
	printf("\n");
	}while(s>1 || s<0);
	y=delete(&q,&n,s);
	printf("Remaing data is : ");
	display(q);
	printf("\n");
	return 0;
}
