/* QUEUE USING LINKED LIST */
#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct node{
	int info;
	struct node *link;
}*front=NULL,*rear=NULL;
void insert(int item);
void insert_more(int item);
int del();
int peek();
int isEmpty();
void display();
int main()
{
	int choice,item,i;
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display the element at the front\n");
		printf("4.Display all the elements of the queue\n");
		printf("5.Insert more\n");
		printf("6.Quit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				    for(i=0;i<MAX;i++)
				    {
				    printf("Enter the item to be inserted \n");
				    scanf("%d",&item);
				    insert(item);
				    }
				    break;
			case 2:
				    item=del();
				    printf("The deleted element is : %d\n",item);
				    break;
			case 3: 
			        printf("The item at the top is : %d\n",peek());
			        break;
			case 4:
				    display();
				    break;
			case 5:
				    printf("Enter the item to be inserted \n");
				    scanf("%d",&item);
				    insert_more(item);
			case 6:
				    exit(1);
			        break;
			default:
				printf("Invalid choice\n");		
		}
	}
	return 0;
}
void insert(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Memory not available\n");
		return;
	}
	tmp->info=item;
	tmp->link=NULL;
	if(front==NULL)
	    front=tmp;
	else
	    rear->link=tmp;
	rear=tmp;
}
void insert_more(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Memory not available\n");
		return;
	}
	tmp->info=item;
	tmp->link=NULL;
	if(front==NULL)
	    front=tmp;
	else
	    rear->link=tmp;
	rear=tmp;
	
	display();
}
int del()
{
	struct node *tmp;
	
	int item ;
	if(isEmpty())
	{
		printf("Queue Underflow\n");
        return;
	}
	tmp=front;
	item=tmp->info;
	front=front->link;
	free(tmp);
	return item;
}
int isEmpty()
{
	if(front==NULL)
	    return 1;
	else
	    return 0;
}
int peek()
{
	if(isEmpty())
	{
		printf("Queue Underflow\n");
		return 1;
	}
	return front->info;
}
void display()
{
	struct node *ptr;
	ptr=front;
	
	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements are :\n");
	while(ptr!=NULL)
	{
	    printf("%d ",ptr->info);
	    ptr=ptr->link;
    }
	printf("\n");
}

