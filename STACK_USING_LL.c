/* STACK USING LINKED LIST */
#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct node{
	int info;
	struct node *link;
}*top=NULL;
void push(int item);
int pop();
int peek();
int isFULL();
int isEmpty();
void display();
void reverse();
void insert(int data);
int main()
{
	int choice,item,i;
	while(1)
	{
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display top element \n");
		printf("4.Display stack\n");
	    printf("5.Reversed stack\n");
		printf("6.Quit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				    for(i=0;i<MAX;i++)
				    {
				    printf("Enter the item to be pushed \n");
				    scanf("%d",&item);
				    push(item);
				    }
				    break;
			case 2:
				    item=pop();
				    printf("The popped element is : %d\n",item);
				    break;
			case 3: 
			        printf("The item at the top is : %d\n",peek());
			        break;
			case 4:
				    display();
				    break;
			case 5:
				    reverse();
				    break;
			case 6:
			        exit(1);
			        break;
			default:
				printf("Invalid choice\n");		
		}
	}
	return 0;
}
void push(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Stack Overflow\n");
		return;
	}
	tmp->info=item;
	tmp->link=top;
	top=tmp;
}
int pop()
{
	struct node *tmp;
	
	int item ;
	if(isEmpty())
	{
		printf("Stack Underflow\n");
        return;
	}
	tmp=top;
	item=tmp->info;
	top=top->link;
	free(tmp);
	return item;
}
int isEmpty()
{
	if(top==NULL)
	    return 1;
	else
	    return 0;
}
int peek()
{
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		return 1;
	}
	return top->info;
}
void display()
{
	struct node *ptr;
	ptr=top;
	
	if(isEmpty())
	{
		printf("Stack is empty\n");
		return;
	}
	printf("Stack elements are :\n");
	while(ptr!=NULL)
	{
	    printf("%d\n",ptr->info);
	    ptr=ptr->link;
    }
	printf("\n");
}
void reverse()
{
	int data;
	if(isEmpty())
    	return;
    data=pop();
    reverse();
    insert(data);
}
void insert(int data)
{
	int temp;
	if(isEmpty())
	{
		push(data);
		return;
	}
	temp=pop();
	insert(data);
	push(temp);
}

