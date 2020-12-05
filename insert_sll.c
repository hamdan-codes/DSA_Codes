#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};

void create(struct node **);
void display(struct node *);
void insert(struct node **h,int v, int pos);

int main()
{
	struct node *head=NULL;
	create(&head);
	display(head);
	int a,p;
	printf("Enter the data to insert: ");
	scanf("%d",&a);
	printf("Enter the index of node to insert %d:",a);
	scanf("%d",&p);
	insert(&head,a,p);
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
	printf("Displaying the Link List:\n");
	for(cur=h;cur!=NULL;cur=cur->next)
		printf("%d ",cur->data);
	printf("\n\n");
}
	
void insert(struct node **h,int v, int pos)
{
	struct node *cur, *ptr;
	cur=(struct node *)malloc(sizeof(struct node));
	cur->data= v;
	cur->next = NULL;
	if(*h== NULL)
	{
		*h=cur;
	}
	else if(pos==0)
	{
		cur->next=*h;
		*h=cur;
	}
	else
	{
		ptr=*h;
		int i=1;
		while(i<pos&&ptr->next!=NULL)
		{
			ptr=ptr->next;
			i++;
		}
		cur->next=ptr->next;
		ptr->next=cur;
	}
}
