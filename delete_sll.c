#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};

void create(struct node **);
void display(struct node *);
void delete(struct node **h,int p);

int main()
{
	struct node *head=NULL;
	create(&head);
	display(head);
	int pos;
	printf("Enter the position to delete: ");
	scanf("%d",&pos);
	delete(&head,pos);
	display(head);
	return 0;
}

void create(struct node **h)
{
	int n;
	printf("Enter the no. of elements in the link list: ");
	scanf("%d",&n);
	//printf("Enter the %d elements in the Link List: ",n);
	struct node *cur,*ptr;
	for(int i=0;i<n;i++)
	{
		cur=(struct node *)malloc(sizeof(struct node *));
		//scanf("%d",&cur->data);
		cur->data=random()%101;
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
	struct node *cur;
	printf("Display the Link List:\n");
	for(cur=h;cur!=NULL;cur=cur->next)
		printf("%d ",cur->data);
	printf("\n\n");
}

void delete(struct node **h,int p)
{
	struct node *ptr,*prv;
	if(*h==NULL)
	{
		printf("EMPTY\n");
	}
	else
	{
		ptr=*h;
		int i=1;
		while(i<p&&ptr!=NULL)
		{
			prv=ptr;
			ptr=ptr->next;
			i++;
		}
		if(ptr==NULL)
		{
			printf("Node not present.\n");
		}
		else if(ptr==*h)
		{
			*h=ptr->next;
			free(ptr);
		}
		else
		{
			prv->next = ptr->next;
			free(ptr);
		}
	}
}
