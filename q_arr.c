#include<stdio.h>
#include<stdlib.h>
#define m 5
typedef struct
{
	int data[m];
	int f,r;
}queue;
int insert(queue *q,int n)
{
	if(q->r==m-1)
	{
		printf("Full Queue.\n");
		return 1;
	}
	if(q->r==-1)
	{
		q->f=q->r=0;
		q->data[q->r]=n;
	}
	else
	{
		q->r+=1;
		q->data[q->r]=n;
	}
	return 0;
}
int delete(queue *q,int *n)
{
/*       //O(1)
	if(q->f==-1)
	{
		printf("Empty Queue\n");
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
		q->f+=1;
	}
	return 0;
*/
         //O(n)
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
		for(int i=0;i<q->r; i++)
		{
			q->data[i]=q->data[i+1];
		}
		q->r-=1;
	}
	return 0;
}
int main()
{
	queue q;
	q.r=q.f=-1;
	int n,x,y;
	
	for(int i=0; i<m; i++)
	{
		scanf("%d",&n);
		x=insert(&q,n);
	}
	/*    //O(n)
	for(int i=0; i<m-3; i++)
	{
		y=delete(&q,&n);
		printf("%d ",n);
	}
	printf("\n");
	for(int i=0; i<m-3; i++)
	{
		scanf("%d",&n);
		x=insert(&q,n);
	}
	*/
	for(int i=0; i<m; i++)
	{
		y=delete(&q,&n);
		printf("%d ",n);
	}
	printf("\n");
}
