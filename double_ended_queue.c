#include<stdio.h>
#include<stdlib.h>
#define m 5

typedef struct{
    int data[m];
    int f;
    int r;
}dqueue;


int insert(dqueue *q,int v,int side)
{
    if(q->f==0 && q->r==m-1)
    {
        printf("Full Queue\n");
        return 1;
    }
    if(q->r==-1)            //Empty queue
    {
        q->f=q->r=0;
        q->data[q->r]=v;
        return 0;
    }
    if(side==1)           //Inserting at end
    {
        if(q->r!=m-1)
        {
            q->r++;
            q->data[q->r]=v;
        }
        else
        {
            for(int i=q->f;i<=q->r;i++)
            {
                q->data[i-1]=q->data[i];
            }
                q->data[q->r]=v;
                q->f--;
        }
           return 0; 
    }
    if(side==0)
    {
        if(q->f!=0)
        {
            q->f--;
            q->data[q->f]=v;
        }
        else
        {
           for(int j=q->r;j>=q->f;j--)
            {
                q->data[j+1]=q->data[j];
            }
            q->data[q->f]=v;
            q->r++;
        }
       return 0; 
    }
        
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
    q.f=q.r=-1; //Initially

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
		printf("\n");
	}
	printf("\nRemaining Data in Queue : ");
	display(q);
	printf("\n");
	return 0;
}
