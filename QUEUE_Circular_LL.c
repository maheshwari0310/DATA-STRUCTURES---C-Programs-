/* C Program to implement queue using circular linked list*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct node
{
    int info;
    struct node *link;
}*rear=NULL;
void insert(int item);
int del();
void display();
int isEmpty();
int peek();
int main()
{
        int choice,item,i;
        while(1)
        {
            printf("1.Insert\n");
    		printf("2.Delete\n");
    		printf("3.Display the element at the front\n");
    		printf("4.Display all the elements of the queue\n");
      		printf("5.Quit\n");
            printf("\nEnter your choice : ");
            scanf("%d",&choice);
            switch(choice)
                {
                 case 1:
                 	 for(i=0;i<MAX;i++)
				    {
                        printf("\nEnter the element to be inserted : \n");
                        scanf("%d",&item);
                        insert(item);
                    }
                        break;
                 case 2:
                        printf("\nDeleted Item : %d\n",del());
                        break;
                 case 3:
                        printf("\nFront item  is %d\n",peek());
                        break;
                 case 4:
                        display();
                        break;
                 case 5:
                        exit(1);
                 default:
                        printf("\nWrong choice\n");
                }
        }
}
void insert(int item)
{
        struct node *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=item;
        if(tmp==NULL)
        {
                printf("\nMemory not available\n");
                return;
        }

        if(isEmpty())
        {
                rear=tmp;
                tmp->link=rear;
        }
        else
        {
                tmp->link=rear->link;
                rear->link=tmp;
                rear=tmp;
        }
}
del()
{
        int item;
        struct node *tmp;
        if( isEmpty() )
        {
                printf("\nQueue underflow\n");
                exit(1);
        }
        if(rear->link==rear)
        {
                tmp=rear;
                rear=NULL;
        }
        else
        {
                tmp=rear->link;
                rear->link=rear->link->link;
        }
        item=tmp->info;
        free(tmp);
        return item;
}
int peek()
{
        if( isEmpty() )
        {
                printf("\nQueue underflow\n");
                exit(1);
        }
        return rear->link->info;
}
int isEmpty()
{
        if( rear == NULL )
                return 1;
        else
                return 0;
}
void display()
{
        struct node *p;
        if(isEmpty())
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue is :\n");
        p=rear->link;
        do
        {
                printf("%d ",p->info);
                p=p->link;
        }while(p!=rear->link);
        printf("\n");
}
