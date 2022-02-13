/* STACK USING ARRAY */
#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int stack_arr[MAX];
int top=-1;
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
	if(isFull())
	{
		printf("Stack Overflow\n");
		return;
	}
	top=top+1;
	stack_arr[top]=item;
}
int pop()
{
	int item ;
	if(isEmpty())
	{
		printf("Stack Underflow\n");
        return;
	}
	item=stack_arr[top];
	top=top-1;
	return item;
}
int isFull()
{
	if(top==MAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isEmpty()
{
	if(top==-1)
	    return 1;
	else
	    return 0;
}
int peek()
{
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return stack_arr[top];
}
void display()
{
	int i;
	if(isEmpty())
	{
		printf("Stack is empty\n");
		return;
	}
	printf("Stack elements are :\n");
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stack_arr[i]);
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

