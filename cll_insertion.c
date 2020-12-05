#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create(struct node ** h)
{
    struct node * cur,* ptr;
    for (int i = 0; i < 5; i++)
    {
        cur = (struct node *)malloc(sizeof( struct node));
        cur->data=rand()%101;
        cur->next=NULL;

        if(*h==NULL)
        {
            *h=cur;
            ptr=cur;
            cur->next=*h;
        }

        else
        {
            cur->next=*h;
            ptr->next=cur;
            ptr=cur;

        }
        
    }

}

void display(struct node *h)
{
    struct node * ptr;
    ptr = h;
    do 
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=h);
}
void insert(struct node **h, int pos, int num)
{
    
    struct node * cur,* ptr;
    
        cur = (struct node *)malloc(sizeof( struct node));
        cur->data=num;
        cur->next=NULL;

        if(*h==NULL)
        {
           *h=cur;
           cur->next=cur;
        }
        else if(pos==0)
        {
            for(ptr=*h;ptr->next!=*h;ptr=ptr->next){}
            cur ->next=*h;
            ptr->next=cur;
            *h=cur;
        }

        else
        {
            ptr=*h;
            int i=1;
            while(i<pos)
            {
                ptr=ptr->next;
                i++;
            }
            cur->next=ptr->next;
            ptr->next=cur;
            ptr=cur;

        }

}
 
int main()
{
    struct node * head =NULL;
    
    create(&head);
    display(head);
    printf("\n");
    insert(&head,6,4);
    display(head);
}