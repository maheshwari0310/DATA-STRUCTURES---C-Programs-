#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue_arr[MAX];
int rear=-1;
int front=-1;
void insert(int item);
int del();
int peek();
int isFull();
int isEmpty();
void display();
int main()
{
	int choice,item,i;
	while(1)
	{
		printf("1 . Insert\n");
		printf("2 . Delete\n");
		printf("3 . Display the element at the top\n");
		printf("4 . Display all the elements of the queue\n");
		printf("5 . Quit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				for(i=0;i<MAX;i++)
			   {
				printf("Input the element for adding in queue\n");
				scanf("%d",&item);
				insert(item);
			   }
				break;
			case 2 :
				item=del();
				printf("Deleted item is : %d\n",item);
				break;
			case 3 :
				printf("Item at the front is : %d \n",peek());
				break;
			case 4 :
				display();
				break;
			case 5 : 
			    exit(1);
			default :
				printf("Wrong choice\n");	
		}
	}
	return 0;
}
void insert(int item)
{
	if(isFull())
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1)
	front=0;
	rear=rear+1;
	queue_arr[rear]=item;
}
int del()
{
	int item;
	if(isEmpty())
	{
		printf("Queue Underflow\n");
		return;
	}
	item=queue_arr[front];
	front=front+1;
	return item;
}
int isFull()
{
	if(rear==MAX-1)
	return 1;
	else
	return 0;
}
int isEmpty()
{
	if(front==-1 || front ==rear+1)
	return 1;
	else
	return 0;
}
int peek()
{
	if(isEmpty())
	{
		printf("Queue Underflow\n");
		return;
	}
	return queue_arr[front];
}
void display()
{
	int i;
	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue is :\n\n");
	for(i=front;i<=rear;i++)
	printf("%d ",queue_arr[i]);
	printf("\n");
}

