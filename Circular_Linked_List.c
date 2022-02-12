/* Program of circular linked list*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *create_list(struct node *last);
void display(struct node *last);
struct node *addtoempty(struct node *last,int data);
struct node *addatbeg(struct node *last,int data);
struct node *addatend(struct node *last,int data);
struct node *addafter(struct node *last,int data,int item);
struct node *addbefore(struct node *last,int data,int item);
struct node *reverse(struct node *last);
struct node *del(struct node *last,int data);

main( )
{
	int choice,data,item;
	struct node	*last=NULL;
	
	while(1)
	{
		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Add to empty list\n");
		printf("4.Add at beginning\n");
		printf("5.Add at end\n");
		printf("6.Add after \n");
		printf("7.Add before\n");
		printf("8.Delete\n");
		printf("9.Reverse\n");
		printf("10.Quit\n");
		
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			last=create_list(last);
			break;
		 case 2:
			display(last);
			break;
		 case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=addtoempty(last,data);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=addatbeg(last,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=addatend(last,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			last=addafter(last,data,item);
			break;
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which you want to insert : ");
		    scanf("%d",&item);
			last=addbefore(last,data,item);
			break;
		case 8:
		 	printf("Enter the element to be deleted : \n");
			scanf("%d",&data);
			last = del(last,data);
			break;
		 case 9 :
			last=reverse(last);
			break;
		 case 10 :
			exit(1);
			break;
		 default :
			printf("Wrong choice\n");
			break;	
			}
		}
	return 0;
}
struct node *create_list(struct node *last)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	last=NULL;
	if(n==0)
		return last;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	last=addtoempty(last,data);
			
	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		last=addatend(last,data);	
	}
	return last;
}
struct node *addtoempty(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	last=tmp;
	last->link=last;
	return last;
}
struct node *addatbeg(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	return last;
}/*End of addatbeg( )*/

struct node *addatend(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	last=tmp;
	return last;
}/*End of addatend( )*/

struct node *addafter(struct node *last,int data,int item)
{
	struct node *tmp,*p;
	p=last->link;
	do
	{
		if(p->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			if(p==last)
				last=tmp;
			return last;
		}
		p=p->link;
	}while(p!=last->link);
	printf("%d not present in the list\n",item);
	return last;
}
struct node*addbefore(struct node *last,int data,int item)
{
	struct node *tmp,*q;
	if(last==NULL)
	{
		printf("List is empty\n");
		return last;
	}
	if(last->link->info==item)
	{
		tmp=(struct node*)malloc(sizeof(struct node));
		tmp->info=data;
		tmp->link=last->link;
		last->link=tmp;
		return last;
    }
    q=last->link;
   do
    {
    	if(q->link->info==item)
    	{
    		tmp=(struct node*)malloc(sizeof(struct node));
        	tmp->info=data;
        	tmp->link=q->link;
            q->link=tmp;
	        return last;
		}
		q=q->link;
	}
	while(q->link!=last->link);
	
    printf("Item %d not found \n",item);
	return last;
}

struct node *del(struct node *last,int data)
{
	struct node *tmp,*p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return last;
	}
	/*Deletion of only node*/
	if(last->link==last && last->info==data)  
	{
		tmp=last;
		last=NULL;
		free(tmp);
		return last;
	}
	/*Deletion of first node*/
	if(last->link->info==data)    
	{
		tmp=last->link;
		last->link=tmp->link;
		free(tmp);
		return last;
	}
	/*Deletion in between*/
	p=last->link;
	while(p->link!=last)
	{
		if(p->link->info==data)     
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return last;
		}
		p=p->link;
	}
	/*Deletion of last node*/
	if(last->info==data)    
	{
		tmp=last;
		p->link=last->link;
		last=p;
		free(tmp);
		return last;
	}
	printf("Element %d not found\n",data);
	return last;
}/*End of del( )*/
struct node *reverse(struct node *last)
{
	struct node *prev,*ptr,*next;
	prev=NULL;
	ptr=last;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	last=prev;
	display1(last);
}
void display1(struct node *last)
{
	struct node *p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("List is :\n");
	p=last;
	printf("%d ",p->info);
	p=last->link;
	do
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=last->link&&p!=last);
	printf("\n");
}

void display(struct node *last)
{
	struct node *p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=last->link;
	do 
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=last->link);
	printf("\n");
}/*End of display( )*/

