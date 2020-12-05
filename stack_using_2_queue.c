#include<stdio.h>
#include<stdlib.h>

#define max 10

typedef struct
{
    int data[max];
    int f;
    int r;
}Queue;

Queue Q[2];
int Aq=0;            //Active Queue

int insert(Queue *Q,int v)
{
	if(Q->r==max-1)
    {
	    printf("Queue is full");
        return 1;
    }
    if(Q->r==-1)
    {
        Q->f=Q->r=0;
    }
    else
    {
        Q->r++;
    }
    Q->data[Q->r]=v;
    return 0;         
}

int delete(Queue *Q,int *v)
{
	if(Q->f==-1)
    {
    	printf("Queue is empty so cannot delete.");
        return 1;
    }
    if(Q->f==Q->r)
    {
        *v=Q->data[Q->f];
        Q->f=-1;
        Q->r=-1;
    } 
    else                               
    {
        *v=Q->data[Q->f];                 //For a sufficiently large array we use this sort of deletion
        Q->f++;
    }
    return 0;  
}

int isEmpty(Queue Q)
{
    if(Q.f==-1)
    	return 1;
    else
        return 0;
}

int push(int v)
{
  return insert(&Q[Aq],v);
}

int pop(int *m)
{
    if(isEmpty(Q[Aq]))
    	return 1;
    while(1)
    {
        delete(&Q[Aq],m);
        if(isEmpty(Q[Aq]))
        	break;
        insert(&Q[(Aq+1)%2],*m);
    }
    Aq=(Aq+1)%2;  
    return 0; 
}

int main()
{
	Q[0].f=Q[0].r=Q[1].f=Q[1].r=-1;
    int m;
    int p=push(10);
    int b=pop(&m);
    printf("%d%d",p,b);
    return 0;
}
